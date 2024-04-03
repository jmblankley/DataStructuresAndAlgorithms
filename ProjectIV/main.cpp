#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cmath>
#include <limits>
#include <cfloat>
#include <vector>
using namespace std;

#include "Point.hpp"

// Globals
Point d1point;
Point d2point;

// Function: compareyCoord
// Parameters: -- const Point& a - reference to the first Point object
//             -- const Point& b - reference to the second Point object
// Purpose: Compares two Point objects based on their y-coordinates and returns true if the y-coordinate of 'a' is less than that of 'b', otherwise false.

bool compareyCoord(const Point& a, const Point& b)
{
    return a.getYCoord() < b.getYCoord();
}

// Function: comparexCoord
// Parameters: -- const Point& a - reference to the first Point object
//             -- const Point& b - reference to the second Point object
// Purpose: Compares two Point objects based on their x-coordinates and returns true if the x-coordinate of 'a' is less than that of 'b', otherwise false.
bool comparexCoord(const Point& a, const Point& b)
{
    return a.getXCoord() < b.getXCoord();
}

// Function: distance
// Parameters: -- const Point& p1 - reference to the first Point object
//             -- const Point& p2 - reference to the second Point object
// Purpose: Calculates the Euclidean distance between two Point objects and returns the distance as a float value.
float distance(const Point &p1, const Point &p2) {
    float dx = p1.getXCoord() - p2.getXCoord();
    float dy = p1.getYCoord() - p2.getYCoord();
    return sqrt(dx * dx + dy * dy);
}


// Function: ClosestPair
// Parameters: -- list<Point>& points - list of points
// Purpose: Finds the closest pair of points in the given list using the closest pair algorithm
float ClosestPair(list<Point>& points)
{
    // Base case: If there are only three or fewer points, calculate the distance directly and return.
    if (points.size() <= 3) {
        // Handle the case when there are two points or fewer
        auto it = points.begin();
        Point p1 = *it++;
        Point p2 = *it;
        if (points.size() == 2) {
            d1point = p1;
            d2point = p2;
            return distance(p1, p2);
        }
        // If there's only one point, return a large value indicating no other points to compare.
        return numeric_limits<float>::max(); // returns a crazy big number (biggest float value possible) meaning there are no more points to consider
    }

    // Compute separation line L such that half the points are on one side and half on the other side.
    auto separationLine = next(points.begin(), points.size() / 2);
    list<Point> left(points.begin(), separationLine);
    list<Point> right(separationLine, points.end());

    // δ 1 = Closest-Pair(left half)
    float d1 = ClosestPair(left);

    // δ 2 = Closest-Pair(right half)
    float d2 = ClosestPair(right);

    // δ = min(δ 1 , δ 2 )
    float delta = min(d1, d2);

    // Merge the two halves back together for further processing
    points.merge(right, compareyCoord);

    // Keep track of points within the delta range from the separation line
    list<Point> closePoints;
    for (const auto& point : points) {
        if (abs(point.getXCoord() - separationLine->getXCoord()) < delta) {
            closePoints.push_back(point);
        }
    }

    
    // Tried list but it was a little easier to grab the last two values from a vector
    // Scan points in y-order and compare distance between each point and next 11 neighbors.
    for (auto it = closePoints.begin(); it != prev(closePoints.end(), 11); ++it) {
        auto end = next(it, 12);
        for (auto it2 = next(it); it2 != end; ++it2) {
            float dist = distance(*it, *it2);
            if (dist < delta) {
                delta = dist;
                d1point = *it;
                d2point = *it2;
            }
        }
    }

    return delta;
}

int main(int argc, char *argv[])
{
    cout << "Please enter a file name: ";
    string filename;
    cin >> filename;

    ifstream inFile(filename);

    int numOfCoordinates;

    string name; // name of point
    float xCoord; // x coordinate of point
    float yCoord; // y coordinate of point

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

    // Sort by X coordinates 
    points.sort(comparexCoord);

    // Call ClosestPair to find the smallest distance
    cout << "Min distance: " << ClosestPair(points) << endl;

    cout << "Between: ";
    cout << "[" << d1point.getName() << ":"  << "(" << d1point.getXCoord() << "," << d1point.getYCoord() << ")]";
    cout << " and ";
    cout << "[" << d2point.getName() << ":"  << "(" << d2point.getXCoord() << "," << d2point.getYCoord() << ")]" << endl;


    

    inFile.close(); // Close the file

    return 0;
}
