#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// time complexity of disjoint _set opertaion o(4*alpha)
// alpha derivation chala kastam anta

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
int main()
{
    disjoint_set graph(7);
    graph.union_by_size(1, 2);
    graph.union_by_size(2, 3);
    graph.union_by_size(4, 5);
    graph.union_by_size(6, 7);
    graph.union_by_size(5, 6);
    if (graph.find_ultimate_parent(3) == graph.find_ultimate_parent(7))
    {
        cout << "they related to same graph"
             << "\n";
    }
    else
    {
        cout << "NO "
             << "\n";
    }
    graph.union_by_size(3, 7);

        return 0;
}