#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// neeku target node okati estadu daniki k distances lo anni nodes nuvvu print cheyali se
// normal graph lo ayithe easy kani trees lo parent vaipu unna node vaipu ela velathavu
// andhuke visited  okati ,parent ane rendhu maps teesukuni cheyali
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
void find_parents(Tree *root, unordered_map<Tree *, Tree *> &parent)
{
    if (node == NULL)
    {
        return;
    }
    queue<Tree *> store;
    store.push(root);
    while (!store.empty())
    {
        Tree *node = store.front();
        store.pop();
        if (node->left != NULL)
        {
            parent[node->left] = node;
            store.push(node->left);
        }
        if (node->right != NULL)
        {
            parent[node->right] = node;
            store.push(node->right);
        }
    }
    return ;
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
    // map of parents
    unordered_map<Tree *, Tree *> parent;
    find_parents(node, parent);

    return 0;
}