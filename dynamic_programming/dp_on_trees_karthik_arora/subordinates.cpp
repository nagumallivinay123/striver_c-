//problem link 
//https://cses.fi/problemset/task/1674/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve_dfs_dp(int index,int parent,vector<int>tree[],vector<int>&ans){
    int count=0;
  for(auto child:tree[index]){
   if(child!=parent){
    solve_dfs_dp(child,index,tree,ans);
    count+=(1+ans[child]);
   }
  }
  ans[index]=count;
  return;

}
int main(){
    int n;
    cin>>n;
    vector<int>tree[n+1];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);

    }
    vector<int>ans(n+1,0);
    solve_dfs_dp(1,-1,tree,ans);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }



return 0;}