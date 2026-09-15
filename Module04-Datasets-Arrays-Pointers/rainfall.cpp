#include <iostream>
#include <fstream>
using namespace std;

int main() {

    const int records = 7;
    int years[records];
    int juneRainfall[records];
    int julyRainfall[records];

    ifstream file("rainfall.csv");

    for (int i = 0; i < records; i++) {
        file >> years[i]
             >> juneRainfall[i]
             >> julyRainfall[i];
    }

    file.close();

    cout << records << " records selected" << endl;
    cout << endl;

    for (int i = 0; i < records; i++) {
        cout << "Year: " <<years[i] << endl;
        cout << "June: " << juneRainfall[i]
             << " mm" << endl;
        cout << "July: " << julyRainfall[i]
             << " mm" << endl;
        cout << endl;
    }

    int *yearsPtr = &years[0];
    int *rainfallPtr1 = &juneRainfall[0];
    int *rainfallPtr2 = &julyRainfall[0];

    cout << "First Year through pointer: " << *yearsPtr << endl;
    cout << "First June rainfall through pointer: "
         << *rainfallPtr1 << " mm" << endl;
    cout << "First July rainfall through pointer: "
         << *rainfallPtr2 << " mm" << endl;

    return 0;
}