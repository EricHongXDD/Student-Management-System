//
// Created by IsaacHong on 2022/11/23.
//

#include "usergroup.h"

school shmtu;


blacklist::blacklist():level(0){
}
guest::guest():level(1){
}
user::user():level(2){
}
admin::admin():level(3){
}

int guest::getLevel(){
    return level;
}
int user::getLevel(){
    return level;
}
int admin::getLevel(){
    return level;
}

void blacklist::blacklists_menu() {
    cout << "[WARNING]Your account was blocked. Please contact your supervisor for help." << endl;
    fflush(stdin);cin.get();
    exit(-1);
}

void guest::menu(int level) {
    cout<<"\t\t************************************************"<<endl;
    cout<<"\t\t\t Operation System(Made by Isaac)"<<endl;
    cout<<"\t\t************************************************"<<endl;
    cout<<"\t\t\t\t [1] Initialize"<<endl;
    cout<<"\t\t\t\t [2] Query"<<endl;
    if (level == 1){
        cout<<"\t\t************************************************"<<endl;
    }
}

void user::menu(int level) {
    guest::menu(level);
    cout<<"\t\t\t\t [3] Insert"<<endl;
    cout<<"\t\t\t\t [4] Delete"<<endl;
    cout<<"\t\t\t\t [5] Update"<<endl;
    cout<<"\t\t\t\t [6] Save"<<endl;
    if (level == 2){
        cout<<"\t\t************************************************"<<endl;
    }
}

void admin::menu(int level)  {
    user::menu(level);
    cout<<"\t\t\t\t [7] Display"<<endl;
    cout<<"\t\t\t\t [8] Backup"<<endl;
    cout<<"\t\t\t\t [9] Recover"<<endl;
    if (level == 3){
        cout<<"\t\t************************************************"<<endl;
    }
}

int guest::select(int level)  {
    cout << "Please enter the operation number. Enter '0' to exit this program. " << endl;
    int option = 0;
    cin >> option;
    long long id = 0;
    switch (option) {
        case 0:
            exit(0);
        case 1:
            shmtu.recover(shmtu, "data.txt");
            cout << "Initialize successful." << endl;
            return -1;
            break;
        case 2:
            cout << "Please enter the student ID that you want to search." << endl;
            cin >> id;
            shmtu.lookup(id);
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        default:
            if (level == 1){ // if enter illegal.
                cout << "Can not find the operation. Please enter again." << endl;
                select(level);
            }
            return option; // give the choice to next switch.(high level group select)
    }
}

int user::select(int level)  {
    int number; // the number of data to insert
    long long  id;
    int option = guest::select(level);
    switch (option) {
        case -1:
            return -1;
        case 3:
            cout << "Please enter the number of data to insert." << endl;
            cin >> number;
            for (int i = 0; i < number; ++i) {
                shmtu += shmtu.input();
            }
            return -1;
        case 4:
            cout << "Please enter the student ID that you want to delete." << endl;
            cin >> id;
            shmtu - id;
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        case 5:
            cout << "Please enter the student ID that you want to update." << endl;
            cin >> id;
            shmtu.modify(id);
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        case 6:
            shmtu.saveall(shmtu);
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        default:
            if (level == 2){ // if enter illegal.
                cout << "Can not find the operation. Please enter again." << endl;
                select(level);
            }
            return option; // give the choice to next switch.(high level group select)
    }
}

int admin::select(int level)  {
    string newDataBase;
    string originalDataBase;
    int option = user::select(level);
    switch (option) {
        case -1:
            return -1;
        case 7:
            shmtu.output();
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        case 8:
            cout << "Please enter the new file name that you want to backup to (Must end with .txt)." << endl;
            cin >> newDataBase;
            shmtu.backup("data.txt",newDataBase);
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        case 9:
            cout << "Please enter the original file name that you want to recover from (Must end with .txt)." << endl;
            cin >> originalDataBase;
            shmtu.recover(shmtu, originalDataBase);
            cout << "Enter any key back to operation menu......" << endl;
            fflush(stdin);cin.get();
            return -1;
        default:
            if (level == 3){ // if enter illegal.
                cout << "Can not find the operation. Please enter again." << endl;
                select(level) ;
            }
            return option;
    }
}