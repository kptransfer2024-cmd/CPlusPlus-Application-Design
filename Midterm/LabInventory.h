#ifndef LABINVENTORY_H
#define LABINVENTORY_H

#include "Device.h"

class LabInventory {
private:
    Device* devices;
    int count;
    int capacity;

    int binarySearch(int targetId);

public:
    LabInventory();
    ~LabInventory();

    void addDevice();
    void displayDevices();
    void searchDevice();
    void borrowDevice();
    void returnDevice();
    void showLowStock();
    void saveToFile();
    void loadFromFile();
    void showDataSizes();
};

#endif
