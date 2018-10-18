#include<iostream>
//#include "login.h"
#include "Admin.h"
using namespace std;

#ifndef TEACHER_H
#define TEACHER_H

class teacher : public Admin
{
public:
    Admin* admin;
    //string teacherId;
    string course;
public:
    void teacherOptions(string getId);
    void editAdministration();
    void viewProfile();
    void viewTeacherCourses();
};
#endif // TEACHER_H
