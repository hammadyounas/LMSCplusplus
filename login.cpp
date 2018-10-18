#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include "teacher.h"
#include "administrator.h"
#include "login.h"
#include "Node.h"
using namespace std;

    Node* addNode(Node* root,string temp);
    bool searchNode(Node* root,string temp);

login::login()
{

    //userName ;
    //Pasword = " ";
}

void login::getIdPasword()
{
        Pasword = "";
        string depart; // cheack depart
        char ch;
        cout<<"\n\n\t\t\tUser Name: ";
        cin>>userName;
        cout<<"\n\t\t\tPasword: ";
        //cin>>Pasword;
    while(true){
        ch = getch();
            if(ch == 13){

                break;
        }
        Pasword.push_back(ch);
        cout<<'*';

    }
    cout<<endl;
    if(userName == "admin"){
            //cout<<"check"<<endl;
        administratorClass();
       //cout<<"username"<<endl;
       //adminDepart();
    }
    if(userName.length() > 9 || userName.length() < 8){
        cout<<"\t\t\tWorng ID!"<<endl;
        getIdPasword();
    }
    //cout<<Pasword<<endl;
        if(userName.length() == 8){
            for(int i=0; i<2; i++){
                depart += userName.at(i);
    }
    }
    else if(userName.length() == 9){
    for(int i=0; i<3; i++){
        depart += userName.at(i);
    }
    }
    //cout<<depart<<endl;

    if(depart == "fc"){
        facultyDepart();
    }
    else if(depart == "cs"){
        csDepart();
    }
    else if(depart == "ee"){
        eeDepart();
    }
    else if(depart == "me"){
        meDepart();
    }
    else if(depart == "bba"){
        bbaDepart();
    }
    else{
        cout<<"\t\t\tId does not Exist!"<<endl;
        getIdPasword();
    }
}

void login::administratorClass()
{
    ///administrator();
    string pass;
    ifstream fin;
    fin.open("administrator.txt",ios::app);
    if(!fin){
        cout<<"server error"<<endl;
    }
    else{
        getline(fin,pass);
       // cout<<"password : "<<pass;
        if(pass == Pasword){
            Adminstrator->options();
            //cout<<"check"<<endl;
            getIdPasword();
        }
    }
}

void login::adminDepart()
{
    int a = 0;
    Node*   root; ///address of root
   // Node* tree;
       string tempPasword;
       string file;
        string temp;
        ifstream finId;
        ifstream finPasw;
        string id;
    //cout<<"Admin"<<endl;
    for(int i=2; i<8; i++){
        id += userName.at(i);
    }
    finId.open("admin.txt",ios::app);


        if(!finId){
            cout<<"Error!"<<endl;
    }
    else{
        while(!(finId.eof())){
                finId>>temp;
                /// first the null of root address oh root then send root address
            if(a == 0){
                root = addNode(NULL,temp);
                a += 1;
            }
             if (a==1){
                 addNode(root,temp);
            }
        }

         if(searchNode(root,id)){
                file = userName;
        file += ".txt";

            finPasw.open(file.c_str(),ios::app);  ///open file for check pasword
            getline(finPasw,tempPasword);   ///get one id from file
            if(tempPasword == Pasword){
                    //admin  class will be open
                cout<<"You have been logged in!"<<endl;
            }
            else{
                cout<<"Pasword is incorrerct!"<<endl;
                getIdPasword();
            }

        }
        else{
            cout<<"Id does not exist! Enter again"<<endl;
            getIdPasword();
        }

    }
           finPasw.close();
           finId.close();
}

void login::facultyDepart()
{
    int a = 0;
    Node*   root;
   // Node* tree;
   string tempPasword;
   string file;
   string temp;
   ifstream finId;
   ifstream finPasw;
    string id;

    for(int i=2; i<8; i++){
            id += userName.at(i);
    }


    finId.open("faculty.txt",ios::app);
        if(!finId){
                cout<<"Error!"<<endl;
    }
    else{
        while(!(finId.eof())){
            finId>>temp;
            if(a == 0){

                root = addNode(NULL,temp);
                a += 1;
            }


            else if (a==1){

                 addNode(root,temp);
            }
        }

        if(searchNode(root,id)){
                    file = userName;

        file += ".txt";

            finPasw.open(file.c_str(),ios::app);
            getline(finPasw,tempPasword);
            if(tempPasword == Pasword){
                ///faculty class will be open


                cout<<"You have been logged in!"<<endl;
                callTeacherClass->teacherOptions(userName);
                getIdPasword();
            }
            else{
                    cout<<"Pasword is incorrerct!"<<endl;
                    getIdPasword();
            }
        }
        else{
                    cout<<"Id does not exist! Enter again"<<endl;
                    getIdPasword();
        }
    }
    finId.close();
}

void login::csDepart()
{
    int a = 0;
    Node*   root;
   // Node* tree;
       string tempPasword;
       string file;
        string temp;
        ifstream finId;
        ifstream finPasw;
        string id;

    for(int i=2; i<8; i++){
        id += userName.at(i);
    }


    finId.open("cs.txt",ios::app);
    if(!finId){

        cout<<"Error!"<<endl;
    }
    else{

        while(!(finId.eof())){
            finId>>temp;
            if(a == 0){
                    root = addNode(NULL,temp);
                    a += 1;
            }
            else if (a==1){
                    addNode(root,temp);
            }
        }
        if(searchNode(root,id)){
                    file = userName;
        file += ".txt";
            finPasw.open(file.c_str(),ios::app);
            getline(finPasw,tempPasword);


            if(tempPasword == Pasword){
                //student class will be open
                callStudentClass->studentOptions(userName);
                getIdPasword();
                cout<<"You have been logged in!"<<endl;
            }
            else{
                cout<<"Pasword is incorrerct!"<<endl;
                getIdPasword();
            }
        }
        else{
            cout<<"Id does not exist! Enter again"<<endl;
            getIdPasword();
        }
    }
    finId.close();
}

void login::eeDepart()
{
    int a = 0;
    Node*   root;
   // Node* tree;
       string tempPasword;
       string file;
        string temp;
        ifstream finId;
        ifstream finPasw;
        string id;
    for(int i=2; i<8; i++){
            id += userName.at(i);
    }
    finId.open("ee.txt",ios::app);
        if(!finId){
            cout<<"Error!"<<endl;
    }
    else{

        while(!(finId.eof())){
            finId>>temp;

            if(a == 0){
                root = addNode(NULL,temp);
                a += 1;

            }
            else if (a==1){

                 addNode(root,temp);
            }
        }
        if(searchNode(root,id)){
                    file = userName;
        file += ".txt";
            finPasw.open(file.c_str(),ios::app);
            getline(finPasw,tempPasword);

        if(tempPasword == Pasword){
                //student class will be open
                callStudentClass->studentOptions(userName);
                getIdPasword();
                cout<<"You have been logged in!"<<endl;
            }
            else{
                cout<<"Pasword is incorrerct!"<<endl;
                getIdPasword();
            }
        }
        else{
            cout<<"Id does not exist! Enter again"<<endl;
            getIdPasword();
        }
    }
    finId.close();
}

void login::meDepart()
{
    int a = 0;
    Node*   root;
   // Node* tree;
       string tempPasword;
       string file;
        string temp;
        ifstream finId;
        ifstream finPasw;
        string id;
    for(int i=2; i<8; i++){
        id += userName.at(i);
    }


    finId.open("me.txt",ios::app);
    if(!finId){
        cout<<"Error!"<<endl;
    }
    else{
        while(!(finId.eof())){
            finId>>temp;
            if(a == 0){
                root = addNode(NULL,temp);
                a += 1;
                //cout<<a<<endl;
            }
            else if (a==1){
                 addNode(root,temp);
            }
        }
        if(searchNode(root,id)){
                    file = userName;
        file += ".txt";
            finPasw.open(file.c_str(),ios::app);
            getline(finPasw,tempPasword);
            if(tempPasword == Pasword){
                //student class will be open
                callStudentClass->studentOptions(userName);
                getIdPasword();
                cout<<"You have been logged in!"<<endl;
            }
            else{
                cout<<"Pasword is incorrerct!"<<endl;
                getIdPasword();


            }
        }
        else{
            cout<<"Id does not exist! Enter again"<<endl;
            getIdPasword();
        }
    }
    finId.close();
}

void login::bbaDepart()
{
    //cout<<"Check"<<endl;
    int a = 0;
    Node*   root;
   // Node* tree;
   string tempPasword = "";
   string file;
    string temp;
    ifstream finId;
    ifstream finPasw;
    string id;
    for(int i=3; i<9; i++){
        id += userName.at(i);
    }
    finId.open("bba.txt",ios::app);
    if(!finId){
        cout<<"Error!"<<endl;
    }
    else{
        while(!(finId.eof())){
            finId>>temp;
            if(a == 0){
                root = addNode(NULL,temp);
                a += 1;
            }
            else if (a==1){
                 addNode(root,temp);
            }
        }
        if(searchNode(root,id)){
                    file = userName;
        file += ".txt";

            finPasw.open(file.c_str(),ios::app);
            getline(finPasw,tempPasword);


            if(tempPasword == Pasword){
                //student class will be open
                    cout<<"Check"<<endl;
                    callStudentClass->studentOptions(userName);
                    getIdPasword();
                    cout<<"You have been logged in!"<<endl;
            }
            else{
                    cout<<"Pasword is incorrerct!"<<endl;
                    getIdPasword();
            }
        }
        else{
            cout<<"Id does not exist! Enter again"<<endl;
            getIdPasword();
        }
    }
    finId.close();
}

bool searchNode(Node* root,string temp)
{
    //int count=0;
    if(root == NULL){
        cout<<"Tree is Empty!"<<endl;
        return NULL;
    }
    while(temp < root->data && root->left != NULL){
        root = root->left;
        ///count++;

    }
    while(temp > root->data && root->right != NULL){
        root = root->right;
       /// count++;
    }
    if(temp == root->data){
    cout<<root->data<<endl;
   // cout<<count<<endl;
    return true;
    }
    else{
        return false;
    }
}

Node* addNode(Node* root, string temp)
{
    Node* newNode = new Node;
    newNode->data  = temp;
    if(root != NULL){
        if(temp < root->data && root->left == NULL){
            root->left = newNode;
        }
        else if(temp > root->data && root->right == NULL){
            root->right = newNode;
        }
        else if(temp < root->data){
            root = addNode(root->left,temp);
        }
        else if(temp > root->data){
            root = addNode(root->right,temp);
        }
    }
    //cout<<newNode->data<<endl;
    return newNode;
}
