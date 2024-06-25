
#include<iostream>
#include<bits/stdc++.h>
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
Node *find_target(Node *root, unordered_map<Node *, Node *> &parent, int target)
{
    Node *targeted;
    queue<Node *> store;
    store.push(root);
    parent[root] = NULL;
    while (!store.empty())
    {
        int n = store.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = store.front();
            store.pop();
            if (temp->data == target)
            {
                targeted = temp;
            }
            if (temp->left != NULL)
            {
                parent[temp->left] = temp;
                store.push(temp->left);
            }
            if (temp->right != NULL)
            {
                parent[temp->right] = temp;
                store.push(temp->right);
            }
        }
    }
    return targeted;
}
class Solution
{
public:
    int minTime(Node *root, int target)
    {
        // Your code goes here
        unordered_map<Node *, Node *> parent;
        unordered_map<Node *, int> visited;
        Node *target_node = find_target(root, parent, target);
        int maxi = INT_MIN;
        visited[target_node] = 0;
        queue<Node *> store;
        store.push(target_node);
        while (!store.empty())
        {
            int n = store.size();
            for (int i = 0; i < n; i++)
            {
                Node *temp = store.front();
                maxi = max(visited[temp], maxi);
                store.pop();
                if (parent[temp] != NULL && visited.find(parent[temp]) == visited.end())
                {
                    visited[parent[temp]] = visited[temp] + 1;
                    store.push(parent[temp]);
                }
                if (temp->left != NULL && visited.find(temp->left) == visited.end())
                {
                    visited[temp->left] = visited[temp] + 1;
                    store.push(temp->left);
                }
                if (temp->right != NULL && visited.find(temp->right) == visited.end())
                {
                    visited[temp->right] = visited[temp] + 1;
                    store.push(temp->right);
                }
            }
        }
        return maxi;
    }
};


int main(){



return 0;}