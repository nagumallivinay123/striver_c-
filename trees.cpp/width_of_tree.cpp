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
    Tree *node1 = new Tree(22);
    Tree *node2 = new Tree(10);
    Tree *node3 = new Tree(11);
    Tree *node4 = new Tree(12);
    Tree *node5 = new Tree(20, node3, node4);
    Tree *node6 = new Tree(13, node1, node2);
    Tree *node = new Tree(9, node6, node5);
    // breadth kavalante level order traversal chesi ,nodes ki numbering evvali ,first node ki last node ki madya difference kannukovali andhulo maximum teeste adhey ans;
    // kani nodes numbering echechetappudu overflow avuthundi danni overcome cheyadaniki manam  optimization chestam
    queue<pair<Tree *, int> > store;
    int ans = 0;
    store.push(make_pair(node,0));
    while (!store.empty())
    {
        int size_m = store.size();
        int min_m = store.front().second;
        int first, last;
        for (int i = 0; i < size_m; i++)
        {
            Tree *temp = store.front().first;
            int var = store.front().second - min_m;
            store.pop();
            if (i == 0)
            {
                first = var;
            }
            if (i == size_m - 1)
            {
                last = var;
            }
            if (temp->left != NULL)
            {
                store.push(make_pair(temp->left,var*2+1));
            }
            if (temp->right != NULL)
            {
                store.push(make_pair(temp->right, var * 2 + 2));
            }
        }
        ans = max(last - first + 1, ans);
    }
    cout << ans << "\n";
    return 0;
}