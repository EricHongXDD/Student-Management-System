//
// Created by IsaacHong on 2022/11/25.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_LOGINMENU_H
#define STUDENT_MANAGEMENT_SYSTEM_LOGINMENU_H

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "usergroup.h"
using namespace std;

class loginmenu:public encryption{
private:
    string passkey;
public:
    void loginMenu(); //主界面函数
    void select(); //选择函数
    int readFile(); //读取密码文件
    void createPassword(); //创建密码
    int checkPassword(); //验证密码
    void changePassword(); //修改密码
    //void adminMenu(); // admin menu
};


#endif //STUDENT_MANAGEMENT_SYSTEM_LOGINMENU_H
