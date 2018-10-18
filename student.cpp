
#include<iostream>
#include "student.h"
#include <fstream>
string studentId;
//#include "login.h"
using namespace std;

void student::studentOptions(string getId)
{
    int choice;
    studentId = getId;
    cout<<"\t\t\t1: Show courses "<<endl;
    cout<<"\t\t\t2: Show profile "<<endl;
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
        StudentCourses();
        break;
    case 2:
        StudentProfile();
        break;
    case 3:
       return;
        //break;
    }
}

void student::StudentCourses()
{
    string remain = "courses.txt";
    string fileName;
    string course;
    fileName = studentId;
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
    studentOptions(studentId);
}

void student::StudentProfile()
{
            string ignore; ///ignore pasword
            string data;
            string fileName = studentId;
            fileName += ".txt";
            ifstream fin;

    fin.open(fileName.c_str(),ios::app);
    getline(fin,ignore);


    while(!fin.eof()){
        data = " ";
        getline(fin,data);
        cout<<"\t\t\t "<<data<<endl;
    }


    cout<<endl;
    studentOptions(studentId);
}
