#include <string>

using namespace std;

# ifndef PERSON_H
# define PERSON_H

class Admin;

class Person{
public:
    friend Admin;

protected:

    // Virtual functions can be used by student/teacher
    // .... 

protected:
    string ID;
    string Password;
    string Name;
    string Identity;
};

# endif