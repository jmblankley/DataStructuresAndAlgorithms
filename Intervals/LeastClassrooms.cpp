/**************************************************
 * File: LeastClassrooms.cpp                                    *
 * Author: S. Blythe                              						  *
 * Date: 2/2024                                   						   *
 * Purpose: Given a list of lectures (intervals)        *
 *    find the smallest number of classrooms 	  	 *
 *    can schedule classes                          				*
 **************************************************/
#include "GenericHeap.tpp"
#include "Classroom.hpp"
#include "Interval.hpp"

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

// a function to help us sort by defining "less than" between two
//  intervals. In this case, we define "less than" to be based
//  only on the finish time of the Intervals (jobs).
bool compareByFinish(const Interval &i1, const Interval &i2)
{
	return i1.finish() < i2.finish();
}

int main(int argc, char *argv[])
{
	// pull in filename from command prompt.
	string fName = argv[1];

	// build input stream from filename
	ifstream ifile(fName);

	list<Interval> lectures; // list of all jobs

	Interval lecture; // next lecture in input file

	// for each lecture read from input file, add that lecture to list of all jobs
	ifile >> lecture;
	while (ifile)
	{
		lectures.push_back(lecture);

		ifile >> lecture;
	}

	list<Interval> answer; // the collection of maximum size. Intially empty.
	int d = 0;
	GenericHeap<Classroom> classroomHeap(lectures.size());

	lectures.sort(compareByFinish); // sort the provided jobs (by finish time)

	for (Interval i : lectures)
	{
		i.display();
		cout << endl;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	int lastFinishTime = 0;

	// go through each provided lecture (in order of finish time)
	for (Interval nextLecture : lectures)
	{
		// does this lecture fit in an exisitng classroom?
		if (classroomHeap.peekMin().finish() <= nextLecture.start())
		{
			// schedule the lecture into the Classroom
			classroomHeap.peekMin().finish() = nextLecture.finish();
			classroomHeap.downHeap();
		}
		else
		{
			// add a new classroom with lecture scheduled into the classroom
			d++;
			Classroom cNew(nextLecture.finish());
			classroomHeap.add(cNew);
		}
	}

	cout << d << endl;

	return 0;
}
