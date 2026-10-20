#ifndef DEVICE_H
#define DEVICE_H

#include <string>
using namespace std;

class Device {
private:
    int deviceId;
    string deviceName;
    double price;
    int totalStock;
    int availableStock;

public:
    Device();
    Device(int id, string name, double cost, int total, int available);

    int getId();
    string getName();
    double getPrice();
    int getTotalStock();
    int getAvailableStock();

    bool borrowOne();
    bool returnOne();
    void displayInfo();
};

#endif
