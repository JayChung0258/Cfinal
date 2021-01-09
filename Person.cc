#include "Person.h"
#include "Course.h"

bool Person::check(string id, string password, string identity)
{

    if (password == this->Password && id == this->ID && identity == this->Identity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Person::onerun(int choice, Course &list)
{
    bool logout = false;

    string courseName, id, time, teacher, classRoom, week, credits;

    switch (choice)
    {
    case 1:
        cout << "New course name: ";
        cin >> courseName;
        cout << "New course id: ";
        cin >> id;
        cout << "New course time: ";
        cin >> time;
        // cout << "New course teacher: ";
        // cin >> teacher;
        cout << "New course classRoom: ";
        cin >> classRoom;
        cout << "New course week: ";
        cin >> week;
        cout << "New course credits: ";
        cin >> credits;
        cin.get();
        cout << endl;

        list.addCourse(courseName, id, time, this->Name, classRoom, week, credits);
        list.printCourseList();
        break;
    case 2:
        cout << "Delete course id: ";
        cin >> id;

        //verify the teacher access
        if (list.courseVerify(id, this->Name))
        {
            list.deleteCourse(id);
            cout << "Delete successfully" << endl;
        }
        else
        {
            cout << "No access authority" << endl;
        }

        break;
    case 3:
        cout << "Change course id: ";
        cin >> id;

        //verify the teacher access
        if (list.courseVerify(id, this->Name))
        {
            list.changeCourse(id);
            cout << "change successfully" << endl;
            list.printCourseList();
        }
        else
        {
            cout << "No access authority or wrong id" << endl;
        }

        //verify the teacher access

        break;
    case 4:
        list.showAllCourse(this->Name);
        break;
    case 5:
        logout = true;
        break;
    }

    if (logout)
    {
        return false;
    }
    else
    {
        return true;
    }
}