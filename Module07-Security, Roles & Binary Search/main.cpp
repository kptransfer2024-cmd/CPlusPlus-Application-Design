#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username;
public:
    User(string name) : username(name) {}

    void viewRecords(int data[], int size) {
        cout << "Records for user " << username << ":" << endl;
        for (int i = 0; i < size; i++) {
            cout << data[i] << "; ";
        }
        cout << endl;
    }
};

class Admin : public User {
public:
    Admin(string name) : User(name) {}
    
    void addRecord(int data[], int &size, int value) { 
        if (size >= 1000){
            cout << "Array is full. Cannot add more records." << endl;
            return;
        } 
        else {
            int location = 0;
            while (location < size && data[location] < value) {
                location++;
            }

            for (int i = size; i > location; i--) {
                data[i] = data[i - 1];
            }
            data[location] = value;
            size++;
        }
    }
    
     void deleteRecord(int data[], int &size, int value) { 
        if (size <= 0) {
            cout << "Array is empty. Cannot delete record." << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    data[j] = data[j + 1];
                }
                size--;
                return;
            }
        }
        cout << "Record not found." << endl;
    }
};


int binarySearch(int data[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) return mid;
        if (data[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int records[1000];
    int size = 100;

    for (int i = 0; i < size; i++){
        records[i] = i;
    }

    int role;
    cout << "enter 0 if you are an admin, 1 if you are a regular user: ";
    cin >> role;
    cout << endl;

    string username;
    cout << "enter your name: ";
    cin >> username;
    cout << endl;

    if (role == 0) {
        Admin admin(username);

        int adminChoice;
        cout << "Hi admin " << username << endl;
        cout << "Select the following admin operations:" << endl;
        cout << "0. View Records" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Search Record" << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice)
        {
        case 0: {
            admin.viewRecords(records, size);
            break;
            }
        case 1: {
            int value1;
            cout << "Enter the value to add: ";
            cin >> value1;
            admin.addRecord(records, size, value1);
            break;
            }
        case 2: {
            int value2;
            cout << "Enter the value to delete: ";
            cin >> value2;
            admin.deleteRecord(records, size, value2);
            break;
            }
        case 3: {
            int value3;
            cout << "Enter the value to search: ";
            cin >> value3;
            int index = binarySearch(records, size, value3);
            if (index != -1) {
                cout << "Value found at index " << index << endl;
            } else {
                cout << "Value not found." << endl;
            }
            break;
            }
        default:
            cout << "Invalid choice." << endl;
        }
    }


    else if (role == 1) {
        User user(username); 
        cout << "Hey user " << username << endl;

        int viewRecords;
        cout << "Do you want to view records? (1 for yes, 0 for no): ";
        cin >> viewRecords;
        if (viewRecords == 1) {
            user.viewRecords(records, size);
        }
        else if (viewRecords == 0) {
            cout << "You chose not to view records." << endl;
        }
        else {
            cout << "Invalid input. Enter 1 for yes, 0 for no." << endl;
        }
    }

    else {
        cout << "Invalid role entered. Enter 0 or 1." << endl;
    }

    return 0;
}