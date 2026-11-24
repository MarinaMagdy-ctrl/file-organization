#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);
    if (outFile.fail()) {
        cout << "Unable to open students.txt" << endl;
        return 1;
    }

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        char name[20];
        int id;
        float grade;

        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 20);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Grade: ";
        cin >> grade;

        outFile << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Add another student? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "Records saved to students.txt successfully." << endl;

    return 0;
}
