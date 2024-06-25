#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next;
    node(){
    
    }
    node(int value){
        this->data=value;
        this->next=NULL;
    }
};
void insert_at_tail(node *parent,int data){
    node* new_thing=new node(data);
    if(parent==NULL){
        parent=new_thing;
    }
    else{
       node* temp=parent;
       while(temp->next!=NULL){
        temp=temp->next;
       }
       temp->next=new_thing;

    }
}
// star tho pattu ampersand kuda raayali endhulo
void insert_at_front(node* &parent,int data){
     node* new_thing=new node(data);
    new_thing->next=parent;
    parent=new_thing;
    return;
}
void traverese(node* &parent){
    node* temp=parent;
    while(temp->next!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
    return;
}
void deletion(node* &parent,int value){
    node *temp=parent; 
    if(temp->data==value){
        parent=parent->next;
        delete temp;
    }
    else{
    while(temp->next->data!=value){
        temp=temp->next;
    }
    node *temp2=temp->next;
    temp->next=temp->next->next;
    delete temp2;
    }
    
}
int main(){
    node *head=NULL;
    insert_at_front(head,1);
    insert_at_front(head,3);
    insert_at_front(head,5);
    insert_at_front(head,7);
    insert_at_tail(head,2);
    insert_at_tail(head,4);
    deletion(head,4);
    traverese(head);




return 0;}