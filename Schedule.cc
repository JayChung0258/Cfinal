#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include "Schedule.h"
#include "Course.h"
using namespace std;

string courses []= {
    "程式設計", "A028", "三234", "王小明", "大仁樓201","3","3",
    "線性代數", "B128", "二234", "李大人", "大仁樓211","2","3",
    "數位系統", "C778", "二D56", "陳沈沈", "大仁樓331","2","3",
    "演算法",  "G222", "六234", "沈大大", "大仁樓301","6","3"
};

string timeList [] = {
  "06:00 A",
  "07:00 B",
  "08:00 1",
  "09:00 2",
  "10:00 3",
  "11:00 4",
  "12:00 C",
  "13:00 D",
  "14:00 5",
  "15:00 6",
  "16:00 7",
  "17:00 8",
  "18:00 E",
  "19:00 F",
  "20:00 G",
};

int switchTime(char startTime){
  if(startTime=='A' || startTime=='B')
    return startTime-'A';
  else if(startTime=='C' || startTime=='D')
    return startTime-'=';
  else if(startTime=='E' || startTime=='F' || startTime=='G')
    return startTime-'9';
  else if(startTime=='1' || startTime=='2' || startTime=='3' || startTime=='4')
    return startTime-'/';
  else if(startTime=='5' || startTime=='6' || startTime=='7' || startTime=='8')
    return startTime-'-';
  else{
    cout << "課程時間有誤" << endl; 
    return -1;      
  } 
}

Schedule::Schedule(){
  for (int i = 0; i < 4; i++){
    string courseName = courses[i * 7];
    string courseId = courses[(i * 7) + 1];
    string time = courses[(i * 7) + 2];
    string teacher = courses[(i * 7) + 3];
    string classRoom = courses[(i * 7) + 4];
    string week = courses[(i * 7) + 5];
    string credits = courses[(i * 7) + 6];
    Course newCoure(courseName, courseId, time, teacher, classRoom,week,credits);
    this->courseList.push_back(newCoure);
  }
  this->belongs=2021;
  this->total_credits=12;
}

Schedule::Schedule(int belongs, int credits, vector<Course> course){
  this->belongs=belongs;
  this->courseList=course;
  this->total_credits=credits;
}

void 
Schedule::print(int belongs){
  if(this->belongs==belongs){
    cout << setw(18) << "一" << setw(15) << "二" << setw(15) << "三" << setw(15) << "四" << setw(15) << "五" << setw(15) << "六" << endl;
    int courseLen = this->courseList.size();
    int flag[6][16]={0}; //1: not to print upper line
    string weekList[6][16];
    for(int i=0;i<6;i++){
      for(int j=0;j<16;j++)
        weekList[i][j]="XXX";
    }
    for (int i = 0; i < courseLen; i++) {
      int week = this->courseList[i].getWeek();;
      int credits = this->courseList[i].getCredits();
      char startTime=this->courseList[i].getTime().at(3);
      int start=switchTime(startTime);
      for(int j=0;j<credits;j++){
        if(j==0)
          weekList[week-1][start+j]=courseList[i].getName();
        else if(j==1){
          weekList[week-1][start+j]=courseList[i].getClassroom();
          flag[week-1][start+j]=1;
        }
        else
          flag[week-1][start+j]=1;
      }
    }
    for(int i=0;i<16;i++){
      for(int j=0;j<6;j++){
        if(j==0)
          cout<<"----------";
        if(flag[j][i]==0)
          cout<<"--------------";
        else
          cout<<"              ";
      }
      cout<<'X'<<endl;
      for(int k=0;k<6;k++){
        if(k==0)
          cout<<timeList[i]<<"   ";
        if(weekList[k][i]=="XXX")
          cout<<"              ";
        else{
          int left_side=(14-weekList[k][i].length()/3*2)/2;
          int right_side=14-weekList[k][i].length()/3*2-left_side;
          for(int i=0;i<left_side;i++)
            cout<<" ";
          cout<<weekList[k][i];
          for(int i=0;i<right_side-1;i++)
            cout<<" ";
        }
      }
      cout<<endl;
    }
    
  }
}

