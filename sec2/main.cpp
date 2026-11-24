
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");

    if (!inFile.is_open()) {
        cout << "Error, could not open fruit.txt" << endl;
        return 1;
    }

    string fruit;
    while (getline(inFile, fruit)) {
        cout << fruit << endl;
    }

    inFile.close();
    return 0;
}

