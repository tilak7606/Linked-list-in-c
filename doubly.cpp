#include <iostream>
#include <bits/stdc++.h>
using namespace std;






class node
{
public:
    int data;
    node *next;
    node *prev;

    // constructor :
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};







void count_length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    cout << "The count is = " << count << endl;
}






void insert_at_head(node *&head,node *&tail, int val)
{   
    // if list is empty : 
    if(head == NULL){
        node *temp = new node(val);
        head = temp;
        tail = temp;
    }
    else{
    node *temp = new node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
}





void insert_at_tail(node *&tail, node *&head,int val){

    // if list is empty : 
    if(tail == NULL){
        node *temp = new node(val);
        tail = temp ;
        head = temp;
    }
    else{
    node *temp = new node(val);

    tail -> next = temp;
    temp -> prev = tail ;
    tail = temp;
    }
}






void insert_at_index(node *&head,node *&tail, int data, int pos){
    if(pos == 1){
        insert_at_head(head,tail,data);            // head , tail, data : 
        return ;
    }
    node *temp=  new node(data);
    node *p = head;


    int cnt =  1;
    while(cnt < pos - 1){
        p = p -> next;
        cnt++;
    }

    if(p -> next == NULL){
        insert_at_tail(tail,head,data);
        return ;
    }

    temp -> next = p -> next;
    p->next->prev = temp;
    temp -> prev = p;
    p -> next = temp;



}






void delete_at_head(node *&head){
    if(head == NULL)        // Empty list : 
    return;           
    else if(head -> next == NULL){    //  only one element in the list : 
        delete head;
        return;
    }
    else{
        node *temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
}









void delete_at_index(node *&head,node *&tail,int pos){
    if(pos == 1){
    delete_at_head(head);
    return;
    }
    node *p = head;
    int cnt = 1;
    node *temp = NULL;
    while(cnt < pos){
        temp = p;
        p=  p -> next;
        cnt++;
    }
    if(p -> next == NULL){
         p -> prev = NULL;
    temp -> next = p-> next;
    p -> next = NULL;
    tail = temp;
    delete p;
    }
    else{
    p -> prev = NULL;
    temp -> next = p-> next;
    p -> next = NULL;
    delete p;
    }
    

}






void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}







int main()
{
    node *head = new node(10);
    node *tail = head;
    // node *head = NULL;
    // node *tail = NULL;

    print(head);
    count_length(head);

    insert_at_head(head,tail, 9);
    print(head);
    count_length(head);

    insert_at_head(head, tail,8);
    print(head);
    count_length(head);

    insert_at_tail(tail,head,11);
    print(head);
    count_length(head);

    insert_at_tail(tail,head,12);
    print(head);
    count_length(head);

    insert_at_index(head, tail, 0, 2);          //head , tail , data , position : 
    print(head);
    count_length(head);
    
    insert_at_index(head,tail,-1,1);
    print(head);
    count_length(head); 

       
    insert_at_index(head,tail,-2,1);
    print(head);
    count_length(head); 
       
    insert_at_index(head,tail,13,9);
    print(head);
    count_length(head); 

    delete_at_head(head);
    print(head);
    count_length(head); 

    delete_at_index(head,tail,2);
    print(head);
    count_length(head); 

    delete_at_index(head,tail,7);
    print(head);
    count_length(head); 
    
    cout<<tail->data<<endl;


    return 0;
}