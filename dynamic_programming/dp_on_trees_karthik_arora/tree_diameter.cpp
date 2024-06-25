#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long dist(long long index,long long parent,vector<long long>tree[],long long count,vector<long long>&dp){
    long long ans=0;
    long long add=0;
    
    for(long long i=0;i<tree[index].size();i++){
        if(tree[index][i]!=parent)
        {
                  

            dp[tree[index][i]]=count+1;
            long long a=1+dist(tree[index][i],index,tree,count+1,dp);
            ans=max(ans,a);
        }
    }

    return ans;

}
int main(){
long long n;
cin>>n;
if(n==1){
    cout<<0<<"\n";
    return 0;
}
vector<long long>tree[n+1];
for(long long i=0; i<n; i++){
    long long a,b;
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
}

vector<long long>dp(n+1,0);
long long top=1;
long long max_dist=dist(1,-1,tree,0,dp);
for(auto i=1;i<=n;i++){
    if(dp[i]==max_dist){
        top=i;
        break;
    }
}
 max_dist=dist(top,-1,tree,0,dp);
cout<< max_dist;





return 0;}