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
    //vector<int> ans;
    int count=0;
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
            store_temp.push(i);
        }
    }
    //manam gaa careful ga obsever cheste ->okavela directed cyclic graph gani avvakapothe appudu count indegree zero ayyevi (mean khan's algorithm upiyoginchi cheste )cheste less than no of vertices vastayi 
//
    while (!store_temp.empty())
    {
        int parent = store_temp.front();
        store_temp.pop();
        count++;
        for (int i = 0; i < graph[parent].size(); i++)
        {
            int child = graph[parent][i];
            indegree[child]--;
            if (indegree[child] == 0)
            {
                store_temp.push(child);
            }
        }
    }
  if(count==vertices){
    cout<<"it has no cycles"<<"\n";
  }
  else{
    cout<<"it contains cycles"<<"\n";
  }


    return 0;
}