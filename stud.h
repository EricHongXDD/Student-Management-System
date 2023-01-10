//
// Created by IsaacHong on 2022/11/6.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_STUD_H
#define STUDENT_MANAGEMENT_SYSTEM_STUD_H

#include<iomanip>
#include <iostream>
#include <string>
#include <map>
#include<fstream>
#include "encryption.h"

using namespace std;

class student{ // student's data
private:
    string name; // student's name
    int sex; // student's gender
    string birthDay; // student's birthday
    string phoneNo; // student's phone number
public:
    long long id; // student's ID
    student(long long,string,int,string,string); // constructor
    student(); // default constructor
    ~student(); // destructor
    int outputData(); // output a student's data
    long long getID(); // get student's ID
    string getName(); // get student's name
    int getSex(); // get student's sex
    string getBirthday(); // get student's birthday
    string getPhoneNO(); // get student's phoneNO
};

// student's data's operation
class school:public encryption{
private:
    map<long long, student> stud;
public:
    int modify(long long); // modify a student's data (according to his id)
    student input(); // input a student's data
    student input(long long); // input a student's data with default id
    student input(long long,const string&,int,const string&,const string&);
    int output(); // output all students' data
    int operator+=(const student&); // add a student's data
    int operator-(long long); // delete a student's data (according to his id)
    pair<student,bool> lookup(long long); // lookup a student's data (according to his id)
    map<long long, student> getschool(); // get the school data
    int saverow(student); // save one piece of student's data (when a data is added, save is needed)
    int saveerase(long long); // when a data is erased, save is needed
    int savemodify(long long,const student&); // when a data is modified, save is needed

    int saveall(school); // save all students' data
    int backup(const string&,const string&); // backup original database to new database
    int recover(school&,string); // recover data from database (forget to use reference before XDDDD......)
};


#endif //STUDENT_MANAGEMENT_SYSTEM_STUD_H
