#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// prims algorithm eppudu least value echche spanning three find out chestundi
// vati yokka edges sum cheste least value ravali aa vidaga
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int sum = 0;
    // priority queue endhukante minimum weight unna edges find cheyadaniki
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> store;
    // munduga emi vertices visit kaledhu ani pettukuntam
    vector<int> visited(V, 0);
    //<distance,node>->pettukuntam
    store.push({0, 0});

    while (!store.empty())
    {
        int parent = store.top().second;
        int dist = store.top().first;
        store.pop();
        // okavela visit ayipoyamu anuko pettukomu
        if (visited[parent] == 1)
        {
            continue;
        }
        // visit kakapothe answer lo pettukuntam
        visited[parent] = 1;
        sum += dist;
        for (auto it : adj[parent])
        {
            int child = it[0];
            int weight = it[1];
            if (visited[child] == 0)
            {
                store.push({weight, child});
            }
        }
    }
    return sum;
}
int main()
{
    int edges, vertices;
    cin >> edges >> vertices;
    vector<vector<int>> adj[vertices];
    for (int i = 0; i < edges; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        vector<int> temp;
        temp.push_back(b);
        temp.push_back(weight);
        vector<int> temp2;
        temp2.push_back(a);
        temp2.push_back(weight);
        adj[a].push_back(temp);
        adj[b].push_back(temp2);
    }
return spanningTree(vertices,adj);
    return 0;
    //time complexity is ELogE  
}