#include <string>
#include "Person.h"

using namespace std;

# ifndef STUDENT_H
# define STUDENT_H

class Admin;

class Student: public Person{
public:
    friend Admin;

protected:
    Student(string id, string password, string name, string identity);
};

# endif