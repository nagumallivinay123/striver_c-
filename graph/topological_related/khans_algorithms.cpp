#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// khan's algorithm ->ds +navjyot sir cheppinde edhi
// topological sort cheyadanike vadatamu edhi
// kani ekkada indegree concept vadatamu
int main()
{
    int vertices, edges;
    cin >> vertices >> edges;
    // graph must be directed acyclic graph(DAG)
    vector<int> graph[vertices];
    vector<int> ans;
    vector<int> indegree(vertices, 0);
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        // counting indegree of each veritices;
        indegree[b]++;
    }

    // khans algorithm
    //ekkada dini speciality enti anteh only indegree vadi chestam
    //evi indegree zero unnayo vatini queue lo chesukuntam
    //dani taravata okaoka index in queue lo unna vatini remove chestamu
    //aa remove chesina index taluka adjacent nodes annitini group lo pe
    queue<int> store_temp;
    for (int i = 0; i < vertices; i++)
    {
        if (indegree[i] == 0)
        {
            ans.push_back(i);
            store_temp.push(i);
        }
    }
    while (!store_temp.empty())
    {
        int parent = store_temp.front();
        store_temp.pop();
        for (int i = 0; i < graph[parent].size(); i++)
        {
            int child = graph[parent][i];
            indegree[child]--;
            if (indegree[child] == 0)
            {
                ans.push_back(child);
                store_temp.push(child);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }



    return 0;
}