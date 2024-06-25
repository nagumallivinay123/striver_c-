//graphs is collections of nodes and edges .
//tree
//tree lo undalasina properities no cycles ,all nodes should be connected,.
//relate it to  first sem fee subject
#include<iostream>
using namespace std;
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    int matrix[nodes+1][nodes+1];
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        matrix[u][v]=1;
        matrix[v][u]=1;//undirectional  graphs 
    }
    vector<vector<int>>arr(n+1);
    //o(m+n lo avvali )
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(v);
    }




return 0;}
