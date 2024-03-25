#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
using namespace std;

#include "Point.hpp"

bool compareyCoord(const Point& a, const Point& b)
{
    return a.getYCoord() < b.getYCoord();
}

// Function to calculate the Euclidean distance between two points
float distance(const Point &p1, const Point &p2) {
    float dx = p1.getXCoord() - p2.getXCoord();
    float dy = p1.getYCoord() - p2.getYCoord();
    return sqrt(dx * dx + dy * dy);
}


float ClosestPair(list<Point> points)
{
    cout << "Top of closest pair." << endl;
    // Compute separation line L such that half the points are on one side and half on the other side.
    auto separationLine = std::next(points.begin(), std::distance(points.begin(), points.end()) / 2);
    list<Point> left(points.begin(), separationLine);
    list<Point> right(separationLine, points.end());

    // δ 1 = Closest-Pair(left half)
    float d1 = ClosestPair(left);
    cout << "d1: " << d1 << endl;
     // δ 2 = Closest-Pair(right half)
    float d2 = ClosestPair(right);
    cout << "d2: " << d2 << endl;
    // δ = min(δ 1 , δ 2 )
    float delta = min(d1, d2);
    cout << "delta: " << delta << endl;

    list<Point> temp;

    // Ignore all points further than δ from separation line L
    for(auto i : left)
    {
        if(i.getXCoord() < delta)
        {
            temp.push_back(i);
        }
    }
    for(auto i : right)
    {
        if(i.getXCoord() < delta)
        {
            temp.push_back(i);
        }
    }

    // Sort remaining points by y-coordinate.
    temp.sort(compareyCoord);

    // Scan points in y-order and compare distance between each point and next 11 neighbors. If any of these distances is less than δ, update δ.

    // return δ
    cout << "Bottom of closest pair." << endl;
    return delta;
}

int main(int argc, char *argv[])
{
    cout << "Please enter a file name: ";
    string filename;
    cin >> filename;

    ifstream inFile(filename);

    int numOfCoordinates;
    string name;
    float xCoord;
    float yCoord;

    // Check if file is opened successfully
    if (!inFile)
    {
        cerr << "Unable to open file " << filename << endl;
        return 1; // Return an error code
    }

    list<Point> points;

    // Read the first item into numOfCoordinates
    inFile >> numOfCoordinates;

    // Loop through the file to read the rest of the items
    for (int i = 0; i < numOfCoordinates; ++i)
    {
        // Read name, xCoord, and yCoord in sequence
        inFile >> name >> xCoord >> yCoord;

        // Construct object for insertion into list
        Point forInsertion(name, xCoord, yCoord);

        // Push object into list
        points.push_back(forInsertion);
    }

    ClosestPair(points);

    

    inFile.close(); // Close the file

    return 0;
}
