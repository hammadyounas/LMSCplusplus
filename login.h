#ifndef LOGIN_H
#define LOGIN_H

//#include<iostream>
#include "administrator.h"
#include "teacher.h"
#include "student.h"
using namespace std;




class login: public administrator , public teacher,public student
{
protected:

        teacher* callTeacherClass;
        student* callStudentClass;
        administrator* Adminstrator;
        string userName;
        string Pasword;
    //Node* data;

public:
    login();
    //void show();
        void administratorClass();
        void getIdPasword();
        void adminDepart();
        void facultyDepart();
        void csDepart();
        void eeDepart();
        void meDepart();
        void bbaDepart();
};
#endif // LOGIN_H
