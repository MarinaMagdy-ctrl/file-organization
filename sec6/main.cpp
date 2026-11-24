#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    cout << "Step 1: creating Students.txt" << endl;
    ofstream outFile("Students.txt");
    if (!outFile) {
        cout << "Failed to create Students.txt" << endl;
        return 1;
    }

    outFile << "Ali Ahmed" << endl;
    outFile << "Mohamed Rady" << endl;
    outFile << "Youssef Zaki" << endl;
    outFile.close();

    cout << "Step 2: reading and filtering" << endl;
    ifstream inFile("Students.txt");
    ofstream tempFile("temp.txt");
    if (!inFile || !tempFile) {
        cout << "Failed to open files" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    while (getline(inFile, line)) {
        if (lineNumber != 1) {
            tempFile << line << endl;
        }
        lineNumber++;
    }

    inFile.close();
    tempFile.close();

    cout << "Step 3: removing and renaming" << endl;
    remove("Students.txt");
    rename("temp.txt", "Students.txt");

    cout << "Done!" << endl;
    return 0;
}
