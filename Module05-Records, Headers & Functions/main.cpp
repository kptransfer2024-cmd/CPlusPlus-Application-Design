#include <iostream>
#include "Records.h"
#include <string>
using namespace std;


int main(){
    int count = 0;
    int ids[1000];
    string names[1000];
    double grades[1000];
    int selection;
    int targetId;

    while (1){
        showMessage();
        cin >> selection;

        switch (selection) {
            case 1:
                addRecord(ids, names, grades, count);
                break;

            case 2:
                displayRecords(ids, names, grades, count);
                break;

            case 3:
                if (count == 0) {
                    calculateAverage(grades, count);
                }
                else {
                    cout << "Average grade is: "
                        << calculateAverage(grades, count)
                        << endl;
                }
                break;

            case 4:
                cout << "Type the student ID of the record that you wish to delete: ";
                cin >> targetId;
                deleteRecord(ids, names, grades, targetId, count);
                break;

            case 5:
                cout << "Type the student ID of the record that you wish to search: ";
                cin >> targetId;
                searchRecord(ids, names, grades, targetId, count);
                break;

            case 6:
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid selection. Choose 1-6." << endl;
        }


        cout << endl;
    }
}