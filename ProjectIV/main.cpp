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
    // Base case: If there are only two or fewer points, calculate the distance directly and return.
    if (points.size() <= 3) {
        // Handle the case when there are two points or fewer
        auto it = points.begin();
        Point p1 = *it++;
        Point p2 = *it;
        if (points.size() == 2) {
            return distance(p1, p2);
        }
        // If there's only one point, return a large value indicating no other points to compare.
        return numeric_limits<float>::max();
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

    vector<Point> ansPoints; // Tried list but it was a little easier to grab the last two values from a vector
    // Scan points in y-order and compare distance between each point and next 11 neighbors.
    for (auto it = closePoints.begin(); it != prev(closePoints.end(), 11); ++it) {
        auto end = next(it, 12);
        for (auto it2 = next(it); it2 != end; ++it2) {
            float dist = distance(*it, *it2);
            if (dist < delta) {
                delta = dist;
                ansPoints.push_back(*it);
                ansPoints.push_back(*it2);
            }
        }
    }

    cout << "Min distance: " << delta << endl;

    cout << "Between: ";
    for(int i = ansPoints.size() - 1; i >= 2; i--) // Iterate over vector starting from the end, and only go to the second to last item
    {
        cout << "[" << ansPoints[i].getName() << ":"  << "(" << ansPoints[i].getXCoord() << "," << ansPoints[i].getYCoord() << ")]";
        if(i > 2) // Only put "and" if it is not the last item in the vector
        {
            cout << " and ";
        }
    }
    cout << endl;

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

    // Sort by X coordinates 
    points.sort(comparexCoord);

    ClosestPair(points);

    

    inFile.close(); // Close the file

    return 0;
}
