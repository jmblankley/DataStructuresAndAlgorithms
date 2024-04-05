/***********************************************
 * File: Point.hpp                             *
 *                                             *
 * Author: Joshua Blankley                     *
 *                                             *
 * Date: April 2024                            *
 *                                             *
 * Purpose: This file contains the definition  *
 * of the Point class, which represents a      *
 * point in a 2-dimensional plane.             *
 ***********************************************/

#ifndef _POINT_HPP_
#define _POINT_HPP_

#include <string>
using namespace std;

class Point {
private:
    string _name;
    float _xCoord;
    float _yCoord;

public:
    // Constructors
    Point() : _name(""), _xCoord(0), _yCoord(0) {}
    Point(string name, float xCoord, float yCoord) : _name(name), _xCoord(xCoord), _yCoord(yCoord) {}

    // Accessors
    string getName() const { return _name; }
    float getXCoord() const { return _xCoord; }
    float getYCoord() const { return _yCoord; }

    // Modifiers
    void setName(const string &name) { _name = name; }
    void setXCoord(float xCoord) { _xCoord = xCoord; }
    void setYCoord(float yCoord) { _yCoord = yCoord; }
};

#endif
