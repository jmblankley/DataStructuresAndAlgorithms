#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Item.hpp"

std::vector<Item> usedItems;

// Function: totalCost
// Parameters: -- const std::vector<Item>& items - reference to the vector of Item objects
//             -- int T - total time available
// Purpose: Uses the knapsack algorithm (dynamic programming) to minimize the total storage cost
int totalCost(const std::vector<Item>& items, int T) {
    int n = items.size();
    int M[n + 1][T + 1]; // Initialize the memoization table
    
    // Initialization of memoization table
    for (int w = 0; w <= T; w++) {
        M[0][w] = 0;
    }
    for (int i = 0; i <= n; i++) {
        M[i][0] = 0;
    }

    // Fill up the 2D array using the knapsack algorithm
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= T; w++) {
            if (items[i - 1].getIncinerationTime() > w) {
                M[i][w] = M[i - 1][w];
            } else {
                M[i][w] = std::max(M[i - 1][w], items[i - 1].getStorageCost() + M[i - 1][w - items[i - 1].getIncinerationTime()]);
            }
        }
    }

    // Backtrack to find the items used
    int remainingTime = T;
    for (int i = n; i > 0 && remainingTime > 0; i--) {
        if (M[i][remainingTime] != M[i - 1][remainingTime]) {
            usedItems.push_back(items[i - 1]);
            remainingTime -= items[i - 1].getIncinerationTime();
        }
    }

    // Calculate the total penalty
    int totalPenalty = 0;
    int maxStorageCost = 0;
    for (const auto& item : items) {
        maxStorageCost += item.getStorageCost();
    }
    totalPenalty = maxStorageCost - M[n][T];

    return totalPenalty;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "USAGE ERROR, EXPECTED: ./project5 <filename> [-print]" << std::endl;
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

    std::vector<Item> items;
    for (int i = 0; i < totalItems; i++) {
        std::string itemName;
        int storageCost, incinerationTime;
        inFile >> itemName >> storageCost >> incinerationTime;
        items.emplace_back(itemName, storageCost, incinerationTime);
    }

    inFile.close();

    int totalPenalty = totalCost(items, maxTime);

    std::cout << "TOTAL PENALTY: " << totalPenalty << std::endl;

    if(argc >= 3)
    {
        std::string printOp = argv[2];

        if(printOp == "-print")
        {        
            std::cout << "STORED ITEMS: ";
            for (const auto& item : items) {
                bool found = false;
                for (const auto& usedItem : usedItems) {
                    if (item.getName() == usedItem.getName()) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << item.getName() << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
