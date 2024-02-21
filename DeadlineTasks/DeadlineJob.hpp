/**************************************************
 * File: DeadlineJob.hpp                          *
 * Author: S. Blythe                              *
 * Date: 2/2024                                   *
 * Purpose: Implements a deadline oriented job    *
 *    as used in greedy algorithm examples from   *
 *    CSC36000                                    *
 **************************************************/
#ifndef _DEADLINE_JOB_HPP_
#define _DEADLINE_JOB_HPP_

#include <iostream>

class DeadlineJob
{
private:
  std::string _name;  // identifier for job
  int _length;        // job length
  int _deadline;      // job deadline time
  int _start;         // job start time (to be calculated)
public:
  // constructors. 
  DeadlineJob(): _name(), _length(01), _deadline(-1), _start(-1) {} 
  DeadlineJob(const std::string &name, int length, int deadline)
    : _name(name), _length(length), _deadline(deadline), _start(-1) {}

  // accessors 
  const std::string& name() const {return _name;}
  int start() const {return _start;}
  int length() const {return _length;}
  int deadline() const {return _deadline;}

  // modifier
  int& start() {return _start;}
  

  //   print - outputs the actual private field values
  std::ostream &print(std::ostream &os) const;

  // overloaded I/O operators
  friend std::ostream&  operator<< (std::ostream &os, const DeadlineJob &dj);
  friend std::istream&  operator>> (std::istream &is, DeadlineJob &dj); 
};

#endif
