#ifndef RECORDS_H
#define RECORDS_H


#include <string>
using namespace std;

void showMessage();

void addRecord(int ids[], string names[], double grades[], int& count);

void displayRecords(int ids[], string names[], double grades[], int count);

double calculateAverage(double grades[], int count);

void deleteRecord(int ids[], string names[], double grades[], int targetId, int& count);

void searchRecord(int ids[], string names[], double grades[], int targetId, int count);

#endif