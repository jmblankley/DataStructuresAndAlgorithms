#include "Interval.hpp"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

bool compareByFinish(const Interval &i1, const Interval &i2)
{
	return i1.finish() < i2.finish();
}

int main(int argc, char *argv[])
{
	string fName = argv[1];
	ifstream ifile(fName);

	list<Interval> possibleJobs;

	Interval job;

	while (ifile)
	{
		ifile >> job;
		possibleJobs.push_back(job);
	}

	list<Interval> answer;
	possibleJobs.sort(compareByFinish);

	for (Interval testJob : possibleJobs)
	{
		if (/* compatible*/)
		{
			answer.push_back(testJob);
		}
	}

	for (Interval i : answer)
	{
		i.display(); // need to make this function
	}

	return 0;
}