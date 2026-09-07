#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string username = "Kunpeng";
    string applicationName = "Student Record Application";
    double version = 1.0;

    int age = 21;
    char grade = 'A';
    bool isStudent = true;
    bool isEnrolled = false;
    float gpa = 3.8;
    double height = 6.0;

    cout << "===  ++++ ==================== ++++ ===" << endl;
    cout << "===  ++       MY APPLICATION     ++ ===" << endl;
    cout << "App Name: " << applicationName << endl;
    cout << "Version: " << version << endl;
    cout << "===  ++++ ==================== ++++ ===" << endl;
    cout << endl;
    cout << endl;

    cout << "Name: " << username << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student: " << isStudent << " (1 for YES, 0 for NO)" << endl;
    cout << "Is Enrolled: " << isEnrolled << " (1 for YES, 0 for NO)" << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Height: " << height << endl;
    cout << endl;

    cout << "update your name: ";
    cin >> username;
    cout << "update your age: ";
    cin >> age;
    cout << "update your grade: ";
    cin >> grade;
    cout << "update your GPA: ";
    cin >> gpa;
    cout << "update your height: ";
    cin >> height;
    cout << "Record updated successfully!" << endl;
    cout << endl;
    cout << "=== UPDATED RECORD ===" << endl;
    cout << "Name: " << username << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Height: " << height << endl;

    return 0;
}