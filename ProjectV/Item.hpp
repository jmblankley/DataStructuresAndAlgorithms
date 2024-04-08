#include <iostream>

using namespace std;

class Item {
public:
    Item(const string& name, int storageCost, int incinerationTime) : _name(name), _storageCost(storageCost), _incinerationTime(incinerationTime) {}

    string getName() const { return _name; }
    int getStorageCost() const { return _storageCost; }
    int getIncinerationTime() const { return _incinerationTime; }

private:
    string _name;
    int _storageCost;
    int _incinerationTime;
};