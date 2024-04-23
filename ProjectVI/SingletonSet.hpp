/********************************************************
* File: SingletonSet.hpp                                *
*                                                       *
* Author: Joshua M. Blankley                            *
*                                                       *
* Purpose: Defines the SingletonSet class which         *
* is used in Kruskal's algorithm to maintain a set of   *
* connected nodes/verticies.                            *
*********************************************************/


#include <vector>
using namespace std;

class SingletonSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Function: Constructor
    // Parameters: -- int n - number of elements in the set
    // Purpose: Initializes the parent and rank vectors to represent n disjoint sets
    SingletonSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Function: find
    // Parameters: -- int u - element whose root is to be found
    // Purpose: Finds and returns the representative/root element of the set containing u
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Function: merge
    // Parameters: -- int u - element from first set to be merged
    //             -- int v - element from second set to be merged
    // Purpose: Merges the sets containing elements u and v if they are disjoint
    void merge(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
