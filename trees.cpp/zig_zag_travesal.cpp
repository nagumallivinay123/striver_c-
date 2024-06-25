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
//                           9
//                         /   \
//                        13    20
//                      /  \    / \
//                     22  10   11 12

int main()
{
    // zig zag traversal of tree
    // normal ga ayithe bfs lo store chesukuntaru same ekkada kuda anteh
    // bfs lo at a time oka level ve store chesukuntayi
    // cheyali
    Tree *node1 = new Tree(22);
    Tree *node2 = new Tree(10);
    Tree *node3 = new Tree(11);
    Tree *node4 = new Tree(12);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);

    // zig zig traversal
    bool zig_zag_check = true;
    queue<Tree *> store;
    store.push(node);
    vector<vector<int> > ans;
    while (!store.empty())
    {
        int size_check = store.size();
        vector<int> temp_store;
        for (int i = 0; i < size_check; i++)
        {
            Tree *child = store.front();
            store.pop();
            temp_store.push_back(child->data);
            if (child->left != NULL)
            {
                store.push(child->left);
            }
            if (child->right != NULL)
            {
                store.push(child->right);
            }
        }
        if (zig_zag_check == true)
        {
            ans.push_back(temp_store);
            zig_zag_check = false;
        }
        else
        {
            reverse(temp_store.begin(), temp_store.end());
            ans.push_back(temp_store);
            zig_zag_check = true;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j=0;j<ans[i].size();j++){

        cout << ans[i][j]<< "\n";
        }
    }

    return 0;
}