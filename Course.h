#include <string>
#include <vector>
using namespace std;

# ifndef COURSE_H
# define COURSE_H

class Course;
 // id , time, classroom, teacher, student list, grade limit
class Course
{
public:
    Course();
    Course(string courseName, string id, string time, string teacher, string classRoom);
    void addCourse(string courseName, string id, string time, string teacher, string classRoom);
    void deleteCourse(string id);
    void printCourseList();
private:
    string courseName;
    string courseId;
    string time;
    string teacher;
    string classRoom;
    vector<Course> courseList;
};

# endif