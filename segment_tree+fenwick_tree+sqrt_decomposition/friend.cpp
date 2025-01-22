#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp;

long long maximize(int start_node, int k, vector<vector<int>> &mat, vector<vector<int>> &adj)
{
    int n = mat.size();
    dp.assign(n, vector<long long>(k, -1));

    queue<tuple<int, int, long long>> q; // {node, day, current enjoyment}
    for (int i = 0; i < n; ++i)
    {
        q.emplace(i, 0, mat[i][0]);
        dp[i][0] = mat[i][0];
    }

    long long max_enjoyment = 0;

    while (!q.empty())
    {
        auto [node, day, enjoyment] = q.front();
        q.pop();

        if (day == k - 1)
        {
            max_enjoyment = max(max_enjoyment, enjoyment);
            continue;
        }

        for (int neighbor : adj[node])
        {
            long long new_enjoyment = enjoyment + mat[neighbor][day + 1];
            if (new_enjoyment > dp[neighbor][day + 1])
            {
                dp[neighbor][day + 1] = new_enjoyment;
                q.emplace(neighbor, day + 1, new_enjoyment);
            }
        }
    }

    return max_enjoyment;
}

long long GetMaximumEnjoyment(int n, int m, int h, int k, vector<vector<int>> edges, vector<vector<int>> mat)
{
    vector<vector<int>> adj(n);

    for (const auto &edge : edges)
    {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return maximize(0, k, mat, adj);
}
int main(){
 int n=4;
 int m=3;
 int h=2;
 int k=2;
 vector<vector<int>>e={
    {4,3},{1,2},{2,3}
 };
 vector<vector<int>>f={{3,4},{10,2},{30,1},{4,9}};
 cout<<GetMaximumEnjoyment(n,m,h,k,e,f)<<endl;


return 0;
}