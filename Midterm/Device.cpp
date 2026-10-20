#include <iostream>
#include <iomanip>
#include "Device.h"
using namespace std;


Device::Device() {
    deviceId = 0;
    deviceName = "";
    price = 0;
    totalStock = 0;
    availableStock = 0;
}


Device::Device(int id, string name, double cost, int total, int available) {
    deviceId = id;
    deviceName = name;
    price = cost;
    totalStock = total;
    availableStock = available;
}


int Device::getId() { 
    return deviceId; 
}


string Device::getName() {
    return deviceName; 
}


double Device::getPrice() { 
    return price; 
}


int Device::getTotalStock() { 
    return totalStock; 
}


int Device::getAvailableStock() { 
    return availableStock; 
}


bool Device::borrowOne() {
    if (availableStock <= 0) {
        return false;
    }
    availableStock--;
    return true;
}


bool Device::returnOne() {
    if (availableStock >= totalStock) {
        return false;
    }
    availableStock++;
    return true;
}


void Device::displayInfo() {
    cout << fixed << setprecision(2);
    cout << "ID: " << deviceId << endl;
    cout << "Device: " << deviceName << endl;
    cout << "Replacement Cost: $" << price << endl;
    cout << "Available: " << availableStock << "/" << totalStock << endl;
    cout << "-----------------------------" << endl;
}
