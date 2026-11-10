#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Device {
    int id;
    string name;
    int available;
};

struct Forecast {
    string name;
    int available;
    int expectedDemand;
    int suggestedRestock;
};

bool loadDevices(const string& filename, vector<Device>& devices) {
    ifstream file(filename);
    int count;
    if (!(file >> count) || count < 0 || count > 100000) {
        return false;
    }

    for (int i = 0; i < count; ++i) {
        Device device{};
        double price;
        int total;
        if (!(file >> device.id)) return false;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!getline(file, device.name) ||
            !(file >> price >> total >> device.available) ||
            device.name.empty() || !isfinite(price) || price < 0 ||
            total < 0 || device.available < 0 || device.available > total) {
            return false;
        }
        devices.push_back(device);
    }
    return true;
}

// Least-squares linear trend for four weeks (x = 0, 1, 2, 3).
// Returns the predicion: estimated number of requests in week 5 (x = 4).
double predictNextWeek(const array<int, 4>& history) {
    constexpr double meanX = 1.5;
    constexpr double sumSquaredX = 5.0;
    double meanY = 0.0;
    for (int value : history) meanY += value;
    meanY /= history.size();

    double numerator = 0.0;
    for (size_t i = 0; i < history.size(); ++i) {
        numerator += (static_cast<double>(i) - meanX) * (history[i] - meanY);
    }
    double slope = numerator / sumSquaredX;
    return max(0.0, meanY + slope * (4.0 - meanX));
}

int main() {
    const string filename = "../Module09-Using AI to Expand Your Application/devices.txt";
    vector<Device> devices;
    if (!loadDevices(filename, devices)) {
        cerr << "Could not read inventory: " << filename << endl;
        return 1;
    }

    // Sample weekly borrowing requests for a standalone prototype.
    // These are NOT actual logs from Module 9. They are randomly generated sample data.
    srand(time(0));

    unordered_map<int, array<int, 4>> sampleHistory;

    for (const Device& device : devices) {
        array<int, 4> history;

        for (int i = 0; i < 4; i++) {
            history[i] = rand() % 11;
        }

        sampleHistory[device.id] = history;
    }

    vector<Forecast> results;
    constexpr int safetyStock = 1;
    for (const Device& device : devices) {
        auto it = sampleHistory.find(device.id);
        if (it == sampleHistory.end()) continue;
        int demand = static_cast<int>(ceil(predictNextWeek(it->second)));;
        int restock = max(0, static_cast<int>(ceil(demand + safetyStock - device.available)));
        results.push_back({device.name, device.available, demand, restock});
    }

    sort(results.begin(), results.end(), [](const Forecast& a, const Forecast& b) {
        if (a.suggestedRestock != b.suggestedRestock) {
            return a.suggestedRestock > b.suggestedRestock;
        }
        return a.expectedDemand > b.expectedDemand;
    });

    cout << "Predictive Inventory Forecast (Demo)" << endl;
    cout << "History: simulated weekly requests | Safety stock: 1" << endl;
    cout << fixed << setprecision(1);
    for (const Forecast& result : results) {
        cout << result.name << " | Available: " << result.available << " | Next-week demand: " << result.expectedDemand << " | Suggested restock: " << result.suggestedRestock << endl;
    }
    cout << endl;
    cout << "Note: estimates are statistical forecasts, not a trained AI model." << endl;
}
