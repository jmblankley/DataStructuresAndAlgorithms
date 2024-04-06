#include <iostream>

using namespace std;

class Item {
public:
    Item(const string& name, int value, int weight) : name(name), value(value), weight(weight) {}

    string getName() const { return name; }
    int getValue() const { return value; }
    int getWeight() const { return weight; }

private:
    string name;
    int value;
    int weight;
};