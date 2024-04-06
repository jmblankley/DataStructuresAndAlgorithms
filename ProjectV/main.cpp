#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Item.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "USAGE ERROR, EXPECTED: ./project5 <filename>" << endl;
        return 1; // Return an error code
    }

    string filename = argv[1];
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return 1; // Return an error code
    }

    int totalItems, maxWeight;
    inFile >> totalItems >> maxWeight;
    inFile.ignore(); // Ignore the newline character

    vector<Item> items;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string itemName;
        int itemValue, itemWeight;
        ss >> itemName >> itemValue >> itemWeight;
        items.emplace_back(itemName, itemValue, itemWeight);
    }

    // Printing for verification
    cout << "Total Items: " << totalItems << endl;
    cout << "Max Weight: " << maxWeight << endl;
    for (const auto &item : items) {
        cout << item.getName() << " " << item.getValue() << " " << item.getWeight() << endl;
    }

    return 0;
}
