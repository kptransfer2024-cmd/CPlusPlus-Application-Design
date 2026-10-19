#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int getPositiveNumber() {
    int value;
    string input;
    string extra;

    while (true) {
        cout << "Enter a positive number: ";
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra) && value > 0) {
            return value;
        }

        cout << "Invalid input. Try again.\n";
        cout << "please enter a positive integer.\n";
    }
}

int main() {
    int number = getPositiveNumber();

    cout << "You entered: " << number << endl;

    return 0;
}