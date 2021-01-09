#include "Teacher.h"

Teacher::Teacher(string id, string password, string name, string identity): Person(){
    this->ID = id;
    this->Password = password;
    this->Name = name;
    this->Identity = identity;
}