#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Item.hpp"

vector<Item> storedItems;

// Function: totalCost
// Parameters: -- const Point& a - reference to the first Point object
//             -- int n - number of items to look at
//             -- int T - total time availble
//             -- const int* sC - pointer to the storage cost array
//             -- const int* iT - pointer to the incinerationTime array
// Purpose: Uses the knapsack algorithm (dynamic programming) to minimize the total storage cost
int totalCost(int n, int T, const int* sC, const int* iT) {
    long unsigned int M[n+1][T+1]; // Initialize the memoization table
    
    for(int w = 0; w <= T; w++)
    {
        M[0][w] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        M[i][0] = 0;
    }

    // fill up the 2d array using the knapsack algorithm
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= T; w++) {
            if(iT[i - 1] > w) {
                M[i][w] = M[i - 1][w];
            } else {
                M[i][w] = std::max(M[i - 1][w], sC[i - 1] + M[i - 1][w - iT[i - 1]]);
            }
        }
    }

    // DEBUG
    // Print the 2D array M
    std::cout << "Memoization Table (M):" << std::endl;
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= T; w++) {
            std::cout << M[i][w] << "\t";
        }
        std::cout << std::endl;
    }
    // DEBUG

    return M[n][T];
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
