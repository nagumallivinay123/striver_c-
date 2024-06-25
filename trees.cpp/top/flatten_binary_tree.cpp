#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
    Tree(int value, Tree *left_side, Tree *right_side)
    {
        this->data = value;
        this->left = left_side;
        this->right = right_side;
    }
};
//approach 2 o(N) and space complexity o(N);
Tree *flatten_binary_tree_into_linked_list(Tree *root){
    if(root==NULL){
        return NULL;
    }
    stack<Tree* >store;
    store.push(root);
    while(!store.empty())
    {
        Tree *current=store.top();
        store.pop();
        if(current->right){
            store.push(current->right);
        }
        if(current->left){
            store.push(current->left);
        }
       if(!store.empty()){
        current->right=store.top();
       }
       current->left=NULL;

    }
}
int main(){



return 0;}