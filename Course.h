#include <string>
#include <vector>
using namespace std;

#ifndef COURSE_H
#define COURSE_H

class Teacher;

class Course;
// id , time, classroom, teacher, student list, grade limit
class Course
{
public:
    friend Teacher;

public:
    Course();
    Course(string courseName, string id, string time, string teacher, string classRoom, string week, string credits);
    void addCourse(string courseName, string id, string time, string teacher, string classRoom, string week, string credits);
    bool courseVerify(string id, string teacherName);
    void deleteCourse(string id);
    void changeCourse(string id);
    void showAllCourse(string teacherName);
    void printCourseList();
    string getTime();
    int getWeek();
    int getCredits();
    string getName();
    string getTeacher();
    string getClassroom();

private:
    string courseName;
    string courseId;
    string time;
    int week; //day of the week
    int credits;
    string teacher;
    string classRoom;
    vector<Course> courseList;
};

#endif