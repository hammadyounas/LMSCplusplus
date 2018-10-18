#include<iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

struct Node
{
    string data;
    Node* left = NULL;
    Node* right = NULL;
};
#endif // NODE_H
