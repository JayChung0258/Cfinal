#include <string>
#include "Person.h"

using namespace std;

# ifndef TEACHER_H
# define TEACHER_H

class Admin;

class Teacher: public Person{
public:
    friend Admin;
protected:
    Teacher(string id, string password, string name, string identity);
};

# endif