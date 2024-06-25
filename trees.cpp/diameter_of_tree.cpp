#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max_diameter=0;
class Tree 
{
    int data;
    Tree *left;
    Tree *right;
    public:
    Tree(int value){
      this->data=value;
      this->left=NULL;
      this->right=NULL;
    }
    Tree(int value,Tree *left_side,Tree *right_side){
        this->data=value;
        this->left=left_side;
        this->right=right_side;
    }
}
//malli diameter anteh doubt vastundi kada 
//daimeter anteh oka node nunchi onko node ki max distance tree mottam lo undedi 
int diameter(Tree *parent){
    if(parent==NULL){
        return 0;
    }
    int left=diameter(parent->left);
    int right=diameter(parent->right);
    max_diameter=max(max_diameter,left+right);
    return 1+max(left,right);
}
int main(){


return 0;}
