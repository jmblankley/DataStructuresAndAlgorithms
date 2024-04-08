#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Item.hpp"

#define MAXVAL 10000

std::vector<Item> storedItems;

int totalCost(int n, int W, const int* sC, const int* iT) {
    long unsigned int M[n+1][W+1]; // Initialize the memoization table

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            M[i][w] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if(iT[i - 1] > w) {
                M[i][w] = M[i - 1][w];
            } else {
                M[i][w] = std::max(M[i - 1][w], sC[i - 1] + M[i - 1][w - iT[i - 1]]);
            }
        }
    }

    // Print the 2D array M
    std::cout << "Memoization Table (M):" << std::endl;
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            std::cout << M[i][w] << "\t";
        }
        std::cout << std::endl;
    }

    return M[n][W];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "USAGE ERROR, EXPECTED: ./project5 <filename>" << std::endl;
        return 1; // Return an error code
    }

    std::string filename = argv[1];
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1; // Return an error code
    }

    int totalItems, maxTime;
    inFile >> totalItems >> maxTime;
    inFile.ignore(); // Ignore the newline character

    int storageCosts[totalItems];
    int incinerationTimes[totalItems];

    for (int i = 0; i < totalItems; i++) {
        std::string itemName;
        int storageCost, incinerationTime;
        inFile >> itemName >> storageCost >> incinerationTime;
        storageCosts[i] = storageCost;
        incinerationTimes[i] = incinerationTime;
    }

    inFile.close();

    std::cout << "TOTAL PENALTY: " << totalCost(totalItems, maxTime, storageCosts, incinerationTimes) << std::endl;

    return 0;
}
