#ifndef AI_ASSISTANT_H
#define AI_ASSISTANT_H
#include <string>
#include <vector>
using namespace std;

class AIAssistant {
public:
    string ask(const string& question, const string& inventoryFile = "devices.txt") const;

private:
    struct DeviceRecord {
        int id;
        string name;
        double replacementCost;
        int totalStock;
        int availableStock;
    };

    bool readInventory(const string& filename, vector<DeviceRecord>& records, string& error) const;

    string mockResponse(const string& question, const vector<DeviceRecord>& records) const;

};

#endif
