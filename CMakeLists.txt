cmake_minimum_required(VERSION 3.20)
project(Student_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Student_Management_System main.cpp stud.cpp stud.h encryption.cpp encryption.h savedata.cpp savedata.h usergroup.cpp usergroup.h loginmenu.cpp loginmenu.h)
