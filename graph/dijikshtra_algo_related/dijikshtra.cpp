#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 2;
const int n = 1e3;
// 1st-Approach
// edhi priority_queue vadi chesinadi
//time complexity for dijikshtra algorithm is ElogV E->edges V->vertices ]
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // min heap kavalante kastam priority queue lo anduke ee problem
    // ekkada adj matrix ela echcha
    // adj[i]->some vector t ayithe
    // t[0]=node t[1]=distance between i & node;
    // danibattirasindi le;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> store;
    vector<int> distance(V, 0);
    for (int i = 0; i < V; i++)
    {
        distance[i] = 1e9;
    }
    distance[S] = 0;
    store.push({0, S});
    while (!store.empty())
    {
        int parent = store.top().second;
        int dist = store.top().first;
        store.pop();
        for (auto itr : adj[parent])
        {
            int side_node = itr[0];
            int weight = itr[1];
            if (distance[side_node] > weight + dist)
            {
                distance[side_node] = weight + dist;
                store.push({weight + dist, side_node});
            }
        }
    }
    return distance;
}
// Second->Approach
//set approach 
//set ki priority_queue ki pedda difference undadu konni sarulu priority_queue best kavachchu konisarulu set best kavachchu

vector<int> dijkstra_2(int V, vector<vector<int>> adj[], int S)
{
    // min heap kavalante kastam priority queue lo anduke ee problem
    // ekkada adj matrix ela echcha
    // adj[i]->some vector t ayithe
    // t[0]=node t[1]=distance between i & node;
    // danibattirasindi le;
    set<pair<int, int>> store;
    vector<int> distance(V, 0);
    for (int i = 0; i < V; i++)
    {
        distance[i] = 1e9;
    }
    distance[S] = 0;
    store.insert({0, S});
    while (!store.empty())
    {
        auto something = *(store.begin());
        int parent = something.second;
        int dist = something.first;
        store.erase(something);
        for (auto itr : adj[parent])
        {
            int side_node = itr[0];
            int weight = itr[1];
            if (distance[side_node] > weight + dist)
            {
                if (distance[side_node] != 1e9)
                {
                    store.erase({distance[side_node], side_node});
                }
                distance[side_node] = weight + dist;
                store.insert({weight + dist, side_node});
            }
        }
    }
    return distance;
}
int main()
{
    // priority queu indefault max_heap form chestundi
    // priority queue min heap_kavalante syntax marchali
    // gfg refer priority queue rasetappudu
    // priority_queue ekkadaa minimum distance find cheyadaniki rastunammu
    // same priority_queue lane set kuda vadukovachcchu
    // set lo automatic dani antata adhe minimum distance unna element mundu pettestundi

//complexity of dijikstar is Elog(v); E->edges,V->vertices;
//example emi teesukoni chestavante Mesh_graph teesukuni cheste telustadi ->hypotetical graph adhi


    return 0;
}