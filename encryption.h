//
// Created by IsaacHong on 2022/11/7.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_ENCRYPTION_H
#define STUDENT_MANAGEMENT_SYSTEM_ENCRYPTION_H

#include <iostream>
#include <string>
using namespace std;

//class encryption{
//private:
//    string passkey;
//public:
//    void loginMenu(); //主界面函数
//    void select(); //选择函数
//    int readFile(); //读取密码文件
//    void createPassword(); //创建密码
//    int checkPassword(); //验证密码
//    void changePassword(); //修改密码
//    void deletePassword(); //删除密码
//};

class encryption{
private:
    string passkey;
public:
    void encrypt(string&, int *); // 加密
    void decode(string&, int *); // 解密
};


#endif //STUDENT_MANAGEMENT_SYSTEM_ENCRYPTION_H
