#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//topological sort gurinchi navjyot sir chepparu alane,jenny's lecture vi kuda chusavu
//topological sort endhulo chestam main ga-> directed acyclic graphs lo mains chestam ,
//topological sort -> edhi anteh enti ->okavela (DAG) graph lo u and v ani edge unte u annadi mundu order ravali tarvata v annadi ravali ->e order lo mottam vertices oka array lo store cheste adhe topological sort.


//MAIN ALGORITM 
void dfs(int index,vector<int>graph[],vector<int>&visited,stack<int>&ans){
    visited[index]=1;
    for(int i=0;i<graph[index].size();i++){
        int child=graph[index][i];
       if(visited[child]==0){
        dfs(child,graph,visited,ans);
       }
    }
    ans.push(index); 
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    //graph must be directed acyclic graph(DAG)
    vector<int>graph[vertices];
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    //MAIN ALGORITHM;
    vector<int>visited(vertices,0);
    stack<int>store_ans;
    for(int i=0;i<vertices;i++){
        if(visited[i]==0){
            dfs(i,graph,visited,store_ans);

        }
    }
    while(!store_ans.empty()){
        cout<<store_ans.top()<<" ";
        store_ans.pop();
    }
    




return 0;}