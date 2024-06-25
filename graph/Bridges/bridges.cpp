#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// bridges anna critical components anna rendu okkate
// bridges emitante graph lo edoka edge remove chesina aa edge ki unna rendu nodes edoka vidanga reach kakapothe , aa edges ni bridges antamu

// example kinda graph lo 4-> 5 edge remove cheste  4 emo 5 ni reach kaaledhu  so 4-5 annadi critical edge
// similar gaa 5-6,8-10;

// gfg question link  ->https://www.geeksforgeeks.org/problems/critical-connections/1
// leetcode qestion link-> https://leetcode.com/problems/critical-connections-in-a-network/submissions/
// striver explaination -> https://www.youtube.com/watch?v=qrAub5z8FeA
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
//.................
// ee graph okasari dry run cheste ardamavutundi
// timer teesukovali
int timer = 1;
void dfs(int index, int parent, vector<int> graph[], vector<int> &visited, vector<int> &insert_time, vector<int> &low_time, vector<vector<int>> &ans)
{
    visited[index] = 1;
    // intial gaa insert time mariyu low time same gaane untayi
    insert_time[index] = low_time[index] = timer;
    timer++;
    for (auto child : graph[index])
    {
        if (child != parent)
        {
            if (visited[child] == -1)
            {
                dfs(child, index, graph, visited, insert_time, low_time, ans);
                low_time[index] = min(low_time[child], low_time[index]);
                // main logic edhe
                // anteh deeni meaning children ni vere node nunchi kalavachchu ani dani ardaam
                if (insert_time[index] < low_time[child])
                {
                    // cout<<index<<"\n";
                    ans.push_back({min(index, child), max(index, child)});
                }
            }
            else
            {
                // visit chesindi already visit cheste  dani minimum time nuvvu teesuko
                // dani ardam cycle undani
                low_time[index] = min(low_time[index], low_time[child]);
            }
        }
    }

    return;
}
vector<vector<int>> criticalConnections(int v, vector<int> adj[])
{
    // Code here
    vector<vector<int>> ans;
    vector<int> insert_time(v, -1);
    vector<int> low_time(v, INT_MAX);
    vector<int> visited(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == -1)
        {
            dfs(i, -1, adj, visited, insert_time, low_time, ans);
        }
    }
    // cout << insert_time[9] << " " << low_time[10] << " ";
    sort(ans.begin(), ans.end());
    return ans;
}
// input
//  12 14
//  1 2
//  1 4
//  2 3
//  4 3
//  4 5
//  5 6
//  6 7
//  6 9
//  7 8
//  9 8
//  8 10
//  10 11
//  10 12
//  11 12

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
    auto output = criticalConnections(n, adj);
    cout << "criticalConnections: \n";
    for (auto it : output)
    {
        cout << it[0] + 1 << " " << it[1] + 1 << endl;
    }

    return 0;
}