#include<iostream>
#include<fstream>
//#include "login.h"
#include "teacher.h"
#include "Admin.h"
string teacherId;
using namespace std;

void teacher::teacherOptions(string getId)
{
    string file;
    string flag;
    int choice;
    ifstream fin;
    teacherId = getId;
    file = getId;
   // teacherId = file;
    file += ".txt";
    fin.open(file.c_str(),ios::app);
    //cout<<file<<endl;
    getline(fin,flag); ///just for ignore first line
    getline(fin,flag); ///check flag
    //cout<<flag<<endl;
    if(flag == "1"){
        cout<<"\t\t\t1: check your profile"<<endl;
        cout<<"\t\t\t2: open admin depart"<<endl;
        cout<<"\t\t\t3: view courses "<<endl;
        cout<<"\t\t\t4: logout "<<endl;
        cout<<"\t\t\t";
        cin>>choice;
        while(choice < 1 || choice > 4){
        cout<<"\t\t\tsorry! you entered wrong digit. Enter again "<<endl;
        cout<<"\t\t\t";
        cin>>choice;
    }
        switch(choice)
        {
        case 1:
           viewProfile();
           break;
        case 2:
            //admin->listAdminClass();
            editAdministration();
            break;
        case 3:
            viewTeacherCourses();
            break;
        case 4:
            return;
        }
    }
    else if(flag == "0"){
        cout<<"\t\t\t1: check your profile"<<endl;
        cout<<"\t\t\t2: view courses "<<endl;
        cout<<"\t\t\t3: logout "<<endl;
        cout<<"\t\t\t";
        cin>>choice;
        while(choice < 1 || choice > 3){
        cout<<"\t\t\tsorry! you entered wrong digit. Enter again "<<endl;
        cout<<"\t\t\t";
        cin>>choice;
    }
        switch(choice)
        {
        case 1:
           viewProfile();
           break;
        case 2:
            viewTeacherCourses();
            break;
        case 3:
            return;
        }
    }
}

void teacher::editAdministration()
{
    ///open Admin class
    admin->listAdminClass();
    teacherOptions(teacherId);
}

void teacher::viewProfile()
{
    ///profile class
    string ignore;
    string data;
    string fileName = teacherId;
    fileName += ".txt";
    ifstream fin;
    fin.open(fileName.c_str(),ios::app);
    getline(fin,ignore);  ///ignore pasword
    getline(fin,ignore); ///ignore flag


    while(!fin.eof()){
        data = " ";
        getline(fin,data);
        cout<<"\t\t\t "<<data<<endl;
    }
        cout<<endl;
        teacherOptions(teacherId);
}



void teacher::viewTeacherCourses()
{
    string remain = "courses.txt";
    string fileName;
    string course;
    fileName = teacherId;
    fileName += remain;
    ifstream fin;
    fin.open(fileName.c_str(),ios::app);
    if(!fin){
        cout<<"Sorry! Error to showing courses!"<<endl;
    }
    else{
        while(!fin.eof()){

            course = " ";
            getline(fin,course);
            cout<<"\t\t\t"<<course<<endl;
        }
    }
    teacherOptions(teacherId);
}

