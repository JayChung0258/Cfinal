#include <iostream>
#include <string>
#include "Admin.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

bool Admin::onerun(int choice, vector <Person*> &person){
    bool logout = false;
    string id, password, name, identity;

    switch (choice){
        case 1:
            cout << "New ID: ";
            cin >> id;
            cout << "New Password: "; 
            cin >> password;
            cout << "New name: "; 
            cin >> name;
            cout << "New Identity(S/T): ";
            cin >> identity;
            this->Add(person, id, password, name, identity);
            cin.get();
            cout << endl;
            break;
        case 2:
            cout << "The ID you want to delete: ";
            cin >> id;
            this->Delete(person, id);
            cin.get();
            cout << endl;
            break;
        case 3:
            cout << "Your ID: ";
            cin >> id;
            cout << "New Password: "; 
            cin >> password;
            cout << "New name: "; 
            cin >> name;
            this->Change(person, id, password, name);
            cin.get();
            cout << endl;
            break;
        case 4:
            this->View(person);
            break;
        case 5:
            logout = true;
            break;
    }

    if(logout){
        return false;
    }
    else{
        return true;
    }
}

// Add new student/teacher
void Admin::Add(vector <Person*> &person, string id, string password, string name, string identity){
    if(identity == "S"){
        Student *new_person = new Student(id, password, name, identity);
        person.push_back(new_person);
        cout << "Add Successfully!!" << endl;
    }
    else if(identity == "T"){
        Teacher *new_person = new Teacher(id, password, name, identity);
        person.push_back(new_person);
        cout << "Add Successfully!!" << endl;
    }
    else{
        cout << identity << " is not a legal identity." << endl;
    }
}

// Delete member from list
void Admin::Delete(vector <Person*> &person, string id){
    char ans;
    bool deleted = false;
    cout << "Are you sure ? [y]/[n]" << endl << "Enter: ";
    cin >> ans;
    if(ans == 'y' || ans == 'Y'){
        if(!person.empty()){
            for(size_t i=0;i<person.size();i++){
                if(id == person[i]->ID){
                    person.erase(person.begin()+i);
                    deleted = true;
                }
            }
            if(deleted){
                cout << "Delete Successfully!!" << endl;
            }
            else{
                cout << "Undefine person cannot delete!!" << endl;
            }
        }
        else{
            cout << "Empty list cannot delete." << endl;
        }
    }
    else{
        cout << "Canceling Delete process ~" << endl;
    }
}

// Change the details
void Admin::Change(vector <Person*> &person, string id, string password, string name){
    for(size_t i=0;i<person.size();i++){
        if(id == person[i]->ID){
            person[i]->Password = password;
            person[i]->Name = name;
            cout << "Change Successfully!!" << endl;
            break;
        }
        if(i==person.size()-1){
            cout << id << " is a un-defined person!!" << endl;
        }
    }
}

// View the list
void Admin::View(vector <Person*> person){
    cout << "------------" << endl;
    for(size_t i=0;i<person.size();i++){
        cout << "ID: " << person[i]->ID << endl;
        cout << "Password: " << person[i]->Password << endl; 
        cout << "Name: " << person[i]->Name << endl;
        cout << "Identity: " << person[i]->Identity << endl;
        cout << "------------" << endl;
    }
    cout << endl;
}

// check admin password is right
bool Admin::check(string password){
    if(password == this->Admin_Password){
        return true;
    }
    else{
        cout << password << " is not the Correct Password!!" << endl << endl;
        return false;
    }
}