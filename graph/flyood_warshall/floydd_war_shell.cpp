//edhi shortest distance betweeen all pairs find out cheyadaniki vadaatamu 
//deeniki dp vadithe pani ayipothundi 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

    int edges,vertices;
    cin>>vertices>>edges;
    long long dp[vertices+1][vertices+1];
    //annitini intialise to maximum distances execpt i==j 
    for(int i=0;i<=vertices;i++){
        for(int j=0;j<=vertices;j++){
        if(i==j){
            dp[i][j]=0;
        }
        else{
            dp[i][j]=INT_MAX;}
            cout<<dp[i][j]<< " ";
        }
        cout<<"\n";

    }
    cout<<"\n\n\n";
    //x to y weight untundi
    for(int i=0;i<edges;i++){
        int x,y,weight;
        cin>>x>>y>>weight;
        dp[x][y]=weight;
    }
    //ekkade flyod warshall vachchindi algorithm 
    //flyod warshall gurinchi enka cheppalante brut force algorithm to implement all shortest distances all adjacent nodes;
//okavela dijikshtra apply chesina dani complexity enka takkua 
//oka node complexity of dijikshtra is Elogv ala n nodes ki v *elogv  adhey dijikshtra lo ayither v^3 
//dijikshtra negative cycle kannukolemu 

    for(int k=1;k<=vertices;k++){
    for(int i=1;i<=vertices;i++){
        for(int j=1;j<=vertices;j++){
            dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
        }

    }}
for(int i=1;i<=vertices;i++){
    for(int j=1;j<=vertices;j++){
        if(dp[i][j]==INT_MAX){
            cout<<"I"<<" ";
        }
        else{
            cout<<dp[i][j]<<" ";

        }
    }
    cout<<"\n";
}
    




return 0;}