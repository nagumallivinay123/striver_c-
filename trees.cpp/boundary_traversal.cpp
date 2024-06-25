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

//                            9
//                          /   \
//                         13    20
//                       /  \    / \
//                      22  10   11 12
//                      /     \   /  / \
//                    20      3  5  15  14
//                     \      /\
//                     5     1  2

void left_boundary(Tree *temp, vector<int> &store)
{
    Tree *node = temp->left;
    while (node != NULL)
    {
        if (node->left != NULL || node->right != NULL)
        {
            store.push_back(node->data);
        }
        if (node->left != NULL)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return;
}
void leaf_nodes(Tree *something, vector<int> &store)
{
    if (something == NULL)
    {
        return;
    }
    if (something->left == NULL && something->right == NULL)
    {
        store.push_back(something->data);
    }
    leaf_nodes(something->left, store);
    leaf_nodes(something->right, store);
}
void right_boundary(Tree *something, vector<int> &store)
{
    vector<int> temp;
    Tree *node = something->right;
    while (node != NULL)
    {
        if (node->right != NULL || node->left != NULL)
        {
            temp.push_back(node->data);
        }
        if (node->right != NULL)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    reverse(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        store.push_back(temp[i]);
    }
}

int main()
{
    Tree *some = new  Tree(1);
    Tree *some2 = new Tree(2);
    Tree *some3 = new Tree(3, some, some2);
    Tree *vin2 = new Tree(5);
    Tree *vinadd1 = new  Tree(20, NULL, vin2);
    Tree *node1 = new Tree(22, vinadd1, NULL);
    Tree *node2 = new Tree(10);
    Tree *sow3 = new Tree(5);
    Tree *node3 = new Tree(11, sow3, NULL);
    Tree *suda1 = new Tree(15);
    Tree *suda2 = new Tree(14);
    Tree *node4 = new Tree(12, suda1, suda2);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);
    // traversing in boundary order
    // left boundary
    // leaf nodes
    // right boundary
    vector<int> store_ans;
    if (node == NULL)
    {
        return 0;
    }
    else if (node->right == NULL && node->left == NULL)
    {
        cout << node->data << "\n";
        return 0;
    }
    else
    {
        store_ans.push_back(node->data);
        left_boundary(node, store_ans);
        leaf_nodes(node, store_ans);
        right_boundary(node, store_ans);
        for(int i=0;i<store_ans.size();i++)
        {
            cout<<store_ans[i]<<"\n";

        }
    }

    return 0;
}