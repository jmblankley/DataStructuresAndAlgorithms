#ifndef _WASTE_ITEM_
#define _WASTE_ITEM_

#include <string>
using namespace std;

class WasteItem {
    private:
        string _name;
        int _storeCost; // main value
        int _deadline;
        WasteItem *_left;
        WasteItem *_right;

    public:
        WasteItem() : _name(""), _storeCost(0), _deadline(0), _left(nullptr), _right(nullptr) {}
        WasteItem(string name, int storeCost, int deadline) : _name(name), _storeCost(storeCost), _deadline(deadline), _left(nullptr), _right(nullptr) {}

        // accessors
        const string& getName() const { return _name; }
        int getCost() const { return _storeCost; }
        int getDeadline() const { return _deadline; } 

        friend ostream &operator<<(ostream &os, const WasteItem &item);
};

#endif