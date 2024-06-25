#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int depth[200001];
int ans[200001];
void dfs(int index,int parent,vector<int>tree[]){
    int ans=0;
    for(auto child:tree[index]){
        if(child!=parent){
            dfs(child,index,tree);
            ans=max(ans,1+depth[child]);
        }
    }
     depth[index]=ans;
     return;
}
void solve(int index,int parent,int parent_ans,vector<int>tree[])
{
   vector<int>prefix;
   vector<int>suffix;
   for(auto child:tree[index]){
    if(child!=parent){
        prefix.push_back(depth[child]);
        suffix.push_back(depth[child]);
    }
   }
   for(int i=1;i<prefix.size();i++){
    prefix[i]=max(prefix[i-1],prefix[i]);
   }
   for(int i=suffix.size()-2;i>=0;i--){
    suffix[i]=max(suffix[i+1],suffix[i]);
   }
   int i=0;
   for(auto child:tree[index]){
    if(child!=parent){
        int before=(i==0)?INT_MIN:prefix[i-1];
        int after= (i==(int)suffix.size()-1)?INT_MIN:suffix[i+1];
        int send_index_ans=max(parent_ans,max(before,after));
        solve(child,index,send_index_ans+1,tree);
        i++;
    }
    
   }
    ans[index]=1+max(parent_ans,prefix.empty()?-1:prefix.back());
    return;

}
int main(){
    int n;
    cin>>n;
    vector<int>tree[n+1];
    for(int i=1;i<n;i++){
        int a;
        int b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //first find depth of all nodes
   dfs(1,-1,tree); 
    //solve it
    solve(1,-1,-1,tree);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
   
    



return 0;}