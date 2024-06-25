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
//                           9 (0,0)
//                        /     \
//                  13(-1,1)     20(1,1)
//                    /  \         / \
//           22(-2,2) 10(0,2) 11(0,2) 12(2,2)
// -2vertical  level
// -1vertical  level
// 0 vertical  level
// 1 vertical  level
// 2 vertical  level
//right view -> kavali ante 9,20,12    ->endhulo nuvvu observe chesina logic enti anteh prati level nunchi okkate select avutundi deeniki recursion solution best 
//level order in iterative lo time waste avutundi -> prati level lo last element lo kada 
vector<int>right_view;
vector<int>left_view;
void right_seeing(Tree *node,int level){
    if(node==NULL){
        return ;
    }
    //ee chinna logic kadhu
    //
    if(right_view.size()==level){
        right_view.push_back(node->data);
    }
    right_seeing(node->right,level+1);
    right_seeing(node->left,level+1);
    return;
}
void left_seeing(Tree *node,int level){
    if(node==NULL)
    {
       return ;
    }
    if(left_view.size()==level){
        left_view.push_back(node->data);
    }
    left_seeing(node->left,level+1);
    left_seeing(node->right,level+1);
    return;
}



int main(){
 Tree *node1 = new Tree(22);
 Tree *node2 = new Tree(10);
 Tree *node3 = new Tree(11);
 Tree *node4 = new Tree(12);
 Tree *node5 = new Tree(20, node3, node4);
 Tree *node6 = new Tree(13, node1, node2);
 Tree *node = new Tree(9, node6, node5);
//right view 
right_seeing(node,0);
left_seeing(node,0);
for(int i=0;i<right_view.size();i++){
    cout<<right_view[i]<<" ";
}
cout<<"\n";
for(int i=0;i<left_view.size();i++){
    cout<<left_view[i]<<" ";
}



return 0;}