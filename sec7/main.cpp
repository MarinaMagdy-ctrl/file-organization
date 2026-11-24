#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ofstream out("names.txt");
    out << "Hadeer Mahmoud" << endl;
    out << "Youssef Ali" << endl;
    out << "Ahmed Mostafa" << endl;
    out << "Esraa Ebrahim" << endl;
    out.close();

    ifstream input("names.txt");
    string line;
    vector<string> data;

    while (getline(input, line)) {
        if (!line.empty()) {
            data.push_back(line);
        }
    }

    sort(data.begin(), data.end());
    input.close();

    cout << "Names sorted Successfully" << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }

    return 0;
}
