#include "AIAssistant.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

namespace {
string lowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return text;
}

bool contains(const string& text, const string& fragment) {
    return text.find(fragment) != string::npos;
}

bool hasExtraContent(ifstream& file) {
    string extra;
    return static_cast<bool>(file >> extra);
}
}  

bool AIAssistant::readInventory(const string& filename, vector<DeviceRecord>& records, string& error) const {
    ifstream file(filename);
    if (!file) {
        error = "Cannot open " + filename + ". Run this program from the Module09 folder.";
        return false;
    }

    int count = 0;
    if (!(file >> count) || count < 0 || count > 100) {
        error = "Invalid device count in " + filename + ".";
        return false;
    }
    file.ignore(1000, '\n');

    int previousId = 0;
    for (int i = 0; i < count; ++i) {
        DeviceRecord device{};
        if (!(file >> device.id)) {
            error = "Invalid device ID in inventory file.";
            return false;
        }
        file.ignore(1000, '\n');

        if (!getline(file, device.name) ||
            !(file >> device.replacementCost >> device.totalStock >> device.availableStock)) {
            error = "Incomplete device record in inventory file.";
            return false;
        }
        file.ignore(1000, '\n');

        if (device.id <= previousId || device.name.empty() ||
            !isfinite(device.replacementCost) || device.replacementCost < 0 ||
            device.totalStock <= 0 || device.availableStock < 0 ||
            device.availableStock > device.totalStock) {
            error = "Invalid values in inventory file.";
            return false;
        }
        previousId = device.id;
        records.push_back(device);
    }

    if (hasExtraContent(file)) {
        error = "Unexpected extra data in inventory file.";
        return false;
    }
    return true;
}

string AIAssistant::ask(const string& question, const string& inventoryFile) const {
    vector<DeviceRecord> records;
    string error;
    if (!readInventory(inventoryFile, records, error)) {
        return "[MOCK ASSISTANT] " + error;
    }

    // TODO (future API integration):
    //   1. Convert the validated records to a small JSON payload.
    //   2. Send the user's question and payload to an AI service over HTTPS.
    //   3. Check HTTP errors and validate the model's returned text.
    //   4. Fall back to mockResponse() if the service is unavailable.
    // No API key is required or used for this Module 9 prototype.
    return "[MOCK ASSISTANT - rule-based, no live AI]\n" + mockResponse(question, records);
}

string AIAssistant::mockResponse(const string& question,const vector<DeviceRecord>& records) const {
    const string q = lowerCase(question);
    ostringstream answer;

    if (contains(q, "help") || q.empty()) {
        return "Try asking:\n"
               "  - Which devices need restocking?\n"
               "  - Summarize inventory\n"
               "  - Which device is most expensive?";
    }

    if (contains(q, "restock") || contains(q, "low") ||
        contains(q, "reorder") || contains(q, "running out") ||
        contains(q, "recommend")) {
        int lowCount = 0;
        answer << "Devices with 2 or fewer available units:\n";
        for (const auto& device : records) {
            if (device.availableStock <= 2) {
                ++lowCount;
                answer << "  - " << device.name << " (ID " << device.id << "): " << device.availableStock << " / " << device.totalStock << " available\n";
            }
        }
        if (lowCount == 0) {
            return "No devices are currently at or below the low-stock threshold (2).";
        }
        answer << "Suggestion: Review these " << lowCount
               << " device(s) for possible restocking.";
        return answer.str();
    }

    if (contains(q, "expensive") || contains(q, "highest price") ||
        contains(q, "most costly") || contains(q, "highest cost")) {
        if (records.empty()) {
            return "There are no devices in the inventory.";
        }
        const auto highest = max_element(
            records.begin(), records.end(),
            [](const DeviceRecord& a, const DeviceRecord& b) {
                return a.replacementCost < b.replacementCost;
            });
        answer << fixed << setprecision(2)
               << "Highest replacement cost: " << highest->name
               << " (ID " << highest->id << ") - $"
               << highest->replacementCost << " per unit.";
        return answer.str();
    }

    if (contains(q, "summary") || contains(q, "summarize") ||
        contains(q, "overview") || contains(q, "status") ||
        contains(q, "inventory")) {
        int totalUnits = 0;
        int availableUnits = 0;
        int lowStockDevices = 0;
        for (const auto& device : records) {
            totalUnits += device.totalStock;
            availableUnits += device.availableStock;
            if (device.availableStock <= 2) {
                ++lowStockDevices;
            }
        }
        answer << "Inventory summary:\n"
               << "  Device types: " << records.size() << "\n"
               << "  Total units: " << totalUnits << "\n"
               << "  Available units: " << availableUnits << "\n"
               << "  Low-stock device types (<= 2): " << lowStockDevices;
        return answer.str();
    }

    return "This mock supports inventory summaries, low-stock/restocking "
           "recommendations, and highest-price lookups. Type 'help' for examples. "
           "A future real AI API could interpret more flexible questions.";
}
