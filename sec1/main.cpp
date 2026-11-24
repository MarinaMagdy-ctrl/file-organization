#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName, id, grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter Grade: ";
    getline(cin, grade);

    ofstream outFile("Student.txt");

    if (!outFile.is_open()) {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    outFile << "Full Name: " << fullName << endl;
    outFile << "ID: " << id << endl;
    outFile << "Grade: " << grade << endl;

    outFile.close();
    cout << "Student data written to Student.txt successfully." << endl;

    return 0;

}
