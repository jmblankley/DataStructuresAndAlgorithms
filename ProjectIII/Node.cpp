#include "Node.hpp"
using namespace std;

ostream &operator<<(ostream &os, const Node &node)
{
    os << node._name + " " + to_string(node._storeCost) + " " + to_string(node._deadline);
}