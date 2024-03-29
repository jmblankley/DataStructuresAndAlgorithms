/********************************************************
 * File: WasteItem.cpp                                  *
 * Author: JMBlankley                                   *
 * Date: 1/2024                                         *
 * Purpose: Implementation for a Waste Item             *
 ********************************************************/

#include "WasteItem.hpp"
using namespace std;

ostream &operator<<(ostream &os, const WasteItem &item)
{
    os << item._name + " " + to_string(item._storeCost) + " " + to_string(item._deadline);
    return os;
}
