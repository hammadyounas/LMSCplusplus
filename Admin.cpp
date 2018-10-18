#include "Admin.h"
#include<iostream>
#include<fstream>
#include <string>

Admin::Admin()
{
    //admin->Name = NULL;
    //admin->pasword = NULL;
    //admin->Reg_No = NULL;
}

void Admin::listAdminClass()
{
    int choice;
    cout<<"\t\t1: add admin "<<endl;
    cout<<"\t\t2: faculty members "<<endl;
    cout<<"\t\t3: add staff members "<<endl;
    cout<<"\t\t4: add student "<<endl;
    cout<<"\t\t5: faculty record "<<endl;
    cout<<"\t\t6: staff record "<<endl;
    cout<<"\t\t7: students record "<<endl;
    cout<<"\t\t8: removal admin "<<endl;
    cout<<"\t\t9: removal faculty "<<endl;
    cout<<"\t\t10: removal staff "<<endl;
    cout<<"\t\t11: removal student "<<endl;
    cout<<"\t\t12: back to the class"<<endl;
    cout<<"\t\t";
    cin>>choice;
    while(choice < 1 || choice > 12){
        cout<<"\t\tyou entered wrong digit!"<<endl;
        cout<<"\t\tEnter again "<<endl;
        cout<<"\t\t";
        cin>>choice;
    }


        switch(choice)
        {
        case 1:
            addAdmin();
            break;
        case 2:
            addFacultyMembers();
            break;
        case 3:
            addStaffMembers();
        case 4:
            addStudents();
            break;
        case 5:
            facultyRecord();
            break;
        case 6:
            staffRecord();
            break;
        case 7:
            studentsRecord();
            break;
        case 8:
            removalAdmin();
            break;
        case 9:
            removalFaculty();
            break;
        case 10:
            removalStaff();
            break;
        case 11:
            removalStudent();
            break;
        case 12:
            //login::getIdPasword();
            return;
        //break;
    }
}

void Admin::addAdmin()
{
    string adminId;  ///take id for make new admin
    string data;  ///hold file data
    string check = "";
    cout<<"\t\t\tEnter Admin Id: "<<endl;
    cout<<"\t\t\t";
    cin>>adminId;
    for(int i=0; i<2; i++){
        check += adminId.at(i);    ///take depart for example cs ee me
    }
    //cout<<check<<endl;
    if(check != "fc"){    ///id should faculty members
    while(check != "fc"){
        cout<<"\t\t\tYou entered wrong id!\n\t\t\tEnter again"<<endl;
        cout<<"\t\t\t";
        cin>>adminId;
        for(int i=2; i<8; i++){
        check += adminId.at(i);    ///take depart for example cs ee me
    }
    }
    }
    adminId += ".txt";
    //cout<<adminId<<endl;
    /// check id then delete id form file
    if(check == "fc"){
         fstream fin,fout;
         fin.open(adminId.c_str(),ios::app);
         fout.open("temp.txt",ios::out);
         while(!fin.eof()){
                //cout<<"check"<<endl;
            getline(fin,data);
            cout<<data<<endl;
            if(data == "1"){
                //cout<<"check"<<endl;
                fout<<"0"<<endl;
            }
            else if(data != "1"){
                fout<<data<<endl;
            }
         }
        fin.clear(); ///clear record from file
    fin.seekg(0,ios::beg);
    fin.close(); ///close record file
    fout.close(); ///close temp file
        if(remove(adminId.c_str())!= 0){

        }
        else{
        rename("temp.txt", adminId.c_str());
        }

    }
    else if(check != "fc"){
        cout<<"admin does not exist"<<endl;
    }

}

void Admin::addFacultyMembers()
{
    string temp;
    teacherStruct s;
    cout<<"\n\t\t\t Enter Teacher Name: ";
    cin>>s.teacherName;
    cout<<"\n\t\t\t Enter registration id: ";
    cin>>s.Reg_Id;
    cout<<"\n\t\t\tEnter pasword : ";
    cin>>s.pasword;
    cout<<"\n\t\t\t Enter Depart: ";
    cin>>s.depart;
    cout<<"\n\t\t\tDo you want to make him admin yes/no: ";
    cin>>s.decision;
    if(s.decision == "yes"){
        s.flag = 1;
    }
    else if(s.decision == "no"){
        s.flag = 0;
    }

}

void Admin::addStaffMembers()
{

}

void Admin::addStudents()
{
            string add;
            string check;
            string temp;
            string hold = "";
            string id;


    studentStruct s;

    cout<<"Enter student's Name: ";
    //getline(cin,s.Name);
    cin>>s.Name;
    cin.ignore();
            cout<<"\nEnter student father's name : ";
            getline(cin,s.Fname);
            cout<<"\nEnter student's Date of Birth : ";
            getline(cin,s.dateOfBirth);
            cout<<"\nEnter student's registration id : ";
            getline(cin,s.Reg_Id);
            cout<<"\nEnter student's password : ";
            getline(cin,s.pasword);
            cout<<"\nEnter student's department : ";
            getline(cin,s.depart);
             cout<<"\nEnter Student's batch : ";
            getline(cin,s.Batch);

    temp = s.Reg_Id;
    hold = s.Reg_Id;
    temp += ".txt";
    ofstream fout;
    fout.open(temp.c_str(),ios::app);
    fout<<s.pasword<<endl;
    fout<<s.Name<<endl;
    fout<<s.Fname<<endl;
    fout<<s.dateOfBirth<<endl;
    fout<<s.depart<<endl;
    fout<<s.Batch<<endl;

    if(s.Reg_Id.length() == 8)
{
        for(int i=0; i<2; i++){

                add += s.Reg_Id.at(i);

    }

    for(int i=2; i<8; i++){
        id += s.Reg_Id.at(i);
    }

}
    else if(s.Reg_Id.length() == 9)
{
        for(int i=0; i<3; i++){
                add += s.Reg_Id.at(i);
    }
    for(int i=3; i<9; i++){
        id += s.Reg_Id.at(i);
    }

}

    ofstream write;

    if(add == "cs")
    {
            add += ".txt";
            write.open(add.c_str(),ios::app);
            write<<id<<endl;
            write.close();
    }

    else if(add == "ee")
    {
        add += ".txt";
        write.open(add.c_str(),ios::app);
        write<<id<<endl;
        write.close();
    }


    else if(add == "me")
    {
        add += ".txt";
        write.open(add.c_str(),ios::app);
        write<<id<<endl;
        write.close();
    }

    else if(add == "bba")
    {
        add += ".txt";
        write.open(add.c_str(),ios::app);
        write<<id<<endl;
        write.close();
    }

    hold += "courses.txt";
    ofstream fileout;


    fileout.open(hold.c_str(),ios::out);
    do{
            cout<<"\t\t\tEnter Course name:"<<endl;
            cout<<"\t\t\t";
            cin>>s.subject;
            cout<<endl;
            fout<<s.subject<<endl;
            cout<<"\t\t\t Enter more subjects yes/no ? "<<endl;
            cout<<"\t\t\t";
            cin>>check;
    } while(check != "no");

            fout.close();
}

void Admin::facultyRecord()
{
    ///remove
}

void Admin::staffRecord()
{
    ///remove
}

void Admin::studentsRecord()
{
        string depart;
        string id;
        cout<<"\t\t\tEnter Depart: ";
        cin>>depart;
        cout<<endl;
        depart += ".txt";
        ifstream fin;

    fin.open(depart.c_str(),ios::app);

    while(!fin.eof())
    {
        getline(fin,id);
        cout<<"\t\t\t "<<id<<endl;
    }

    cout<<endl;
}

void Admin::removalAdmin()
{
            string adminId;
            string data;  ///hold file data
            string check = "";
            cout<<"\t\t\tEnter Admin Id: "<<endl;
            cout<<"\t\t\t";
            cin>>adminId;

    for(int i=0; i<2; i++){
        check += adminId.at(i);
    }
        cout<<check<<endl;


    if(check != "fc"){
        while(check != "fc")
 {
                cout<<"\t\t\tYou entered wrong id!\n\t\t\tEnter again"<<endl;
                cout<<"\t\t\t";
                cin>>adminId;


        for(int i=2; i<8; i++){
                check += adminId.at(i);
    }
 }
    }
    adminId += ".txt";
    //cout<<adminId<<endl;
    if(check == "fc"){
             fstream fin,fout;
             fin.open(adminId.c_str(),ios::app);
             fout.open("temp.txt",ios::out);


         while(!fin.eof()){
                //cout<<"check"<<endl;
                getline(fin,data);
                cout<<data<<endl;
            if(data == "1"){

                fout<<"0"<<endl;
            }
            else if(data != "1"){
                fout<<data<<endl;
            }
         }
    fin.clear(); ///clear record from file
    fin.seekg(0,ios::beg);
    fin.close(); ///close record file
    fout.close(); ///close temp file


        if(remove(adminId.c_str())!= 0){

        }
        else
        {
                rename("temp.txt", adminId.c_str());
        }

    }

    else if(check != "fc"){
            cout<<"admin does not exist"<<endl;
    }
}

void Admin::removalFaculty()
{
        string fileName;
        string stuId;
        cout<<"\n\t\t\tEnter faculty Id: ";
        cin>>stuId;
        fileName = stuId;
        fileName += ".txt";


    if(remove(fileName.c_str())!= 0){
        cout<<"faculty member Does not exist!"<<endl;
    }


    else{
        cout<<"faculty member has been removed"<<endl;
    }
}

void Admin::removalStaff()
{

}

void Admin::removalStudent()
{
    string depart;
    string rollNo;
    string fileName;
    string stuId;
    string srchId;

    int f=0;
    cout<<"\n\t\t\tEnter Student Id: ";
    cin>>stuId;


    fileName = stuId;
    fileName += ".txt";
        if(remove(fileName.c_str())!= 0){
                cout<<"Student Does not exist!"<<endl;
    }
    else{

        if(stuId.length() == 8){
            for(int i=0; i<2; i++){
                depart += stuId.at(i);
    }
    for(int i=2; i<8; i++){
            rollNo += stuId.at(i);
    }
    }

        else if(stuId.length() == 9){
            for(int i=0; i<3; i++){
                    depart += stuId.at(i);
    }
    for(int i=3; i<8; i++){
            rollNo += stuId.at(i);
    }
    }


            cout<<depart<<endl;
            depart += ".txt";
            ifstream fin;
            ofstream fout;

    fin.open(depart.c_str(),ios::app);
    fout.open("temp.txt",ios::out);

    if(!fin){

        cout<<"Error "<<endl;
    }
    f=0;

    while(!fin.eof()){
        getline(fin,srchId);
        if(srchId == rollNo){
            f = 1;
        }
        else{
            fout<<srchId<<endl;
        }

    }
            fin.clear(); ///clear record from file
            fin.seekg(0,ios::beg);
            fin.close(); ///close record file
            fout.close(); ///close temp file

    if(f == 0 ){
        //cout<<"Sorry You Entered Wrong Data.";
    }
    else{

        if(remove(depart.c_str())!= 0){

        }

            else{
                rename("temp.txt", depart.c_str());
        }
    }
    cout<<"Student has been removed"<<endl;
    }
}
