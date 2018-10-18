#include<iostream>
#include "Admin.h"
#include "administrator.h"
#include <fstream>

//#include "login.h"
using namespace std;

void administrator::options()
{
    ///show administrator optsions
    int choice;
    cout<<"\t\t\t1: Edit administration "<<endl;
    cout<<"\t\t\t2: Show profile "<<endl;
    cout<<"\t\t\t3: logout "<<endl;
    cin>>choice;
    while(choice < 1 || choice > 4){

        cout<<"\t\t\tsorry! you entered wrong digit. Enter again "<<endl;
        cin>>choice;
    }
            switch(choice)
        {
            case 1:
                editAdministration();
                break;
            case 2:
                showYourProfile();
            case 3:
               // log->getIdPasword();
               return;
        //break;
        }
}

void administrator::editAdministration()
{
    ///EditAdmin class
    admin->listAdminClass();
    options();
}


void administrator::showYourProfile()
{
    string ignore; ///ignore pasword
    string data;
    string fileName = "admin";
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
        options();
}
