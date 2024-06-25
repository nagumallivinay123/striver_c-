#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    map<int,int>store;
    //first approach +1 -1 trick 

    int n;
    cin>>n;
    vector<int>store(1e7+1,0);
    int mini_ma=INT_MAX;
    int maxi_ma=INT_MIN;

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
       mp[a]++;
       mp[b+1]--;
    //   int mini_ma=min(a,mini_ma);
    //   int maxi_ma=max(b,maxi_ma);
    }
    map<int,int>::iterator it;
    for(it:mp.begin();it!=mp.end();it++){
       
    }
    




return 0;}