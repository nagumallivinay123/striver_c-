#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long depth[200001];
long long depth_distance[200001];
long long ans[200001];
void dfs(long long index, long long parent, vector<long long> tree[])
{
    long long some = 1;
    long long count = 0;
    for (auto child : tree[index])
    {
        if (child != parent)
        {
            dfs(child, index, tree);
            some += depth[child];
            count += (depth[child] + depth_distance[child]);
        }
    }
    depth_distance[index] = count;
    depth[index] = some;
    return;
}
void solve(long long index, long long parent, long long parent_ans, long long parent_nodes, vector<long long> tree[])
{
    vector<long long> prefix_count;
    vector<long long> prefix;
    vector<long long> suffix_count;
    vector<long long> suffix;
    for (auto child : tree[index])
    {
        if (child != parent)
        {
            prefix_count.push_back(depth[child]);
            suffix_count.push_back(depth[child]);
            prefix.push_back(depth_distance[child]);
            suffix.push_back(depth_distance[child]);
        }
    }
    for (long long i = 1; i < prefix.size(); i++)
    {
        prefix[i] += prefix[i - 1];
        prefix_count[i] += prefix_count[i - 1];
    }
    for (long long i = suffix.size() - 2; i >= 0; i--)
    {
        suffix[i] += suffix[i + 1];
        suffix_count[i] += suffix_count[i + 1];
    }
    long long i = 0;
    for (auto child : tree[index])
    {
        if (child != parent)
        {
            long long before = (i == 0) ? 0 : prefix[i - 1];
            long long nodes_before = (i == 0) ? 0 : prefix_count[i - 1];
            long long after = (i == ((long long)suffix.size() - 1)) ? 0 : suffix[i + 1];
            long long nodes_after = (i == ((long long)suffix_count.size() - 1)) ? 0 : suffix_count[i + 1];
            long long send_nodes = nodes_after + nodes_before + parent_nodes;
            long long send_index_ans = send_nodes + parent_ans + after + before;
            solve(child, index, send_index_ans,send_nodes +1, tree);
            i++;
        }
    }
    long long total = 0;
    for (auto child : tree[index])
    {
        if (child != parent)
        {
            total += (depth[child] + depth_distance[child]);
        }
    }
    // cout<<index<<"-> "<<parent_nodes<<"->"<<parent_ans<<"\n";
    ans[index] = parent_ans + parent_nodes + total;
    return;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> tree[n + 1];
    for (long long i = 1; i < n; i++)
    {
        long long a;
        long long b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    // first find depth of all nodes
    dfs(1, -1, tree);
    // solve it
    solve(1, -1, 0, 0, tree);

    // for(long long i=1;i<=n;i++){
    //     cout<<i<<"->  "<<depth[i]<<"-> "<<depth_distance[i]<<"\n";
    // }
    for (auto i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}