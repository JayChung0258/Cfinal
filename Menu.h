#ifndef MENU_H
#define MENU_H

class Menu{
public:
    Menu(int n, const char * const * menu_choice);
    void view() const;
    int getUserChoice() const;
private:
    int nums;
    char **choices;
};

#endif