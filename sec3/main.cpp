#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outFile("welcome.txt");
    if (!outFile.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    outFile << "Hello Everybody";
    outFile.seekp(11, ios::beg);
    outFile << "one";
    outFile.close();

    ifstream inFile("welcome.txt");
    string text;
    getline(inFile, text);
    inFile.close();

    cout << text.substr(0, 14) << endl;

    return 0;
}

