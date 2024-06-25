#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int timer = 1;
// articulation point anteh -> aa graph lo aa point remove cheste atleast(remaining nodes lo ) okka node ayina
//   vere node  ki reach kakudadu
// starting node ki multiple children unnaru anuko kachchitanga aa starting node articulation point avutundi

// idhi kuda same logic of critical points but slight variation
// striver video link -> https://www.youtube.com/watch?v=j1QDfU21iZk

// // example graph 1-> 2
//                  |   |
//                  4-> 3
//................. |
//................. 5-> 6
//.................    /  \
//.................   7    9
//.................    \.  /
//.................      8
//.................       \
//.................        10
//.................       /  \
//.................      11-> 12

void dfs(int start_node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &mark_articulation_points, vector<int> &low_time, vector<int> &insert_time)
{
    visited[start_node] = 1;
    low_time[start_node] = insert_time[start_node] = timer;
    timer++;
    int count = 0;
    for (auto child : adj[start_node])
    {
        if (child != parent)
        {
            if (visited[child] == 0)
            {
                dfs(child, start_node, adj, visited, mark_articulation_points, low_time, insert_time);
                // logic -1
                low_time[start_node] = min(low_time[start_node], low_time[child]);
                // ekkada kuda chinna variation untundi
                // edhi emi chebutante okavela childnode onko vidam gaa takkuva time lo vachchesta problem emi undadu
                if (insert_time[start_node] <= low_time[child] && parent != -1)
                {
                    mark_articulation_points[start_node] = 1;
                }
                count++;
            }
            else
            {
                // logic -2
                // edhi koddiga variation  untundi  insert_time of child tho endhuku chestamu anteh edhi akkada nunchi start ayyindo
                low_time[start_node] = min(low_time[start_node], insert_time[child]);
            }
        }
    }
    // edhi
    // logic -3

    if (count > 1 && parent == -1)
    {
        mark_articulation_points[start_node] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> low_time(V, INT_MAX);
    vector<int> insert_time(V, 0);
    vector<int> mark_articulation_points(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, -1, adj, visited, mark_articulation_points, low_time, insert_time);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (mark_articulation_points[i] == 1)
        {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)
    {
        return {-1};
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto it = articulationPoints(n, adj);
    for (auto ans : it)
    {
        cout << ans + 1 << " ";
    }

    return 0;
}