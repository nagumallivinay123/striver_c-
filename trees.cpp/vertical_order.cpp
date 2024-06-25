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
int main()
{
    // ela store cheyadaniki manam map and set vadukuntam
    map<int, map<int, multiset<int> > > mp;
    queue<pair<Tree *, pair<int, int> > > store_tree;
    Tree *node1 = new Tree(22);
    Tree *node2 = new Tree(10);
    Tree *node3 = new Tree(11);
    Tree *node4 = new Tree(12);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);
    // endhulo tree ki x and y axis taluka indexing echchestamu andhuke pedda problem create cheyadu
    store_tree.push(make_pair(node, make_pair(0, 0)));
    while (!store_tree.empty())
    {
        Tree *parent = store_tree.front().first;
        int level = store_tree.front().second.first;
        int vertical = store_tree.front().second.second;
        mp[vertical][level].insert(parent->data);
        store_tree.pop();
        if (parent->left != NULL)
        {
            store_tree.push(make_pair(parent->left, make_pair(level + 1, vertical - 1)));
        }
        if (parent->right != NULL)
        {
            
            store_tree.push(make_pair(parent->right, make_pair(level + 1, vertical +1)));
        }
    }
    vector<vector<int> > ans;
    map<int, map<int, multiset<int> > >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        vector<int> temp_var;
        map<int, multiset<int> >::iterator it2;
        for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
        {
            multiset<int>::iterator it3;
            for (it3 = it2->second.begin(); it3 != it2->second.end(); it3++)
            {
                temp_var.push_back(*it3);
            }
        
        }
        ans.push_back(temp_var);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "\n";
        }
    }

    return 0;
}