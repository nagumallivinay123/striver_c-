#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int vertices, vector<vector<int>> &edges, int source)
{
    vector<int> distances(vertices, 1e8);

    distances[source] = 0;
    int V=vertices;
    //bellman_ford algorithm implementation 
    for (int j = 0; j < V - 1; j++)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            if (distances[u] != 1e8 && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }
        }
    }
    //n th iteration lo
    //negative cycle unda leda testing
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        if (distances[u] != 1e8 && distances[u] + weight < distances[v])
        {
            return {-1};
        }
    }
    return distances;
}
int main(){



return 0;}