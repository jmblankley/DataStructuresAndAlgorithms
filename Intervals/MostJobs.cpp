/**************************************************
 * File: MostJobs.cpp                             *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Given a list of jobs (intervals)      *
 *    find the largest subset of the jobs that    *
 *    do not overlap.                             *
 **************************************************/
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

	list<Interval> possibleJobs; // list of all jobs

	Interval job; // next job in input file

	// for each job read from input file, add that job to list of all jobs
	ifile >> job;
	while (ifile)
	{
		possibleJobs.push_back(job);

		ifile >> job;
	}

	list<Interval> answer; // the collection of maximum size. Intially empty.

	possibleJobs.sort(compareByFinish); // sort the provided jobs (by finish time)

	int lastFinishTime = 0;

	// go through each provided job (in order of finish time)
	for (Interval testJob : possibleJobs)
	{
		if (testJob.start() >= lastFinishTime)
		{
			answer.push_back(testJob); // ... add job to optimal answer`
			lastFinishTime = testJob.finish();
		}
	}

	// display each chosen interval from optimal answer
	for (Interval i : answer)
	{
		i.display();
		cout << endl;
	}

	return 0;
}
