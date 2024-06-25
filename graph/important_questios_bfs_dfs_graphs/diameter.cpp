#include<iostream>
#include<bits/stdc++.h>
vector<vector<int>>v(100);
vector<int>depth(100,0);
//finding diameter of graph
using namespace std;
void dfs(int vertex,int parent){
    for(int i=0;i<v[vertex].size();i++)
    {
        if(v[vertex][i]==parent ){
            continue;
        }
        depth[i]=1+depth[parent];
        dfs(v[vertex][i],vertex);
    }

}
int main(){
    int nodes;
    cin>>nodes;
    for(int i=0;i<nodes-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
     //first finding maximum depth of vertex;
     dfs(1,0);
     int t=0;
     int max_vertex;
     for(int i=0;i<nodes;i++){
        if(t<depth[i]){
            t=depth[i];
            max_vertex=i;
        }

        //malli depth zero chestunnamu endhukante maximum node kannukutunammu kada;
        depth[i]=0;
     }
     dfs(max_vertex,0);
     t=0;
     for(int i=0;i<nodes;i++){
        if(t<depth[i]){
            t=depth[i];
        }
     }
     cout<<t<<"\n";




return 0;}