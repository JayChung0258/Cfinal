#include <cassert>
#include <string>
#include <iostream>
#include "Menu.h"

using namespace std;

extern "C" {
extern char *strdup(const char *);
}

Menu::Menu(int n, const char * const * menu_choice) {
    assert(n>=0);
    nums=n;
    choices = new char *[nums];
    for(int i=0; i<nums; i++) {
        choices[i]=strdup(menu_choice[i]);
    }
}

void 
Menu::view() const {
    for(int i=0;i<nums;i++) {
        cout << "[" << i+1 << "] " << choices[i] << "  ";
    }
    cout << endl;
}

int 
Menu::getUserChoice() const {

    int ans=0;
    string input;

    do {
        cout << " Enter: ";
        getline(cin, input);
        ans = atoi(input.c_str());   
    }while((ans<=0)||(ans>nums));

    cout << endl;
    return ans;
}

