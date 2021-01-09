#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Course.h"

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

// 課程名稱, id, 時間, 老師, 上課地點
string datas []= {
    "程式設計", "A028", "三234", "王小明", "大仁樓201","3","3",
    "線性代數", "B128", "二234", "李大人", "大仁樓211","2","3",
    "數位系統", "C778", "二D56", "陳沈沈", "大仁樓331","2","3",
    "科技人文",  "F822", "二D56", "陳李李", "大仁樓331","2","3"
};

Course::Course()
{
    for (int i = 0; i < 4; i++)
    {
        string courseName = datas[i * 7];
        string courseId = datas[(i * 7) + 1];
        string time = datas[(i * 7) + 2];
        string teacher = datas[(i * 7) + 3];
        string classRoom = datas[(i * 7) + 4];
        string week = datas[(i * 7) + 5];
        string credit = datas[(i * 7) + 6];
        Course newCoure(courseName, courseId, time, teacher, classRoom, week, credit);
        this->courseList.push_back(newCoure);
    }
}

Course::Course(string courseName, string id, string time, string teacher, string classRoom, string week, string credits){
    this->courseName = courseName;
    this->courseId = id;
    this->time = time;
    this->teacher = teacher;
    this->classRoom = classRoom;
    this->week = stoi(week);
    this->credits = stoi(credits);
}

void Course::addCourse(string courseName,string id, string time, string teacher, string classRoom, string week, string credits)
{
    Course newCoure(courseName, id, time, teacher, classRoom, week, credits);
    this->courseList.push_back(newCoure);
}

void Course::deleteCourse(string id)
{
    int courseLen = this->courseList.size();
    for (int i = 0; i < courseLen; i++)
    {
        if ((this->courseList[i].courseId).compare(id) == 0)
        {
            this->courseList.erase(this->courseList.begin() + i);
        }
    }
}

void Course::printCourseList()
{
    cout << "課程名稱" << setw(20) << "課程ID" << setw(20) << "授課老師" << setw(15) << "上課時間" << setw(15) << "上課教室" << setw(15) << endl;
    int courseLen = this->courseList.size();
    for (int i = 0; i < courseLen; i++) {
        cout << (this->courseList[i].courseName) << setw(15) << (this->courseList[i].courseId) << setw(15) << (this->courseList[i].teacher) << setw(15) << (this->courseList[i].time) << setw(15) << (this->courseList[i].classRoom) << setw(15) << endl;
    }
}

string 
Course::getTime(){
  return this->time;
}
    
string 
Course::getName(){
  return this->courseName;
}
    
string 
Course::getTeacher(){
  return this->teacher;
}
    
string 
Course::getClassroom(){
  return this->classRoom;
}

int 
Course::getWeek(){
  return this->week;
}

int 
Course::getCredits(){
  return this->credits;
}