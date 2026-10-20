#include <iostream>
#include <fstream>
#include <string>
#include "LabInventory.h"
using namespace std;


LabInventory::LabInventory() {
    capacity = 100;
    count = 0;
    devices = new Device[capacity];
}

LabInventory::~LabInventory() {
    delete[] devices;
}


int LabInventory::binarySearch(int targetId) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (devices[mid].getId() == targetId) {
            return mid;
        }
        if (devices[mid].getId() < targetId) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}


void LabInventory::addDevice() {
    if (count >= capacity) {
        cout << "Inventory is full!" << endl;
        return;
    }

    int id, stock;
    double price;
    string name;

    cout << "Enter Device ID: ";
    if (!(cin >> id) || id <= 0) {
        cout << "Invalid ID." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    if (binarySearch(id) != -1) {
        cout << "This ID already exists!" << endl;
        return;
    }

    cin.ignore(1000, '\n');
    cout << "Enter Device Name: ";
    getline(cin, name);
    cout << "Enter Replacement Cost: ";
    cin >> price;
    cout << "Enter Total Quantity: ";
    cin >> stock;

    if (!cin || name.empty() || price < 0 || stock <= 0) {
        cout << "Invalid device information." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // Keep the array sorted by ID so binary search works.
    int location = 0;
    while (location < count && devices[location].getId() < id) {
        location++;
    }

    for (int i = count; i > location; i--) {
        devices[i] = devices[i - 1];
    }

    devices[location] = Device(id, name, price, stock, stock);
    count++;
    cout << "Device added successfully!" << endl;
}


void LabInventory::displayDevices() {
    if (count == 0) {
        cout << "No devices in inventory." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        devices[i].displayInfo();
    }
}


void LabInventory::searchDevice() {
    int id;
    cout << "Enter ID to search: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID." << endl;
        return;
    }

    int index = binarySearch(id);
    if (index == -1) {
        cout << "Device not found." << endl;
    }
    else {
        cout << "Device found!" << endl;
        devices[index].displayInfo();
    }
}


void LabInventory::borrowDevice() {
    int id;
    cout << "Enter ID to borrow: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID." << endl;
        return;
    }

    int index = binarySearch(id);
    if (index == -1) {
        cout << "Device not found." << endl;
        return;
    }

    Device* devicePtr = &devices[index];
    if (devicePtr->borrowOne()) {
        cout << "Borrowed: " << devicePtr->getName() << endl;
    }
    else {
        cout << "Out of stock!" << endl;
    }
}


void LabInventory::returnDevice() {
    int id;
    cout << "Enter ID to return: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid ID." << endl;
        return;
    }

    int index = binarySearch(id);
    if (index == -1) {
        cout << "Device not found." << endl;
        return;
    }

    Device* devicePtr = &devices[index];
    if (devicePtr->returnOne()) {
        cout << "Returned: " << devicePtr->getName() << endl;
    }
    else {
        cout << "All units are already in inventory." << endl;
    }
}


void LabInventory::showLowStock() {
    bool found = false;
    cout << "=== LOW STOCK ALERT (2 OR FEWER AVAILABLE) ===" << endl;

    for (int i = 0; i < count; i++) {
        if (devices[i].getAvailableStock() <= 2) {
            devices[i].displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "All devices have sufficient stock." << endl;
    }
}


void LabInventory::saveToFile() {
    ofstream file("devices.txt");
    if (!file) {
        cout << "Could not open devices.txt for writing." << endl;
        return;
    }

    file << count << endl;
    for (int i = 0; i < count; i++) {
        file << devices[i].getId() << endl;
        file << devices[i].getName() << endl;
        file << devices[i].getPrice() << endl;
        file << devices[i].getTotalStock() << endl;
        file << devices[i].getAvailableStock() << endl;
    }

    file.close();
    cout << count << " devices saved to devices.txt!" << endl;
}


void LabInventory::loadFromFile() {
    ifstream file("devices.txt");
    if (!file) {
        cout << "Could not find devices.txt." << endl;
        return;
    }

    int fileCount;
    if (!(file >> fileCount) || fileCount < 0 || fileCount > capacity) {
        cout << "Invalid file format." << endl;
        return;
    }
    file.ignore(1000, '\n');

    Device* loaded = new Device[capacity];
    for (int i = 0; i < fileCount; i++) {
        int id, total, available;
        double price;
        string name;

        if (!(file >> id)) {
            cout << "Could not read device data." << endl;
            delete[] loaded;
            return;
        }
        file.ignore(1000, '\n');
        if (!getline(file, name) || !(file >> price >> total >> available) ||
            id <= 0 || name.empty() || price < 0 || total <= 0 ||
            available < 0 || available > total ||
            (i > 0 && id <= loaded[i - 1].getId())) {
            cout << "Invalid device data in file." << endl;
            delete[] loaded;
            return;
        }
        file.ignore(1000, '\n');
        loaded[i] = Device(id, name, price, total, available);
    }

    delete[] devices;
    devices = loaded;
    count = fileCount;
    cout << count << " devices loaded from devices.txt!" << endl;
}


void LabInventory::showDataSizes() {
    cout << "sizeof(int): " << sizeof(int) << " bytes" << endl;
    cout << "sizeof(double): " << sizeof(double) << " bytes" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " bytes" << endl;
    cout << "sizeof(Device): " << sizeof(Device) << " bytes" << endl;
    cout << "sizeof(Device*): " << sizeof(Device*) << " bytes" << endl;
}
