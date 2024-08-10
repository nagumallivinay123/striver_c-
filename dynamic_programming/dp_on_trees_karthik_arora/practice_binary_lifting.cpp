#include<bits/stdc++.h>
using namespace std;

//for based on graphs   
void dfs(int index,int parent,vector<int>&parents,vetor<int>adj[],vetor<int>&level){

    if(parent!=-1){
       level[index]=level[parent]+1;
       parents[index]=parent;
    }
    for(auto child:adj[index]){
        if(child!=parent){
            dfs(child,index,parent,parents,adj,level);
        }
    }
}
//2 power 20 power at max unnayi anuko 
void binary_lifting(int N,vector<int>&parents ,vector<vector<int>>&binary_lifted_parents)
{
    //binary lifted parents lo binary_lifted_parents[i][index] i node ki 2power index lo ee parent undhi 
    for(int i=1;i<=N;i++){
        binary_lifted_parents[i][0]=parents[i];
    }
    for(int i=1;i<=19;i++){
        for(int j=1;j<=N;j++)
        {
            // prati parent ki 
            //j node ki index lo e parent 
            //suppose index is 4 ayithe  

            //  parent[node]{16}=parent[parent{8}]{8}
            //parent[node][4]=parent[parent[node][3]][3];
            //parent[node][index]=parent[parent[node][index-1]][index-1];
            binary_lifted_parents[j][i]=binary_lifted_parents[binary_lifted_parents[j][i-1]][i-1];

        }
    }

}

int above(int index,int diff,vector<vector<int>>&binary_lifted_parents)
{
    if(index==-1){
        return -1;
    }
    int some=diff;
    int count=0;
    while(some>0){
        if(some&1==1){
          return above(binary_lifted_parents[index][count],diff-(count<<1),binary_lifted_parents);
        }
        count++;
    }
    return index;//diff==0 ayithe 
}
int lca(int u,int v,vector<vector<int>>&binary_lifted_parents,vector<int>&level){
    //first u,v dhi level equal chesukovali 
    int diff=abs(level[u]-level[v]);
    if(diff>0){
        if(level[u]>level[v]){
          u=above(u,diff,binary_lifted_parents);
        }
        else{
            v=above(v,diff,binary_lifted_parents);
        }
    }
    //edhi m
   for(int i=19;i>=0;i--){
    if(binary_lifted_parents[u][i]!=binary_lifted_parents[v][i]){
        //uppudu u and v ni marcheyali 
        u=binary_lifted_parents[u][i];
        v=binary_lifted_parents[v][i];
    }
   }
   //just above level 
   return binary_lifted_parents[u][0];
}
int main(){
return 0;
}