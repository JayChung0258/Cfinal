#include "Student.h"

Student::Student(string id, string password, string name, string identity): Person(){
    this->ID = id;
    this->Password = password;
    this->Name = name;
    this->Identity = identity;
}
