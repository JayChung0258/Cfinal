# ifndef SCHEDULE_H
# define SCHEDULE_H
#include "Course.h"
#include <vector>

class Schedule;
 // belongs, course list, credits
class Schedule
{
public:
    Schedule();
    Schedule(vector<Course> course);
    void print();
private:
    int belongs;
    vector<Course> courseList;
    int total_credits;
};

# endif