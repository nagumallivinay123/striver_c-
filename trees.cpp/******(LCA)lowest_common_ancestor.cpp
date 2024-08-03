#include <iostream>
#include <bits/stdc++.h>
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

// lowest common ancestor kavalante two methods
// okati rendhu points yookka root path kannukovali
// ekkada varuku common ga undho last aadhe common rayali

// kani ekkada  lca verela chestamu
Tree *lca(Tree *node, int p, int q)
{
    if (node == NULL || node->data == p || node->data == q)
    {
        return node;
    }
    Tree *lt = lca(node->left, p, q);
    Tree *rt = lca(node->right, p, q);
    if (lt == NULL)
    {
        return rt;
    }
    else if (rt == NULL)
    {
        return lt;
    }
    //left vachcesi right 
    
        return node;
    
}

int main()
{
    // ela store cheyadaniki manam map and set vadukuntam
    
    Tree *node1 = new Tree(22);
    Tree *node2 = new Tree(10);
    Tree *node3 = new Tree(11);
    Tree *node4 = new Tree(12);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);
    // endhulo tree ki x and y axis taluka indexing echchestamu andhuke pedda problem create cheyadu
    Tree *ans=lca(node,12,11);
    cout<<ans->data<<"\n";
    return 0;
}