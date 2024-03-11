#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <string>
using namespace std;

class Node {
    private:
        string _name;
        int _storeCost; // main value
        int _deadline;
        Node *_left;
        Node *_right;

    public:
        Node() : _name(""), _storeCost(0), _deadline(0), _left(nullptr), _right(nullptr) {}
        Node(string name, int storeCost, int deadline) : _name(name), _storeCost(storeCost), _deadline(deadline), _left(nullptr), _right(nullptr) {}

        // accessors
        const string &getName() { return _name; }
        const int &getCost() { return _storeCost; }
        const int &getDeadline() { return _deadline; } 

        friend ostream &operator<<(ostream &os, const Node &node);
};

#endif