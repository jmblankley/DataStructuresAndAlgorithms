#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
using namespace std;

#include "WasteItem.hpp"

// Function: mergeHelper
// Parameters: -- list<WasteItem> &wasteItems - original list that needs sorting
//             -- list<WasteItem>::iterator left - iterator pointing to the beginning of the current sublist
//             -- list<WasteItem>::iterator middle - iterator pointing to the middle
//             -- list<WasteItem>::iterator right - iterator pointing to the end
// Purpose: Merges the two sorted sublists created from the original list. Then copies the mergedList back into the original list.
void mergeHelper(list<WasteItem> &wasteItems, list<WasteItem>::iterator left, list<WasteItem>::iterator middle, list<WasteItem>::iterator right)
{
    list<WasteItem> mergedList;

    auto i = left;
    auto j = middle;

    while (i != middle && j != right)
    {
        if (i->getDeadline() <= j->getDeadline()) // Compare based on deadlines
        {
            mergedList.push_back(*i);
            ++i;
        }
        else
        {
            mergedList.push_back(*j);
            ++j;
        }
    }

    // Copy first sublist
    while (i != middle)
    {
        mergedList.push_back(*i);
        ++i;
    }

    // Copy second sublist
    while (j != right)
    {
        mergedList.push_back(*j);
        ++j;
    }

    // Copy all elements back into original list
    auto k = left;
    for (const auto &element : mergedList)
    {
        *k = element;
        ++k;
    }
}

// Function: mergeSort
// Parameters: -- list<WasteItem> &wasteItems - array that will be sorted
//             -- list<WasteItem>::iterator left - iterator pointing to the beginning
//             -- list<WasteItem>::iterator right - iterator pointing to the end
// Purpose: Uses the merge sort algorithm to sort the input array
void mergeSort(list<WasteItem> &wasteItems, list<WasteItem>::iterator left, list<WasteItem>::iterator right)
{
    if (distance(left, right) > 1)
    {
        auto mid = next(left, distance(left, right) / 2);

        mergeSort(wasteItems, left, mid);
        mergeSort(wasteItems, mid, right);

        mergeHelper(wasteItems, left, mid, right); // call mergeHelper to merge the list back into one
    }
}


int main(int argc, char *argv[])
{
    /*****************************************************************************************************************************************
    1. !!DONE!! Read the input file and store the toxic waste items in a list or array, each item containing the name, storage cost, and deadline.
    2. !!DONE!! Sort the list of toxic waste items based on their deadlines in ascending order.
    3. Initialize a variable `total_storage_cost` to 0.
    4. Initialize a variable `current_day` to 1.
    5. For each toxic waste item in the sorted list:
        6. If the current day is greater than the deadline of the item:
            7. Add the storage cost of the item to `total_storage_cost`.
        8. Else:
            9. Increment `current_day` by 1 and repeat step 6.
    10. Output `total_storage_cost`.
    ******************************************************************************************************************************************/
   
    if(argc < 2)
    {
        cerr << "USAGE ERROR! Expected ./run <filename>, got: " << argv[0] << " " << argv[1] << endl; // error message for when the user doesn't include an input file
        cout << endl;
        return 1;
    }

    // 1. Read the input file and store toxic waste items in a list/array/tree/heap.

    string filename = argv[1]; // filename gotten from console
    ifstream inFile(filename); // ifstream created from filename

    list<WasteItem> wasteItems; // Vector to store WasteItem objects

    // Read each line from the input file
    string name;
    int storeCost, deadline;

    while (inFile >> name >> storeCost >> deadline) { // while the inFile is taking in waste items push new waste item onto vector
        // Create a new WasteItem object and add it to the vector
        wasteItems.push_back(WasteItem(name, storeCost, deadline));
    }

    // Close the input file
    inFile.close();

    // 2. Sort the list of toxic waste items based on their deadlines in ascending order.
    mergeSort(wasteItems, wasteItems.begin(), wasteItems.end());

    // initialize variables to keep track of the total storage cost as well as the current day
    int totalStorageCost = 0;
    int currDay = 1;

    // 3. For each waste item in the list 
    for(auto i : wasteItems)
    {
        // NEED TO ADD LOGIC TO CHECK WASTE ITEMS WITH THE SAME DEADLINES AND ONLY ADD THE SMALLER COST TO THE TOTAL STORAGE COST
        /*** If the current day is greater than the deadline of the item add the storage cost of the item to the totalStorageCost ***/
        if(currDay > i.getDeadline())
        {
            totalStorageCost += i.getCost();
        }
        else /*** Else, increment currDay by 1 and repeat ***/
        {
            currDay++;
        }
    }

    cout << totalStorageCost << endl;



    return 0;
}