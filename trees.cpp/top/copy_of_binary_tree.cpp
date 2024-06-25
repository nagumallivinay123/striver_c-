#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, TreeNode *copy)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        copy->left = new TreeNode(root->left->val);
        inorder(root->left, copy->left);
    }
    if (root->right != NULL)
    {
        copy->right = new TreeNode(root->right->val);
        inorder(root->right, copy->right);
    }
    return;
}
void inorder2(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    inorder2(root->left);
    inorder2(root->right);
}

vector<TreeNode *> make_copy_and_store(TreeNode *original, int check, vector<TreeNode *> &ans)
{

    vector<TreeNode *> temp;
    temp.push_back(NULL);
    temp.push_back(NULL);
    if (original == NULL)
    {
        temp.push_back(NULL);
        temp.push_back(NULL);
        return temp;
    }
    TreeNode *some = new TreeNode(original->val);
    ans.push_back(some);
    temp[1]=some;
    inorder(original, some);
    TreeNode *temp3 = some;
    while (temp3 != NULL)
    {
        if (temp3->val == check)
        {
            temp[1]=temp3;
            break;
        }
        else if (temp3->val > check)
        {
            temp3 = temp3->left;
        }
        else
        {
            temp3 = temp3->right;
        }
    }
    return temp;
}

void func(int start, int end, TreeNode *starts, TreeNode *to_attach, vector<TreeNode *> &ans)
{
    if (start > end)
    {
        cout<<"\n"<<"stopped "<< start<<" "<<end<<" \n";
        return;
    }
    bool count = false;
    for (int i = start; i <= end; i++)
    {
        if (to_attach == NULL)
        {
            TreeNode *some = new TreeNode(i);
            ans.push_back(some);
            cout<<some->val<<" first created "<< "\n";
            func(start, i - 1, some, some, ans);
            func(i + 1, end, some, some, ans);
        }
        else
        {
            if (count)
            {
                vector<TreeNode *> st = make_copy_and_store(starts, to_attach->val, ans);
                TreeNode *parent = st[0];
                TreeNode *to_attach_parent = st[1];
                if (i < to_attach_parent->val)
                {
                    TreeNode *some2 = new TreeNode(i);
                    to_attach_parent->left = some2;
                    cout<<"copy_created "<<some2->val<<"\n";
                    func(start, i - 1, parent, to_attach_parent->left, ans);
                    func(i + 1, end, parent, to_attach_parent, ans);
                }
                else
                {
                    TreeNode *some3 = new TreeNode(i);
                    to_attach_parent->right = some3;
                    cout<<"copy_created "<< some3->val<<"\n";
                    func(i + 1, end, parent, to_attach_parent->right, ans);
                    func(start, i - 1, parent, to_attach_parent, ans);
                }
            }

            else
            {
                if (i < to_attach->val)
                {
                    TreeNode *some2 = new TreeNode(i);
                    to_attach->left = some2;
                    cout<<to_attach->left->val<<"\n";

                    func(start, i - 1, starts, to_attach->left, ans);
                    func(i + 1, end, starts, to_attach, ans);
                }
                else
                {
                    TreeNode *some3 = new TreeNode(i);
                    to_attach->right = some3;
                    cout<<to_attach->right->val<<"\n";

                    func(i + 1, end, starts, to_attach->right, ans);
                    func(start, i - 1, starts, to_attach, ans);
                }
                count = true;
            }
        }
    }
}

int main()
{
    // vector<TreeNode *> ans;
    // func(1, 2, NULL, NULL, ans);
    // inorder2(ans[0]);
    TreeNode *original = new TreeNode(1);
    original->right = new TreeNode(3);
    original->right->left = new TreeNode(2);
    // original->right->right->right = new TreeNode(4);
    TreeNode *copy = new TreeNode(original->val);
    inorder(original, copy);
    inorder2(copy);
    // cout<<copy->left->val<<" "<<copy->right->val<<endl;

    return 0;
}