//
// Created by IsaacHong on 2022/11/23.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_USERGROUP_H
#define STUDENT_MANAGEMENT_SYSTEM_USERGROUP_H
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "stud.h"
class blacklist {
public:
    blacklist();
    void blacklists_menu();
private:
    int level;
};

class guest {
public:
    guest();
    void menu(int);
    int select(int);
    int getLevel();
private:
    int level;
};

class user: public guest{
public:
    user();
    void menu(int);
    int select(int);
    int getLevel();
private:
    int level;
};

class admin: public user{
public:
    admin();
    void menu(int);
    int select(int);
    int getLevel();
private:
    int level;
};

#endif //STUDENT_MANAGEMENT_SYSTEM_USERGROUP_H
