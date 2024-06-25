#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph1[N];//different ela ayithe kasta graph1 lo munde grap[1],graph[2]vati vertices untayi
bool vertex[N];
// vertex number pampiste chalu automatic ga
void depth_first_search(int vertext)
{
    vertex[vertext] = true;
    cout<<vertext<<endl;
    for (int i = 0; i < graph1[vertext].size(); i++)
    {
        if (vertex[graph1[vertext][i]] == true)
        {
            continue;
        }
        depth_first_search(graph1[vertext][i]);
    }
}

int main()
{

    int n, m;
    cin >> n >> m; // vertices and edges data lo teeskutamu;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph1[v1].push_back(v2);
        graph1[v2].push_back(v1);
    }
    depth_first_search(1);

    return 0;
}