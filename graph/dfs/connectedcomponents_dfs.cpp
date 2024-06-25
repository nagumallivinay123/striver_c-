#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph1[N]; // different ela ayithe kasta graph1 lo munde grap[1],graph[2]vati vertices untayi
bool vertex[N];
//connected components anteh graph lo dfs graphs lo evevi oka group ga unnayi ala  ani mata
// vertex number pampiste chalu automatic ga
// connected store cheyadaniki vector<vector>> create chestamu
// vector<vector<int> >
vector<vector<int> > connected_components;
vector<int> normal_connected_components;
void depth_first_search(int vertext)
{
    vertex[vertext] = true;
    normal_connected_components.push_back(vertext);
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
    for (int i = 1; i <= n; i++)
    {
        if (vertex[i] == true)
        {
            continue;
        }
        normal_connected_components.clear();
        depth_first_search(i);

        connected_components.push_back(normal_connected_components);
        // printing connected components
        for (int i = 0; i < connected_components.size(); i++)
        {
            for (int j = 0; j < connected_components[i].size(); j++)
            {
                cout << connected_components[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}