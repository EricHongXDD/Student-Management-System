//
// Created by IsaacHong on 2022/11/6.
//

#include "stud.h"
ofstream ofst;
ifstream ifst;

int key[] = { 2,0,2,1,1,0,3,1,0,2,5,2 };
string idTemp, nameTemp, sexTemp, birthdayTemp, phonenoTemp;


student::student(long long id, string name, int sex, string birthDay, string phoneNo) : id(id),name(std::move(name)),sex(sex),birthDay(std::move(birthDay)),phoneNo(std::move(phoneNo)) {
    // class student constructor
}

student::student() = default; // class student default constructor

student::~student() = default; // class student default destructor

long long student::getID(){return id;}; // get student's ID
string student::getName(){return name;}; // get student's name
int student::getSex(){return sex;}; // get student's sex
string student::getBirthday(){return birthDay;}; // get student's birthday
string student::getPhoneNO(){return phoneNo;}; // get student's phoneNO

int student::outputData(){ // get student's data
    //cout << "Student ID: " << id;
    cout << "Name: " << std::left << setw(8) << getName();
    if (getSex() == 1){ // 1 represent male
        cout << std::left << setw(14) << "Sex: male";
    }
    else{ // 0 represent female
        cout << std::left << setw(14) << "Sex: female";
    }
    cout << "Birthday: " << std::left << setw(13) << getBirthday();
    cout << "PhoneNO: " << std::left << setw(14) << getPhoneNO() << endl;
    return 1;
}

student school::input() { // input student's data
    string name, birthDay, phoneNo, sexTemp; int sex; long long id;
    cout << "input student's id:" << endl; cin >> id;
    cout << "input student's name:" << endl; cin >> name;
    cout << "input student's sex: (male or female)" << endl; cin >> sexTemp;
    if (sexTemp == "male") {
        // 1 represent male
        sex = 1;
    }
    else {
        // 0 represent female
        sex = 0;
    }
    cout << "input student's birthday:" << endl; cin >> birthDay;
    cout << "input student's phoneno:" << endl; cin >> phoneNo;
    student student(id,name,sex,birthDay,phoneNo);
    return student;
}

student school::input(long long id_default) { // input a student's data with default id
    string name, birthDay, phoneNo, sexTemp; int sex;
    cout << "input student's name:" << endl; cin >> name;
    cout << "input student's sex: (male or female)" << endl; cin >> sexTemp;
    if (sexTemp == "male") {
        // 1 represent male
        sex = 1;
    }
    else {
        // 0 represent female
        sex = 0;
    }
    cout << "input student's birthday:" << endl; cin >> birthDay;
    cout << "input student's phoneno:" << endl; cin >> phoneNo;
    student student(id_default,name,sex,birthDay,phoneNo);
    return student;
}

student school::input(long long id_default, const string& name_default, int sex_default, const string& birthDay_default, const string& phoneNo_default) { // input a student's data with default id
    student student(id_default,name_default,sex_default,birthDay_default,phoneNo_default);
    return student;
}

int school::operator+=(const student& a){ // overload += (insert one student data to school)
    // return the insertion position and whether the insertion was successful
    pair<map<long long,student>::iterator, bool> ret;
    ret = stud.insert(make_pair(a.id,a));
    if (!ret.second){ // insertion failed
        cout << "[ERROR] This student's data is already existed (id: " << a.id << ")." << endl;
        cout << "Do you want to modify his/her data? (Y/N) (default No)" << endl;
        char choice = 'N'; cin >> choice;
        switch (choice) {
            case 'y':
            case 'Y':
                this->modify(ret.first->first);
                return 0;
            default:
                cout << "Insert student's data failed. Add operation was cancelled. (id: " << a.id << ")" << endl;
                return 0;
        }
    }
    else{ // insertion success
        this->saverow(a);
        cout << "Successful insert student's data. (id: " << a.id << ")" << endl;
        return 1;
    }
    //stud[a.id] = a;
}

int school::operator-(long long id){ // overload - (delete one student data from school)
    if (stud.erase(id)){ // if success return 1, else return 0
        this->saveerase(id);
        cout << "Successful delete student's data. (id: " << id << ")" << endl;
        return 1;
    }
    else{
        cout << "[ERROR] This student's data is not exist (id: " << id << ")." << endl;
        cout << "Do you want to add his/her data? (Y/N) (default No)" << endl;
        char choice = 'N'; cin >> choice;
        switch (choice) {
            case 'y':
            case 'Y':
                *this += this->input(id);
                return 0;
            default:
                cout << "Delete student's data failed. Add operation was cancelled. (id: " << id << ")" << endl;
                return 0;
        }
    }
}

int school::modify(long long id) { // modify a student's data (according to his id)
    // 'this' argument to member function 'getData' has type 'const student', but function is not marked const
    if (lookup(id).second){
        cout << "Now modify this data ... ..." << endl;
        stud[id] = input(id);
        this->savemodify(id,stud[id]);
        cout << "Successful modify this data. (id: " << id << ")" << endl;
    }
//    else{
//        cout << "[ERROR] This student's data is not exist (id: " << id << ")." << endl;
//        cout << "Do you want to add his/her data? (Y/N) (default No)" << endl;
//        char choice = 'N'; cin >> choice;
//        switch (choice) {
//            case 'y':
//            case 'Y':
//                *this += this->input(id);
//                return 0;
//            default:
//                cout << "Modify student's data failed. Add operation was cancelled. (id: " << id << ")" << endl;
//                return 0;
//        }
//    }
    return 1;
}

int school::output(){ // output all students' data
    if (stud.empty()){ // if data is empty
        cout << "[ERROR]No data in this system. Please initialize or recover or add data." << endl;
    }
    else{
        for (auto & iter : stud) {
            // output student's id according to map stud's key
            cout << "Student ID: " << std::left << setw(15) << iter.first;
            iter.second.outputData();
        }
    }
    return 1;
}

pair<student,bool> school::lookup(long long id){ // lookup a student's data (according to his id)
    auto it_find = stud.find(id);
    if (it_find != stud.end()){
        cout << "Successful located Student ID: " << std::left << setw(15) << id << endl;
        cout << "His/Her data is: " << endl;
        it_find->second.outputData();
        return make_pair(it_find->second,true); // if find this data, student in pair point to it
    }
    else{
        cout << "[WARNING] Can not find Student ID: " << std::left << setw(15) << id << endl;
        cout << "Do you want to add his/her data? (Y/N) (default No)" << endl;
        char choice = 'N'; cin >> choice;
        switch (choice) {
            case 'y':
            case 'Y':
                *this += this->input(id);
                return make_pair(stud.end()->second,false); // if can not find this data, student in pair point to the last student's data in school
            default:
                cout << "Add operation was cancelled. (id: " << id << ")" << endl;
                return make_pair(stud.end()->second,false); // if can not find this data, student in pair point to the last student's data in school
        }
    }
}

map<long long, student> school::getschool(){
    return stud;
}

int school::saverow(student stud) {
    //ofstream ofs;
    idTemp = to_string(stud.id); nameTemp = stud.getName(); sexTemp = to_string(stud.getSex()); birthdayTemp = stud.getBirthday(); phonenoTemp = stud.getPhoneNO();
    encrypt(idTemp,key); encrypt(nameTemp,key); encrypt(sexTemp,key); encrypt(birthdayTemp,key); encrypt(phonenoTemp,key); // encryption
    ofst.open("data.txt", ios::app);
    //ofs << stud.id << "#" << stud.getName() << "#" << stud.getSex() << "#" << stud.getBirthday() << "#" << stud.getPhoneNO() << "#";
    ofst << idTemp << "#" << nameTemp << "#" << sexTemp << "#" << birthdayTemp << "#" << phonenoTemp << "#";
    ofst << endl;
    ofst.close();
    return 1;
}

int school::saveerase(long long id){
    ofst.open("data.txt", ios::app);
    idTemp = to_string(id);
    encrypt(idTemp,key); // encryption
    ofst << "~" << idTemp << "#";
    ofst << endl;
    ofst.close();
    return 1;
}

int school::savemodify(long long id, const student& stud){
    saveerase(id); // when modify, firstly erase original data
    saverow(stud); // then add new data
    return 1;
}

int school::saveall(school sch) {
    auto stud = sch.getschool();
    //ofstream ofs;
    if (stud.empty()){
        cout << "[ERROR]There is nothing to save." << endl;
        return 0;
    }
    else{
        ofst.open("data.txt", ios::trunc); // empty original data and replaced with new data
        ofst.close();
        for (auto & iter : stud) { // save all row
            saverow(iter.second);
        }
        cout << "Save all data successfully." << endl;
        return 1;
    }
}

int school::backup(const string& originalDatabase,const string& newDatabase) // backup original database to new database
{
    //ifstream ifs;
    //ofstream ofs;
    ifst.open(originalDatabase,ios::in); // open the source file
    if(ifst.fail()) // if failed to open the source file
    {
        cout<<"[ERROR][backup]: Fail to open the source file."<<endl;
        ifst.close();
        ofst.close();
        return 0;
    }
    ofst.open(newDatabase,ios::out); // create the new file
    if(ofst.fail()) // if failed to create the new file
    {
        cout<<"[ERROR][backup]: Fail to create the new file."<<endl;
        ofst.close();
        ifst.close();
        return 0;
    }
    else // start backup
    {
        auto content = ifst.rdbuf(); // get original database's streambuf
        ofst<<content; // backup original streambuf to new database
        ofst.close();
        ifst.close();
        cout << "Backup was done successfully." << endl;
        return 1;
    }
}

int school::recover(school& sch, string newDatabase) {
    bool is_original_data = false;
    if (newDatabase != "data.txt"){ // when recover from other database
        cout << "[WARNING] This operation will cover the original data. A backup is recommended. Are you sure to continue recovery? (Y/N) (default No)" << endl;
        char choice = 'N'; cin >> choice;
        switch (choice) {
            case 'y':
            case 'Y':
                break;
            default:
                cout << "Recover was cancelled." << endl;
                return 0;
        }
        cout << "Now recover data from " << newDatabase << " database ... ..." << endl;
        ofst.open("data.txt",ios::trunc); // if original existed, delete first, then recover
        ofst.close();
    }
    else{ // when recover from original database
        is_original_data = true;
        backup("data.txt","~data.txt");
        newDatabase = "~data.txt";
    }
    //ifstream ifs;
    //auto shmtu = sch;
    string line;
    long long id; // store student's id
    string name; // store student's name
    int sex; // store student's gender
    string birthDay; // store student's birthday
    string phoneNo; // store student's phone number

    ifst.open(newDatabase);
    if (ifst.is_open()) {
        int count = 0;
        while (getline(ifst, line)) // while database is not empty
        {
            stringstream ss(line); // ss is an object of class stringstream value is string line
            bool done = false; // record that whether this data is operated(if erased, no need to +=)
            while (getline(ss, line, '#')) // from string ss to get string and store in "line" , except come up with '#'
            {
                stringstream ll;
                if (line[0] == '~'){ // char "~" represents that the data needs to be deleted
                    ll << line.erase(0,1); // erase '~' from line to ensure that id is long long int
                    ll >> idTemp;
                    decode(idTemp,key); // decode
                    id = strtoll(idTemp.c_str(), nullptr, 10); // convert string to long long int
                    sch - id;
                    done = true;
                    break;
                }
                ll << line;
                switch (count % 5) {
                    case 0:
                        //v[1].push_back(line);
                        ll >> idTemp;
                        decode(idTemp,key); // decode
                        id = strtoll(idTemp.c_str(), nullptr, 10); // convert string to long long int
                        break;
                    case 1:
                        //v[2].push_back(line);
                        ll >> name;
                        break;
                    case 2:
                        //v[3].push_back(line);
                        ll >> sexTemp;
                        decode(sexTemp,key); // decode
                        sex = (int)strtoll(sexTemp.c_str(), nullptr, 10); // convert string to int
                        break;
                    case 3:
                        //v[4].push_back(line);
                        ll >> birthDay;
                        break;
                    case 4:
                        //v[5].push_back(line);
                        ll >> phoneNo;
                        break;
                    default:
                        break;
                } // store student's data to different vector (id vector , name vector ...)
                ll.clear(); // empty stringstream's memory
                ++count;
            }
            if (!done){
                decode(name,key); decode(birthDay,key); decode(phoneNo,key); // decode
                sch += sch.input(id,name,sex,birthDay,phoneNo);
            }
            ss.clear(); // empty stringstream's memory
        }
        ifst.close();

        if (is_original_data){ // erase temp(~data.txt)
            backup("~data.txt","data.txt");
            ofst.open("~data.txt",ios::trunc); // erase temp(~data.txt)
            ofst.close();
            cout << "Successful read data from original database." << endl;
            return 1;
        }

        cout << "Successful recover data from " << newDatabase << endl;
        return 1;
    }
    else{
        cout<<"[ERROR][recover]: Fail to open new database. The database may not existed in the current folder"<<endl;
        ifst.close();
        return 0;
    }
}
