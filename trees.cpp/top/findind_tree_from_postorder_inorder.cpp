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
Node *function(vector<int> &in_order, int instart, int inend, vector<int> &post_order, int post_start, int post_end,map<int, int> &inorder_map)
{
    if (instart > inend || post_start > post_end)
    {
        return NULL;
    }
    //post order lo last element root kabatti  
    Node *child = new Node(post_order[post_end]);
    int position = inorder_map[post_order[post_end]];
    int length = position - instart;
    child->left = function(in_order, instart, position - 1, post_order, post_start , post_start + length-1, inorder_map);
    child->right = function(in_order, position + 1, inend,post_order, post_start+length,  post_end-1, inorder_map);
    return child;
}
Node *build_tree(vector<int> &post_order, vector<int> &in_order)
{
    map<int, int> in_order_map;
    for (int i = 0; i < in_order.size(); i++)
    {
        in_order_map[in_order[i]] = i;
    }


    Node *root = function(in_order, 0, in_order.size()-1, post_order, 0, post_order.size()-1, in_order_map);
    return root;
}


    int main()
{
    return 0;
}