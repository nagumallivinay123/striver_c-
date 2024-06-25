#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// actual ga nuvvu traversal ni o(n) && space complexity o(N) lo chestavu
// morris traversal time o(N) ne kani space complexity o(1) untundi
// morris traversal anteh binary threaded pettadam
// oka root unteh daniki  left side unteh aa left side yookka right most kannukuni daniki root connection evvali .ela evvadam valla easy ga malli back ravachchu
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
 vector<int> in_order_morris(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    Node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            ans.push_back(current->data);
            current = current->right;
        }
        else
        {
            Node *left_side=current->left;
            //main logic
            while(left_side->right!=NULL && left_side->right!=current){
                  left_side=left_side->right;
            }
            if(left_side->right==NULL){
                //applying binary thread
                left_side->right=current;
                current=current->left;
            }
            else{
                ans.push_back(left_side->data);
                left_side->right=NULL;
                current=current->right;
            }
        }
    }
    return ans;
}

vector<int> pre_order_morris(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    Node *current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            ans.push_back(current->data);
            current = current->right;
        }
        else
        {
            Node *left_side=current->left;
            //main logic
            while(left_side->right!=NULL && left_side->right!=current){
                  left_side=left_side->right;
            }
            if(left_side->right==NULL){
                //applying binary thread
                ans.push_back(current->data);
                left_side->right=current;
                current=current->left;
            }
            else{
                left_side->right=NULL;
                current=current->right;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}