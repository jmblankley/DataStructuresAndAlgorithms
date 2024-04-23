/********************************************************
* File: main.cpp                                        *
*                                                       *
* Author: Joshua M Blankley                             *
*                                                       *
* Purpose: This project is an exercise in using graphs  *
* to solve a networking problem rather than a           *
* functional communication program. It aimed to         *
* efficiently connect islands with computer network     *
* lines, ensuring seamless communication while          *  
* minimizing costs. By representing the problem as a    *
* graph and coding a specialized algorithm, the project *
* demonstrates the application of graph theory          * 
* principles in solving real-world challenges.          *
*********************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Edge.hpp"
#include "SingletonSet.hpp"

using namespace std;

// Sort by Edge lengths
bool sortByLength(const Edge& a, const Edge& b) {
    return a.getLength() < b.getLength();
}

// Function: Kruskal
// Parameters: -- vector<Edge> graph - list of edges representing the graph
// Purpose: Implements Kruskal's algorithm to find the minimum spanning tree (MST) of a graph.
//          Returns the MST as a list of edges.
vector<Edge> Kruskal(vector<Edge> graph) {
    // Create a map from node names to indices
    unordered_map<string, int> nodeIndices;
    int index = 0;
    for (const auto& edge : graph) {
        if (nodeIndices.find(edge.getNodeA()) == nodeIndices.end()) {
            nodeIndices[edge.getNodeA()] = index++;
        }
        if (nodeIndices.find(edge.getNodeB()) == nodeIndices.end()) {
            nodeIndices[edge.getNodeB()] = index++;
        }
    }

    // Initialize singleton set
    int numNodes = nodeIndices.size();
    SingletonSet ds(numNodes);

    // Initialize minimum spanning tree
    vector<Edge> mst;

    // Sort edges by length
    sort(graph.begin(), graph.end(), sortByLength);

    // Iterate through sorted edges
    for (const auto& edge : graph) {
        int u = nodeIndices[edge.getNodeA()];
        int v = nodeIndices[edge.getNodeB()];

        // Check if adding this edge forms a cycle
        if (ds.find(u) != ds.find(v)) {
            // Add edge to MST
            mst.push_back(edge);
            // Merge sets of u and v
            ds.merge(u, v);
        }
    }

    return mst;
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "USAGE ERROR, EXPECTED: ./project5 <filename>" << std::endl;
        return 1; // Return an error code
    }

    string filename = argv[1];
    ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 2; // Return an error code
    }

    vector<Edge> graph; // Vector of edges (each edge includes two nodes and the length between them)

    // Iterate through the inFile and construct Edges and push them into the map
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string nodeA, nodeB;
        int weight;
        ss >> nodeA >> nodeB >> weight;
        graph.push_back(Edge(nodeA, nodeB, weight));
    }

    // Apply Kruskal's algorithm
    vector<Edge> mst = Kruskal(graph);
    int maxCost = 0;

    // Print the minimum spanning tree if needed
    for (const auto& edge : mst) {
        maxCost += edge.getLength();
    }

    cout << "Max Cost: " << maxCost << endl;


    return 0;
}
