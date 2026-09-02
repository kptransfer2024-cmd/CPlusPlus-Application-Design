#include <iostream>
#include <string>
using namespace std;

void addRecord() {
    cout << "Add Record selected." << endl;
}

void deleteRecord() {
    cout << "Delete Record selected." << endl;
}

void updateRecord() {
    cout << "Update Record selected." << endl;
}

void viewRecords() {
    cout << "View Records selected." << endl;
}

void searchRecords() {
    cout << "Search selected." << endl;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== MY APPLICATION ===" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Update Record" << endl;
        cout << "4. Search" << endl;
        cout << "5. View Records" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                searchRecords();
                break;
            case 5:
                viewRecords();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                cout << "Have a nice day!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Pick a choice between 1 and 6." << endl;
                cout << "Try again." << endl;
        }
    }

    return 0;
}