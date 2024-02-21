DEBUG = -g
CC = g++ -c $(DEBUG) -Wall -ansi -pedantic -std=c++20
LN = g++

SOBJS = Interval.o

all: maxjobs minrooms


maxjobs:  MostJobs.o $(SOBJS)
	$(LN) -o maxjobs  MostJobs.o $(SOBJS)

minrooms:  LeastClassrooms.o Classroom.o $(SOBJS)
	$(LN) -o minrooms  LeastClassrooms.o Classroom.o $(SOBJS)

Classroom.o: Classroom.cpp Classroom.hpp
	$(CC) Classroom.cpp

LeastClassrooms.o: LeastClassrooms.cpp Interval.hpp GenericHeap.hpp GenericHeap.tpp
	$(CC) LeastClassrooms.cpp

MostJobs.o: MostJobs.cpp Interval.hpp
	$(CC) MostJobs.cpp

Interval.o: Interval.cpp Interval.hpp
	$(CC) Interval.cpp

clean:
	/bin/rm -rf *.o maxjobs minrooms *~ \#*

