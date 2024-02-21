#include "DeadlineJob.hpp"

using namespace std;

ostream &
DeadlineJob::print(std::ostream &os) const
{
  os << _name
     << ": length=" << _length
     << ", deadline=" << _deadline
     << ", start time=";
  if (_start!=-1)
    { 
      os << _start
	 << ", lateness=" << max(0, _start+_length-_deadline);
    }
  else
    os <<  "<unscheduled>";

  return os;
}

std::ostream&  operator<< (std::ostream &os, const DeadlineJob &dj)
{
  return dj.print(os);
}

std::istream&  operator>> (std::istream &is, DeadlineJob &dj)
{
  is >> dj._name;
  is >> dj._length;
  is >> dj._deadline;

  return is;
}
