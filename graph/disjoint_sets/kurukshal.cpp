#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class disjoint_set
{
    vector<int> rank, parent, size;

public:
    disjoint_set(int n)
    {
        // creating rank and parent array
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            // intailga anni parents daniniki daniki heads ga la pettukuntayi
            parent[i] = i;
            // oka number untundi kabatti so size 1
            size[i] = 1;
        }
    }
    int find_ultimate_parent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = find_ultimate_parent(parent[node]);
    }
    void union_by_rank(int u, int v)
    {
        int ultimate_parent_u = find_ultimate_parent(u);
        int ultimate_parent_v = find_ultimate_parent(v);
        if (ultimate_parent_u == ultimate_parent_v)
        {
            return;
        }
        // endhuku ekkada chinna rank unna component ni pedda rank unna component ki attach chestunnam anteh time complexity taggadaniki
        if (rank[ultimate_parent_u] < rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if (rank[ultimate_parent_u] > rank[ultimate_parent_v])
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++;
        }
    }
    // similar ga union by rank chesinattu union by size kuda cheyachchu
    // union by size more intutive ga untundi compare to union by rank endhuku rank lo malli compresssion avi vastayi
    // nuvvu unionby size ne implement cheyi adhi ayithey ne correct ga vastundi

    void union_by_size(int u, int v)
    {
        int ultimate_parent_u = find_ultimate_parent(u);
        int ultimate_parent_v = find_ultimate_parent(v);
        if (ultimate_parent_u == ultimate_parent_v)
        {
            return;
        }

        if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_u] += ultimate_parent_v;
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_v] += ultimate_parent_u;
        }
    }
};
// kuruskal algorithm to find_minimum_spanning_trees
// kurukshal ki disjoint set ki relation undhi
// andhuke disjoint set therom mundu vadukunnam
// kuruksal lo mottam  first edges ni weight based sorted order lo pettukuntam
// aa taravata minimum vachche vertex ni pettukuntam
// cycle vastunda ledha detect cheyali  ->doubt vaste jenny's lecture video chudu kurukshal meeda
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < adj.size(); i++)
    {
        edges.push_back({adj[i][1], {i, adj[i][0]}});
    }
    sort(edges.begin(), edges.end());
    disjoint graph(v);
    int sum = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;
        if (graph.find_ultimate_parent(u) != graph.find_ultimate_parent(v))
        {

            graph.union_by_size(u, v);
            sum += weight;
        }
    }
    return sum;
}

int main()
{

    return 0;
}