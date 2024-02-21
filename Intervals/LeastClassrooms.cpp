/**************************************************
 * File: LeastClassrooms.cpp                      *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Given a list of lectures (intervals)  *
 *    find the smallest number of classrooms that *
 * can schedules the classes.                     *
 **************************************************/
#include "Classroom.hpp"
#include "GenericHeap.tpp"
#include "Interval.hpp"

#include <fstream>
#include <iostream>
#include <list>

using namespace std;

// a function to help us sort by defining "less than" between two
//  intervals. In this case, we define "less than" to be based
//  only on the finish time of the Intervals (jobs).
bool compareByStart(const Interval &i1, const Interval &i2)
{
	return i1.start() < i2.start();
}

int main(int argc, char *argv[])
{
	// pull in filename from command prompt.
	string fName = argv[1];

	// build input stream from filename
	ifstream ifile(fName);

	list<Interval> lectures; // list of all jobs

	Interval lecture; // next job in input file

	// for each job read from input file, add that job to list of all jobs
	ifile >> lecture;
	while (ifile)
	{
		lectures.push_back(lecture);

		ifile >> lecture;
	}

	list<Classroom> answer;
	int d = 0;
	GenericHeap<Classroom> classroomHeap(lectures.size());

	lectures.sort(compareByStart); // sort the provided lectures (by start time)

	for (Interval i : lectures)
	{
		i.display();
		cout << endl;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// go through each provided lecture (in order of start time)
	for (Interval nextLecture : lectures)
	{
		/* does this lecture fit in an existing classroom? */
		if (!classroomHeap.isEmpty() && classroomHeap.peekMin().finish() <= nextLecture.start())
		{
			cout << "Scheduling " << nextLecture
				 << " in classroom " << classroomHeap.peekMin() << endl;
			classroomHeap.peekMin().finish() = nextLecture.finish();
			classroomHeap.downHeap();
		}
		else
		{
			// add a new classroom with lecture schdeuled into the classroom
			d++;
			Classroom newClassroom(nextLecture.finish());
			classroomHeap.add(newClassroom);
			cout << "Scheduling " << nextLecture
				 << " in classroom " << newClassroom << " ****" << endl;
		}
	}

	cout << "We will need " << d << " classrooms." << endl;

	return 0;
}
