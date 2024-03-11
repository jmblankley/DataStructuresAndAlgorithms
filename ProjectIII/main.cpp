#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#include "Node.hpp"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        cerr << "USAGE ERROR. EXPECTED: ./run <filename>" << endl;
    }
    
    string filename = argv[1];
    ifstream inFile(filename);

    vector<Node> nodeVec;

    string name;
    int storeCost;
    int deadline;
    Node *inputNode;

        

    return 0;
}