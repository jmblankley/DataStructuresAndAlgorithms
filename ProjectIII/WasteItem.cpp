#include "WasteItem.hpp"
using namespace std;

ostream &operator<<(ostream &os, const WasteItem &item)
{
    os << item._name + " " + to_string(item._storeCost) + " " + to_string(item._deadline);
    return os;
}