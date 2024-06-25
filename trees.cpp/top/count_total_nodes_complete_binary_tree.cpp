#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int countNodes(Node *root){
    if(root == NULL){
        return 0;
    }
    int left_height=leftHeight(Node *root);
    int right_height=rightHeight(Node *root);
    if(left_height==right_height){
        return (1<<right_height)-1;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}
int leftHeight(Node *root){
    if(root==NULL){
        return 0;
    }
    Node *point_root=root;
    int ans=0;
    while(point_root!=NULL){
        ans=ans+1;
        point_root=point_root->left;
    }
    return ans;
}
int rightHeight(Node *root){
    if(root==NULL){
        return 0;
    }
    Node *point_root=root;
    int ans=0;
    while(point_root!=NULL){
        ans=ans+1;
        point_root=point_root->right;
    }
    return ans;
}
int main(){





    return 0;
}