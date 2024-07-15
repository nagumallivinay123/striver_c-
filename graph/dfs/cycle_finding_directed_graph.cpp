#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check_dfs(int index,vector<int>&visited,vector<int>&path_visited,vector<int>adj[]){
        visited[index]=1;
        path_visited[index]=1;
        for(auto child:adj[index]){
            if(visited[child]==0){
                if(check_dfs(child,visited,path_visited,adj)==true){
                    return true;
                }
            }
            else if(visited[child]==1 &&path_visited[child]==1){
                return true;
            }
        }
        path_visited[index]=0;
        return false;
        
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>visited(V,0);
       vector<int>path_visited(V,0);
       for(int i=0;i<V;i++){
           if(visited[i]==0){
               if(check_dfs(i,visited,path_visited,adj)==true){
                   return true;
               }
           }
       }
       return false;
    }
};
int main(){
return 0;
}