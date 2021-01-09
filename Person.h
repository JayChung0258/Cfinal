#include <string>
#include <iostream>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Admin;
class Course;

class Person
{
public:
    friend Admin;

public:
    bool check(string id, string password, string Identity);
    bool onerun(int choice, Course &list);

protected:
    // Virtual functions can be used by student/teacher
    // ....

protected:
    string ID;
    string Password;
    string Name;
    string Identity;
};

#endif