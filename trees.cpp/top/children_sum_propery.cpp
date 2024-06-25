#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// children sum property anteh enti left child +right child anadhi addition equal to parent avvali adheh dinni property
// edaina child/parent ni marchalante increase cheyali tappa decrease cheyakudadu  -> rule
// ala ani kinda nunchi vaste edge cases lo fail ayipothundi
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

// void childrens_sum(Tree *node)
// {
//     if (node == NULL)
//     {
//         return;
//     }
//     int parent = node->data;

//     int right_val = INT_MAX;
//     int left_val = INT_MAX;
//     if (node->right != NULL && node->left != NULL)
//     {
//         right_val = node->right->data;
//         left_val = node->left->data;

//         if (parent < right_val + left_val)
//         {
//             childrens_sum(node->left);
//             childrens_sum(node->right);
//         }
//         else
//         {
//             node->left->data = parent;
//             node->right->data = parent;
//             childrens_sum(node->left);
//             childrens_sum(node->right);
//         }

//         node->data = node->right->data + node->left->data;
//         cout<<node->data<<endl;
//     }
//     return;
// }
void childrens_sum(Tree *node)
{
    int child = 0;
    if (node == NULL)
    {
        return;
    }
    if (node->left != NULL)
    {
        child += node->left->data;
    }
    if (node->right != NULL)
    {
        child += node->right->data;
    }
    if (node->data = < child)
    {
        if (node->right != NULL)
        {
            node->right->data = node->data;
        }
        if (node->left != NULL)
        {
            node->left->data = node->data;
        }
    }
    childrens_sum(node->left);
    childrens_sum(node->right);
    int total = 0;
    if (node->right != NULL)
    {
        total += node->left->data;
    }
    if (node->left != NULL)
    {
        total += node->right->data;
    }
    node->data = total;
    return;
}
int main()
{
    Tree *node1 = new Tree(22);
    Tree *node2 = new Tree(10);
    Tree *node3 = new Tree(11);
    Tree *node4 = new Tree(12);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);
    childrens_sum(node);
    return 0;
}