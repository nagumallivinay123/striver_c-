#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class tree_node(){
    public:
    int data;
    tree_node * right;
    tree_node * left;
    tree_node(int value){
        this->data=0;
        this->right=NULL;
        this->left=NULL;
    }
    tree_node(int value){
        this->data=value;
        this->right=NULL;
        this->left=NULL;
    }
    tree_node(int value,tree_node *left_t,tree_node *right_t){
        this->data=value;
        this->left=left_t;
        this->right=right_t;
    }
}
int maxdepth(Tree_node *parent){
    if(parent==NULL){
        return 0;
    }
    int left=maxdepth(parent->left);
    int right=maxdepth(parent->right);
    return 1+max(left,right);
}

int main(){
    
    



return 0;}