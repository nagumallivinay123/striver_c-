#include <iostream>
#include <bits/stdc++.h>
using namespace std;

///  problem link -> https://codeforces.com/problemset/problem/1927/F
// disjoint usage example
class disjoint
{
    vector<int> parent, size;

public:
    disjoint(int n)
    {
        parent.resize(n, 0);
        size.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_ultimate_parent(int a)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find_ultimate_parent(parent[a]);
    }
    void union_by_size(int u, int v)
    {
        int parent_u = find_ultimate_parent(u);
        int parent_v = find_ultimate_parent(v);
        if (parent_u == parent_v)
        {
            return;
        }
        if (size[parent_u] == size[parent_v])
        {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        }
        else if (size[parent_u] > size[parent_v])
        {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        }
        else
        {
            size[parent_v] += size[parent_u];
            parent[parent_u] = parent_v;
        }
    }
};
int dfs(int start, int parent, int final, vector<int> graph[], int &n, vector<int> &store)
{
    if (start == final)
    {

        return 1;
    }
    int ans = n + 3;
    int temp = -1;
    for (auto child : graph[start])
    {
        if (child != parent)
        {
            int val = 1 + dfs(child, start, final, graph, n, store);
            if (ans > val)
            {
                temp = child;
                ans = val;
            }
        }
    }
    if (temp != -1)
    {
        // cout << temp << " ";
        store.push_back(temp);
    }
    return ans;
}
bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first > b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second.first < b.second.first)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    vector<pair<int, pair<int, int>>> edges;
    disjoint g(n);
    int best_start = -1;
    int best_end = -1;
    int best_weight = -1;
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({weight, {u - 1, v - 1}});
    }
    sort(edges.begin(), edges.end(), comp);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;
        // cout << u << " " << v << " " << weight << "\n";
        if (g.find_ultimate_parent(u) == g.find_ultimate_parent(v))
        {
            best_start = u;
            best_end = v;
            best_weight = weight;
        }
        else
        {
            g.union_by_size(u, v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    vector<int> ans;
    int val = dfs(best_start, -1, best_end, graph, n, ans);
    cout << best_weight << " " << val << "\n";
    ans.push_back(best_start);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] + 1 << " ";
    }
}
int main()
{
    // mana question emitante echchina graph lo shortest edge unna cycle path kaavali
    // procedures edges annitini descending order lo sort cheyi

    // aa taravata edge chestappudu cycle form avutunda leda ani check cheyali
    //  ala form ayithe least edge cycle form ayyela chusukovali
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}