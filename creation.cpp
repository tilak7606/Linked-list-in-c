#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor :
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


int main()
{
    node *hero = new node(0);     // node create ki aur using constructor usme value dal di : 
  
    return 0;
}