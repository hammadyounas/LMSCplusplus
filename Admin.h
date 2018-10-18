//#include<iostream>

#include <string>
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

/*struct admin
{
    string Name;
    string Reg_No;
    string pasword;

};*/

struct StaffStrct
{
    string name;
    string fName;
    string nicNumber;
    string department;
    string address;
};

struct teacherStruct
{
    int flag;
    string decision;
    string teacherName;
    string Reg_Id;
    string pasword;
    string subject;
    string depart;


};

struct studentStruct
{
                string Name;
                string Reg_Id;
                string pasword;
                string subject;
                string dateOfBirth;
                string depart;
                string Fname;
                string Batch;
};
class Admin//: //public login
{
protected:
    //admin* addAdmin;
            studentStruct* addStudent;
            teacherStruct* addTeacher;
            StaffStrct* addStaff;


public:
    Admin();
    //void showAdminProfile();
            void listAdminClass();
            void addAdmin();
            void addFacultyMembers();
            void addStaffMembers();
            void addStudents();
            void facultyRecord();
            void staffRecord();
            void studentsRecord();
            void removalAdmin();
            void removalStudent();
            void removalFaculty();
            void removalStaff();

};
#endif // ADMIN_H


