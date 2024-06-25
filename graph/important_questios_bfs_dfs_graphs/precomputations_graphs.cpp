#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//even no in subtree
//summation of subtree 
//erenditiki precomputation vadali
vector<int>even_no(100,0);
vector<int>sumatation(100,0);
vector<vector<int> >v(100);
void dfs_both(int vertex,int parent)
{
    sumatation[vertex]+=vertex;
    if(vertex%2==0){
        even_no[vertex]+=1;
    }
    for(int i=0;i<v[vertex].size();i++)
    {
        if(v[vertex][i]==parent ){
            continue;
        }
    
        dfs_both(v[vertex][i],vertex);
        sumatation[vertex]+=sumatation[v[vertex][i]];
        even_no[vertex]+=even_no[v[vertex][i]];
    }

}
int main(){
    int nodes;
    cin>>nodes;
    for(int i=0;i<nodes-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);   
    }
    dfs_both(1,0);
    for(int i=1;i<=nodes;i++){
        cout<<sumatation[i]<<" "<<even_no[i]<<"\n";
    }



return 0;}