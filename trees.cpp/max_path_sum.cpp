#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int global_max_path_sum=INT_MIN;
//maximum ee path lo vastundi kannukovali 
class Tree
{
    public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int value){
        this->data=value;
        this->left=this->right=NULL;
    }
    Tree(int value,Tree *some_l,Tree *some_r){
        this->data=value;
        this->left=some_l;
        this->right=some_r;
    }

};
//max_path kannukovvadam ela
//either tree ki left nunchi ayina vellavachcha,right nuchi ayina vellavachchu so aa rendhitiki lo edhi max unte adhe route follow avutham

//same logic as height of tree lagga strive cheppadu 
int max_path_sum(Tree *parent){
    if(parent==NULL){
        return 0;
    }
   int left_t=max(0,max_path_sum(parent->left));
   int right_t=max(0,max_path_sum(parent->right));
   global_max_path_sum=max(global_max_path_sum,parent->data+left_t+right_t);
   return parent->data+max(left_t,right_t);
// }
//          12
//         /  \
//       -10    -11



//                    15
//                   /  \
//                  10   20
//                       /  \
//                      -30  -35
}
int main(){
Tree *node1=new Tree(-11);
Tree *node2=new Tree(-10);
Tree *node=new Tree(12,node2,node1);
cout<<max_path_sum(node)<<"\n";





return 0;}