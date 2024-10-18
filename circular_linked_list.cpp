#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{   public: 

    int data;
    node *next;

    // constructor :
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(node *&tail, int element, int data)
{

    if (tail == NULL)
    {
        node *temp = new node(data);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *new_node = new node(data);
        new_node->next = curr->next;
        curr->next = new_node;
    }
}








void deletion(node *&tail,int element){

    if(tail == NULL){
    cout<<"The list is empty , try again : "<<endl;
    return;
    }
    node *prev = tail;
    
    node *curr = tail -> next;
    
    while(curr -> data != element)
    {
        prev = curr;
     curr = curr -> next;
    }
    if(curr == prev){
    tail = NULL;
    if(curr == tail)
    return;
    }
    tail = tail -> next;

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}








void print(node *tail)
{
    node *temp = tail;
    // do
    // {
    //     cout << tail->data << " ";
    //     tail = tail->next;
    // } while (tail != temp);


    cout<<tail->data<<" ";
    tail = tail->next;

    while(tail != temp){
        cout<<tail->data<<" ";                   
        tail = tail->next;
    }
   
    cout << endl;
}

int main()
{
    node *tail = NULL;
    insert(tail, 0, 1);
    print(tail);

    insert(tail, 1, 2);
    print(tail);

    insert(tail, 2, 3);
    print(tail);

    insert(tail, 3, 4);
    print(tail);

    insert(tail,2,0);
    print(tail);

   deletion(tail,1);
   print(tail);

   deletion(tail,2);
   print(tail);

   deletion(tail,0);
   print(tail);


    return 0;
}