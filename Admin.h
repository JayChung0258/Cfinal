#include <string>
#include <vector>

using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Person;

class Admin{
public:
    Admin(string password){
        this->Admin_Password = password;
    };
    ~Admin(){};

    bool onerun(int choice, vector <Person*> &person);
    bool check(string password);

private:
    string Admin_Password;
    
private:
    void Add(vector <Person*> &person, string id, string password, string name, string identity);
    void Delete(vector <Person*> &person ,string id);
    void Change(vector <Person*> &person, string id, string password, string name);
    void View(vector <Person*> person);
};

#endif