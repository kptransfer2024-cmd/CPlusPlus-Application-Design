#include <iostream>
#include <sstream>
#include <string>
#include "../Midterm/LabInventory.h"
#include "../Module08-Input Validation & Protecting Data/positiveInt.h"
#include "AIAssistant.h"             
using namespace std;


int main() {
    LabInventory inventory;
    AIAssistant assistant;

    cout << "Module 9: Lab Inventory + AI Assistant (MOCK)" << endl;
    cout << "Loading the Module09 inventory snapshot..." << endl;
    inventory.loadFromFile();

    int choice = 0;
    while (choice != 11) {
        cout << "\n=== LAB INVENTORY ===" << endl
             << "1. Add a Device" << endl
             << "2. View All Devices" << endl
             << "3. Search by ID (Binary Search)" << endl
             << "4. Borrow a Device" << endl
             << "5. Return a Device" << endl
             << "6. Low Stock Alert" << endl
             << "7. Save to File" << endl
             << "8. Load from File" << endl
             << "9. Show Data Sizes" << endl
             << "10. AI Inventory Assistant (Mock)" << endl
             << "11. Exit" << endl;

            choice = getPositiveNumber();

            if (choice > 11) {
                cout << "Invalid choice. Please enter 1-11.\n";
                continue;
            }

        switch (choice) {
        case 1: inventory.addDevice(); break;
        case 2: inventory.displayDevices(); break;
        case 3: inventory.searchDevice(); break;
        case 4: inventory.borrowDevice(); break;
        case 5: inventory.returnDevice(); break;
        case 6: inventory.showLowStock(); break;
        case 7: inventory.saveToFile(); break;
        case 8: inventory.loadFromFile(); break;
        case 9: inventory.showDataSizes(); break;
        case 10: {
            inventory.saveToFile();
            cout << "Ask about inventory (or type 'help'): ";
            string question;
            if (!getline(cin >> ws, question)) {
                cout << "Input closed. Goodbye!" << endl;
                return 0;
            }
            cout << endl;
            cout << assistant.ask(question) << endl;
            break;
        }
        case 11:
            cout << "Goodbye!" << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}
