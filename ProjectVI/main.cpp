#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "Edge.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cerr << "USAGE ERROR, EXPECTED: ./project5 <filename> [-print]" << std::endl;
        return 1; // Return an error code
    }

    string filename = argv[1];
    ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 2; // Return an error code
    }

    vector<Edge> map;
    while(inFile)
    {

    }

    return 0;
}