#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// manam ekkada lowest common ancestor find chestunnamu
// dani kosamu emi chestam

vector<int> parent(100);
vector<vector<int>> v(100);
void dfs_parent(int vertex, int parent_t)
{
    parent[vertex] = parent_t;
    for (int i = 0; i < v[vertex].size(); i++)
    {
        if (v[vertex][i] == parent_t)
        {
            continue;
        }
        dfs_parent(v[vertex][i], vertex);
    }
}
vector<int> path(int x)
{
    vector<int> vi;
    int p = parent[x];
    while (p != 0)
    {
        vi.push_back(p);
        p = parent[p];
    }
    reverse(vi.begin(), vi.end());
    return vi;
}
int main()
{
    int nodes;
    cin >> nodes;
    for (int i = 0; i < nodes - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    int one_node, two_node;
    cin >> one_node >> two_node;
    vector<int> pat1 = path(one_node);
    vector<int> pat2 = path(two_node);
    int n = min(pat1.size(), pat2.size()) for (int i = 0; i < n; i++)
    {
        if (pat1[i] == pat2[i])
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return 0;
}