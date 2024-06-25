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
                    //         50
                    //        / \
                    //       7    2
                    //     / \    / \
                    //    3   5  1   30
                    //adhe nuvvu kinda nunchi vacchavu anuko 31+8 add cheste 39 vastundi so 50 nunchi 39 teesukuralemu 
                    //andhuku  pai nunchi ravaali 7+2<50 kabatti both side malli 50 50 
void children_sum(Tree *root){
    if(root==NULL){
        return;
    }
    int child=0;
    if(root->left){
        child+=root->left->data;
    }
    if(root->right){
        child+=root->right->data;
    }
    if(root->data<=child){
        root->data=child;
    }
    else{
        if(root->left){
            root->left->data=root->data;
        }
        if(root->right){
            root->right->data=root->data;
        }

    }
    int total=0;
    children_sum(root->left);
    children_sum(root->right);
    if(root->left){
        total+=root->left->data;
    }
    if(root->right){
        total+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data=total;

    }


}
int main(){



return 0;}