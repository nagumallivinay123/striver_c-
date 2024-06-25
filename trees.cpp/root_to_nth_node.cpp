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
//finding _last_path_in_given_nodes;
void find_path(vector<int> &ans, struct Node *node, int match, int last)
{
    if (node == NULL)
    {
        return;
    }
    last = node->data;
    if (node->data == match)
    {
        ans.push_back(match);
        return;
    }
    ans.push_back(node->data);
    find_path(ans, node->left, match, last);
    if (last == match)
    {
        return;
    }
    ans.pop_back();
    find_path(ans, node->right, match, last);
    if (last == match)
    {
        return;
    }
    ans.pop_back();
}
int main()
{

    vector<int> ans;
    struct Node *node = new Node(5);
    find_path(ans, node, match, 0);

    return 0;
}