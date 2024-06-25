#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int paths[50001][501];
int dp[50001][501];
int dfs(int index,int parent,int k,vector<int>tree[]){
    for(auto child:tree[index])
    {
        if(child!=parent){

        dfs(child,index,k,tree);
        }

    }
    //single node kinda 
     paths[index][0]=1;
    for(int i=1;i<=k;i++){
        //edhi ne main logic 
        for(auto child:tree[index]){
            if(child!=parent){

            paths[index][i]+=(paths[child][i-1]);
            }
        }
    }
}
void func(int index,int parent,int k,vector<int>tree[])
{
    for(int i=0;i<=k;i++){
        dp[index][i]=paths[index][i];  
    }
    if(parent!=-1)
    {
     dp[index][1]+=dp[parent][0];
     for(int i=2;i<=k;i++){
        dp[index][i]+=dp[parent][i-1];
        dp[index][i]-=paths[index][i-2];
     }

    }
    for(auto child:tree[index]){
        if(child!=parent){
            func(child,index,k,tree);
        }
    }
    return ;
  
    
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>tree[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0,-1,k,tree);
    // for(auto it:paths[0]){
    //     cout<<it<<" ";
    // }
    func(0,-1,k,tree);
    int ans=0;
     for(int i=0;i<n;i++){
      ans+=dp[i][k];
     }
    cout<< ans/2<<"\n";
    



return 0;}