#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Admin.h"
#include "Person.h"
#include "Course.h"
#include "Schedule.h"

using namespace std;

extern "C"
{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

const char *const menu_choices[] = {"Login", "Admin", "Quit"};
const char *const admin_menu_choices[] = {"Add", "Delete", "Change", "View", "Logout"};
const char *const teacher_menu_choices[] = {"Add", "Delete", "Change", "All", "Logout"};

int main(int argc, char **argv)
{
    Menu menu(3, menu_choices);
    Menu admin_menu(5, admin_menu_choices);
    Menu teacher_menu(5, teacher_menu_choices);
    Admin admin("1234"); // Admin password default

    vector<Person *> person;

    Course list;
    list.addCourse("財務管理", "D328", "三234", "琳琳明", "商管院101", "3", "3");
    list.printCourseList();

    Schedule schedule;
    // schedule.print(2021);

    while (1)
    {
        menu.view();
        int ans = menu.getUserChoice();

        if (ans == 1)
        {
            //Teacher
            string id;
            string pw;
            string identity;
            cout << "Teacher Id:" << endl;
            cin >> id;
            cout << "Teacher Password:" << endl;
            cin >> pw;
            cout << "Identity:" << endl;
            cin >> identity;
            cout << endl;
            cin.get();

            vector<Person *>::iterator begin = person.begin();
            vector<Person *>::iterator end = person.end();
            vector<Person *>::iterator it;
            for (it = begin; it != end; it++)
            {
                // log in successfully
                if ((*it)->check(id, pw, identity))
                {
                    int teacher_action;
                    do
                    {
                        cout << "---Teacher---" << endl;
                        teacher_menu.view();
                        teacher_action = teacher_menu.getUserChoice();
                    } while ((*it)->onerun(teacher_action, list));
                }
            }
        }
        else if (ans == 2)
        {
            // Admin
            string pw;
            cout << "Admin Password:" << endl;
            cin >> pw;
            cout << endl;
            cin.get();

            if (admin.check(pw))
            {
                int admin_action;
                do
                {
                    cout << "---Admin---" << endl;
                    admin_menu.view();
                    admin_action = admin_menu.getUserChoice();
                } while (admin.onerun(admin_action, person));
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}
