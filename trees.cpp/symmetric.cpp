#include <iostream>
#include <bits/stdc++.h>
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

class Solution
{
public:
    // return true/false denoting whether the tree is Symmetric or not
    bool check(struct Node *lef_t, struct Node *righ_t)
    {
        if (lef_t == NULL || righ_t == NULL)
        {
            return lef_t == righ_t;
        }
        // prati left node value ==prati right node of tree node;
        if (lef_t->data != righ_t->data)
        {
            return false;
        }
        return check(lef_t->left, righ_t->right) && check(lef_t->right, righ_t->left);
    }
    bool isSymmetric(struct Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return check(root->left, root->right);
        }
    }
};