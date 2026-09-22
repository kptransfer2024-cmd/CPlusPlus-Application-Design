#include <iostream>
#include "Records.h"
#include <string>
using namespace std;


void showMessage() {
    cout << "Record system ready!" << endl;
    cout << endl;

    cout << "Please select an operation on the records." << endl;
    cout << "1: add a record" << endl;
    cout << "2: display the records" << endl;
    cout << "3: Calculate the average grade" << endl;
    cout << "4: Delete a record" << endl;
    cout << "5: Search for a record" << endl;
    cout << "6: Exit the Program" << endl;
    cout << endl;

    cout << "Type a number from 1-6: " << endl;
}


void addRecord(int ids[], string names[], double grades[], int& count){
    cout << "Enter student ID: " << endl;
    cin >> ids[count];
    cout << "Enter student name: " << endl;
    cin >> names[count];
    cout << "Enter grade: " << endl;
    cin >> grades[count];

    count += 1;
    return;
}


void displayRecords(int ids[], string names[], double grades[], int count){
    if (count == 0){
        cout << "There is no records" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "student ID: " << ids[i] << ", Name: " << names[i] << ", Grade: " << grades[i] << endl;
    }
    return;
}


double calculateAverage(double grades[], int count){
    double sum = 0;

    if (count == 0){
        cout << "No records in database!";
        return 0;
    }
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}


void deleteRecord(int ids[], string names[], double grades[], int targetId, int& count){
    if (count == 0){
        cout << "No records exist in the database!";
    }   
    else{
        for (int i = 0; i < count; i++){
            if (ids[i] == targetId) {
                for (int j = i; j < count - 1; j++) {
                    ids[j] = ids[j + 1];
                    names[j] = names[j + 1];
                    grades[j] = grades[j + 1];
                }
                count -= 1;
                cout << "The record you specified is deleted" << endl;
                return;
            }
        }
        cout << "The student ID you typed is not in our record systems." << endl;
        return;
    } 
}


void searchRecord(int ids[], string names[], double grades[], int targetId, int count){
    if (count == 0){
        cout << "No records exist in the database!";
    }   
    else{
        for (int i = 0; i < count; i++){
            if (ids[i] == targetId) {
                cout << "Record found: ID = " << ids[i] << endl;
                cout << "Name: " << names[i] << endl;
                cout << "Grade: " << grades[i] << endl;
                return;
            }
        }    
        cout << "The student ID you typed is not in our record systems." << endl;
    }
    return;
}