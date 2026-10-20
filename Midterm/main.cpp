#include <iostream>
#include "LabInventory.h"
using namespace std;

int main() {
    LabInventory inventory;
    int choice = 0;

    while (choice != 10) {
        cout << "\n LAB INVENTORY" << endl;
        cout << "1. Add a Device" << endl;
        cout << "2. View All Devices" << endl;
        cout << "3. Search by ID (Binary Search)" << endl;
        cout << "4. Borrow a Device" << endl;
        cout << "5. Return a Device" << endl;
        cout << "6. Low Stock Alert" << endl;
        cout << "7. Save to File" << endl;
        cout << "8. Load from File" << endl;
        cout << "9. Show Data Sizes" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a number from 1-10." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            inventory.addDevice();
            break;
        case 2:
            inventory.displayDevices();
            break;
        case 3:
            inventory.searchDevice();
            break;
        case 4:
            inventory.borrowDevice();
            break;
        case 5:
            inventory.returnDevice();
            break;
        case 6:
            inventory.showLowStock();
            break;
        case 7:
            inventory.saveToFile();
            break;
        case 8:
            inventory.loadFromFile();
            break;
        case 9:
            inventory.showDataSizes();
            break;
        case 10:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid selection. Choose 1-10." << endl;
        }
    }
    return 0;
}
