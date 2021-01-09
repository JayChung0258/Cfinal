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

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
}

const char* const menu_choices[] = {"Login", "Admin", "Quit"};
const char* const admin_menu_choices[] = {"Add", "Delete", "Change", "View", "Logout"};

int main(int argc, char **argv) 
{
    Menu menu(3, menu_choices);
    Menu admin_menu(5, admin_menu_choices);
    Admin admin("1234"); // Admin password default

    vector <Person*> person; 
    
    Course list;
    list.addCourse("財務管理", "D328", "琳琳明", "三234", "商管院101","3","3");
    list.printCourseList();

    Schedule schedule;
    schedule.print(2021);

    while (1)
    {
        menu.view();
        int ans = menu.getUserChoice();

        if(ans==1){
            // students or teachers
            // ...
        }
        else if (ans==2){
            // Admin
            string pw;
            cout << "Admin Password:" << endl;
            cin >> pw;
            cout << endl;
            cin.get();

            if(admin.check(pw)){
                int admin_action;
                do{
                    cout << "---Admin---" << endl;
                    admin_menu.view();
                    admin_action = admin_menu.getUserChoice();
                }while(admin.onerun(admin_action, person)); 
            }
        }
        else{
            break;
        }
    }
    return 0;
}
