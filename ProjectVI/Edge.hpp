#include <string>

using namespace std;

class Edge {
private:
    string _nodeA;
    string _nodeB;
    int _length;

public:
    Edge() : _nodeA(""), _nodeB(""), _length(0) {}
    Edge(string nodeA, string nodeB, int length) : _nodeA(nodeA), _nodeB(nodeB), _length(length) {}

    // Accessors
    string getNodeA() const { return _nodeA; }
    string getNodeB() const { return _nodeB; }
    int getLength() const { return _length; }

    // Modifiers
    void setNodeA(const string &nodeA) { _nodeA = nodeA; }
    void setNodeB(const string &nodeB) { _nodeB = nodeB; }
    void setLength(int length) { _length = length; }

};