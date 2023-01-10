//
// Created by IsaacHong on 2022/11/7.
//

#include "encryption.h"
//ifstream ifss;
//ofstream ofss;
//
//map<string, string> users;

//int key[] = { 2,0,2,2,1,1,2,4 };

void encryption::encrypt(string& c, int key[]) {
    int len = c.size();
    for (int i = 0; i < len; i++) {
        c[i] = c[i] ^ key[i % 8];
    }
}

void encryption::decode(string& c, int key[]) {
    int len = c.size();
    for (int i = 0; i < len; i++) {
        c[i] = c[i] ^ key[i % 8];
    }
}

//void encryption::loginMenu() { // the login loginmenu
//    cout << endl;
//    //system("cls");
//    readFile();
//    cout<<"\t\t************************************************"<<endl;
//    cout<<"\t\t\t Login System(Made by Isaac)"<<endl;
//    cout<<"\t\t************************************************"<<endl;
//    cout<<"\t\t\t\t [1] Login"<<endl;
//    cout<<"\t\t\t\t [2] Change password"<<endl;
//    cout<<"\t\t\t\t [3] Register"<<endl;
//    cout<<"\t\t\t\t [0] Exit"<<endl;
//    cout<<"\t\t************************************************"<<endl;
//    select();
//}
//
//int encryption::readFile() { // get password from original database
//    string username;
//    string password;
//
//    ifss.open("users.txt");
//    if (ifss.is_open()) {
//        string line;
//        int count = 0;
//        while (getline(ifss, line)) // while database is not empty
//        {
//            stringstream ss(line); // ss is an object of class stringstream value is string line
//            bool erase = false; // record that whether this data is operated(if erased, no need to +=)
//            while (getline(ss, line, '#')) // from string ss to get string and store in "line" , except come up with '#'
//            {
//                stringstream ll;
//                ll << line;
//                switch (count % 2) {
//                    case 0:
//                        //v[1].push_back(line);
//                        ll >> username;
//                        decode(username, key);
//                        break;
//                    case 1:
//                        //v[2].push_back(line);
//                        ll >> password;
//                        decode(password, key);
//                        break;
//                    default:
//                        break;
//                } // store student's data to different vector (id vector , name vector ...)
//                ll.clear(); // empty stringstream's memory
//                ++count;
//            }
//            users[username] = password;
//            ss.clear(); // empty stringstream's memory
//        }
//        ifss.close();
//        return 1;
//    }
//    else{
//        //write_file();
//        ifss.close();
//        createPassword(); // original user
//        return 0;
//    }
//}
//
//void encryption::createPassword(){
//    string username;
//    string password;
//    cout << "Please enter username." << endl; cin >> username;
//
//    map<string, string>::iterator it_find;
//    it_find = users.find(username);
//    if (it_find != users.end()) {
//        cout << "[ERROR]The username is alread existed." << endl << "Enter any key back to loginmenu......" << endl;
//        cin.get();cin.get();
//        loginMenu(); // back to loginmenu
//    }
//    else{
//        cout << "Please enter password." << endl; cin >> password;
//        encrypt(username, key); // encryption
//        encrypt(password, key); // encryption
//        ofss.open("users.txt", ios::app);
//        ofss << username << "#" << password;
//        ofss << endl;
//        ofss.close();
//        cout << "Register successful." << endl << "Enter any key back to loginmenu......" << endl;
//        cin.get();cin.get();
//        loginMenu(); // back to loginmenu
//    }
//}
//
//int encryption::checkPassword(){
//    string username;
//    string password;
//    cout << "Please enter username." << endl; cin >> username;
//    cout << "Please enter password." << endl; cin >> password;
//
//    map<string, string>::iterator it_find;
//    it_find = users.find(username);
//    if (it_find != users.end() && it_find->second == password) {
//        cout << "Login successful." << endl;
//
//        if (username == "guest"){
//            guest gue;
//            while(1){
//                gue.menu(gue.getLevel());
//                gue.select(gue.getLevel());
//            }
//        }
//        else if (username == "user"){
//            user use;
//            while(1){
//                use.menu(use.getLevel());
//                use.select(use.getLevel());
//            }
//        }
//        else if (username == "admin"){
//            admin adm;
//            while(1){
//                adm.menu(adm.getLevel());
//                adm.select(adm.getLevel());
//            }
//        }
//        else {
//            blacklist bla;
//            bla.blacklists_menu();
//        }
//        return 1;
//    }
//    else {
//        cout << "[ERROR]Your password is wrong or the username isn't existed." << endl << "Enter any key back to loginmenu......" << endl;
//        cin.get();cin.get();
//        loginMenu(); // back to loginmenu
//        return 0;
//    }
//}
//
//void encryption::changePassword(){
//    string username;
//    string password;
//    cout << "Please enter the username." << endl; cin >> username;
//    cout << "Please enter the original password." << endl; cin >> password;
//
//    map<string, string>::iterator it_find;
//    it_find = users.find(username);
//    if (it_find != users.end() && it_find->second == password) { // firstly check the username and password
//        cout << "Password check successful." << endl;
//        cout << "Please enter the new password." << endl; cin >> password;
//        users[username] = password;
//        encrypt(password, key); // encryption
//        encrypt(username, key); // encryption
//        ofss.open("users.txt", ios::app);
//        ofss << username << "#" << password;
//        ofss << endl;
//        ofss.close();
//        cout << "Password change successful." << endl << "Enter any key back to loginmenu......" << endl;
//        cin.get();cin.get();
//        loginMenu(); // back to loginmenu
//        return;
//    }
//    else {
//        cout << "[ERROR]Password check failed." << endl << "Enter any key back to loginmenu......" << endl;
//        cin.get();cin.get();
//        loginMenu(); // back to loginmenu
//        return;
//    }
//
//}
//
//void encryption::select(){
//    cout << "Please enter the operation number." << endl;
//    int option = 0;
//    cin >> option;
//    switch (option) {
//        case 1:
//            checkPassword();
//            break;
//        case 2:
//            changePassword();
//            break;
//        case 3:
//            createPassword();
//            break;
//        case 0:
//            exit(0);
//        default:
//            cout << "Can not find the operation." << endl << "Enter any key back to loginmenu......" << endl;
//            cin.get();cin.get();
//            loginMenu(); // back to loginmenu
//            break;
//
//    }
//}