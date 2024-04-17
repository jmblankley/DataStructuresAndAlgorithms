/********************************************************
* File: Edge.hpp                                        *
*                                                       *
* Author: Joshua M. Blankley                            *
*                                                       *
* Purpose: Defines the Edge class which represents the  *
* edges in a map.                                       *
*********************************************************/


#include <string>

using namespace std;

class Edge {
private:
    string _nodeA;
    string _nodeB;
    int _length;

public:
    Edge() : _nodeA(""), _nodeB(""), _length(0) {} // Empty constructor
    Edge(string nodeA, string nodeB, int length) : _nodeA(nodeA), _nodeB(nodeB), _length(length) {} // Full constructor

    // Accessors
    string getNodeA() const { return _nodeA; }
    string getNodeB() const { return _nodeB; }
    int getLength() const { return _length; }

    // Modifiers
    void setNodeA(const string &nodeA) { _nodeA = nodeA; }
    void setNodeB(const string &nodeB) { _nodeB = nodeB; }
    void setLength(int length) { _length = length; }

};