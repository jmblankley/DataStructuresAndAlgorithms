#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Edge.hpp" // Assuming Edge.hpp contains the definition of Edge class

using namespace std;

bool sortByLength(const Edge& a, const Edge& b) {
    return a.getLength() < b.getLength();
}

void Kruskal(vector<Edge> graph)
{
    sort(graph.begin(), graph.end(), sortByLength);

    for(auto i : graph)
    {
        cout << i.getLength() << endl;
    }
}

int main(int argc, char *argv[])
{
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

    Kruskal(graph);

    return 0;
}
