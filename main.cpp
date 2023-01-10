#include "stud.h"
#include "savedata.h"
#include "usergroup.h"
#include "encryption.h"
#include "loginmenu.h"
int main() {
//    school shmtu;
//    savedata save;

//    for (int i = 0; i < 2; ++i) {
//        shmtu += shmtu.input();
//    }
//    shmtu - 202110310195;
//    shmtu.modify(20211031025);
//    shmtu.lookup(2414); shmtu.lookup(202110310252);
//    shmtu.output();
//    save.saveall(shmtu);
//    save.backup("data.txt","backup.txt");
//    shmtu.output();

//    save.recover(shmtu, "data.txt");
//    shmtu.output();
//    save.backup("data.txt","backup2.txt");

//    shmtu.modify(202110313242);
//    shmtu.output();

//    save.saveall(shmtu);
    loginmenu begin;
while (1){
//    admin adm;
//    guest gue;
//    adm.loginmenu(adm.getLevel());
//    adm.select(adm.getLevel());
//    cout << adm.getLevel();
//    adm.loginmenu( adm.getLevel());
//    adm.select(adm.getLevel());
    begin.loginMenu();
    begin.select();
}
    return 0;
}
