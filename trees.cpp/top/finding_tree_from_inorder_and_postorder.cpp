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
Node *function(vector<int> &ino_order, int instart, int inend, vector<int> &preorder, int prestart, int preend, map<int, int> &inorder_map)
{
    if (instart > inend || prestart > prend)
    {
        return NULL;
    }
    Node *child = new Node(preorder[prestart]);
    int position = inorder_map[preorder[prestart]];
    int length = position - instart;
    child->left = function(in_order, instart, position - 1, preorder, prestart + 1, prestart + length, inorder_map);
    child->right = function(in_order, position + 1, inend, preorder, prestart + length + 1, preend, inorder_map);
    return child;
}
Node *build_tree(vector<int> &preorder, vector<int> &in_order)
{
    map<int, int> in_order_map;
    for (int i = 0; i < in_order.size(); i++)
    {
        in_order_map[in_order[i]] = i;
    }

    int inStart = 0 int inEnd = in_order.size() - 1;
    int preStart = 0;
    int preEnd = preorder.size() - 1;
    Node *root = function(in_order, inStart, inEnd, preorder, preStart, preEnd, in_order_map);
    return root;
}


    int main()
{
    return 0;
}