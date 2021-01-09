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
    Schedule(int belongs, int credits, vector<Course> course);
    void print(int belongs);
private:
    int belongs;
    vector<Course> courseList;
    int total_credits;
};

# endif