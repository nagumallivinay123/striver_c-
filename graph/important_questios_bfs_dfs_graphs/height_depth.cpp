#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//edhi height of parent findout cheyadaniki matrame
vector<int>depth(100,0);
vector<int>height(100,0);
vector<vector<int>>v(100);
void dfs(int vertex,int parent){

    for(int i=0;i<v[vertex].size();i++){
        if(v[vertex][i]==parent){
            continue;
        }
        depth[i]=depth[parent]+1;
        dfs(v[vertex][i],vertex);
        height[vertex]=max(height[vertex],1+height[v[vertex][i]]);
    }
}
int main(){
int t;
cin>>t;
int n=t+1;
for(int i=0;i<t;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
for(int i=0;i<=t;i++)
{
        cout<<"height"<<height[i]<<"depth"<<depth[i]<<"\n";
}






return 0;}