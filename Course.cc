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
    "程式設計", "A028", "三234", "王小明", "大仁樓201",
    "線性代數", "B128", "二234", "李大人", "大仁樓211",
    "數位系統", "C778", "二D515", "陳沈沈", "大仁樓331",
    "科技人文",  "F822", "二D515", "陳李李", "大仁樓31",
};

Course::Course()
{
    for (int i = 0; i < 4; i++)
    {
        string courseName = datas[i * 5];
        string courseId = datas[(i * 5) + 1];
        string time = datas[(i * 5) + 3];
        string teacher = datas[(i * 5) + 2];
        string classRoom = datas[(i * 5) + 4];
        Course newCoure(courseName, courseId, time, teacher, classRoom);
        this->courseList.push_back(newCoure);
    }
}

Course::Course(string courseName, string id, string time, string teacher, string classRoom){
    this->courseName = courseName;
    this->courseId = id;
    this->time = time;
    this->teacher = teacher;
    this->classRoom = classRoom;
}

void Course::addCourse(string courseName,string id, string time, string teacher, string classRoom)
{
    Course newCoure(courseName, id, time, teacher, classRoom);
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