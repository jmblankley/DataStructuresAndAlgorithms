#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map> // For mapping node names to indices
#include "Edge.hpp" // Assuming Edge.hpp contains the definition of Edge class

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

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

bool sortByLength(const Edge& a, const Edge& b) {
    return a.getLength() < b.getLength();
}

vector<Edge> Kruskal(vector<Edge> graph) {
    // Create a mapping from node names to indices
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

    // Initialize disjoint set
    int numNodes = nodeIndices.size();
    DisjointSet ds(numNodes);

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

    vector<Edge> graph; // vector of edges (each edge includes two nodes and the length between them)

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
        // cout << edge.getNodeA() << " " << edge.getNodeB() << " " << edge.getLength() << endl;
        maxCost += edge.getLength();
    }

    cout << "Max Cost: " << maxCost << endl;


    return 0;
}
