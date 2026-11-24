#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening persons.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter name and age for person " << i + 1 << ": ";
        cin >> name >> age;
        outFile << name << " " << age << endl;
    }
    outFile.close();

    ifstream inFile("persons.txt");
    if (!inFile.is_open()) {
        cout << "Error reading persons.txt" << endl;
        return 1;
    }

    vector<Person> people;
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        people.push_back(temp);
    }
    inFile.close();

    ofstream resFile("results.txt");
    if (!resFile.is_open()) {
        cout << "Error opening results.txt" << endl;
        return 1;
    }

    if (people.empty()) {
        resFile << "No persons data found." << endl;
    } else {
        Person youngest = people[0];
        Person oldest = people[0];

        for (int i = 1; i < people.size(); i++) {
            if (people[i].age < youngest.age) {
                youngest = people[i];
            }
            if (people[i].age > oldest.age) {
                oldest = people[i];
            }
        }

        resFile << "Youngest: " << youngest.name << " (" << youngest.age << ")" << endl;
        resFile << "Oldest: " << oldest.name << " (" << oldest.age << ")" << endl;
    }

    resFile.close();
    cout << "Done! Results saved to results.txt" << endl;

    return 0;
}
