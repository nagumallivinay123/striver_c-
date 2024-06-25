#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// gfg problem link -> https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// striver solution link -> https://www.youtube.com/watch?v=R6uoSjZ2imo

//****strongly connected components anteh -> directed graph lone vastayi

// main idea vachchesariki  echchina graph lo edges direction reverse chesi enni dfs vestemo anni connected components unnattu kani
class Solution
{
public:
    // Function to find number of strongly connected components in the graph.
    void dfs(int index, vector<int> adj[], vector<int> &visited, stack<int> &store)
    {
        visited[index] = 1;
        for (int i = 0; i < adj[index].size(); i++)
        {
            int child = adj[index][i];
            if (visited[child] == 0)
            {
                dfs(child, adj, visited, store);
            }
        }
        store.push(index);
    }
    void dfs3(int index, vector<int> adjc[], vector<int> &visited)
    {
        visited[index] = 1;
        for (int i = 0; i < adjc[index].size(); i++)
        {
            int child = adjc[index][i];
            if (visited[child] == 0)
            {
                dfs3(child, adjc, visited);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[])
    { // V -> no of vertices;
        vector<int> visited(V, 0);
        // store first finishing dfs traversal
        // ela endhuku cheyali anteh ela cheyakunda cheste -> simple gaa reverse chesi dfs edoka node nunchi start chesavu anuko kachchitange konni cases lo fail ayithe

        stack<int> store;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, adj, visited, store);
            }
        }
        // reversing edges and creating new matrix
        vector<int> adjc[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto it : adj[i])
            {
                adjc[it].push_back(i);
            }
        }
        // intialising the strongly connected componetns =0
        int scc = 0;
        while (!store.empty())
        {
            int temp = store.top();
            store.pop();
            if (visited[temp] == 0)
            {
                scc++;
                dfs3(temp, adjc, visited);
            }
        }
        return scc;
    }
};
int main()
{

    return 0;
}