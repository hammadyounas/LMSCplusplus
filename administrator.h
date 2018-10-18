
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include<iostream>
//#include "login.h"
#include "Admin.h"
using namespace std;



class administrator: public Admin
{
public:
        Admin* admin;
   // login* log;
public:
    void options();
    void showYourProfile();
    void viewAdminsRecord();
    void editAdministration();
};
#endif // ADMINISTRATOR_H
