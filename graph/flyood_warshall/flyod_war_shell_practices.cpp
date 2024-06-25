#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//codeforces taluka practice question floyyd warshall meeda 

int main(){
    int n;
    cin>>n;
  long long dist[n+1][n+1];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cin>>dist[i][j];
    }
  }
  vector<int>del_no(n);
  for(int i=0;i<n;i++){
    cin>>del_no[i];
  }
  //dinni reverese chestamu endhukante floyyd warshall starting nunchi untundi andhuvalle
 reverse(del_no.begin(),del_no.end());
 vector<int>ans;
 for(int k=0;k<n;k++){
    int test_index=del_no[k];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           long long new_dist=dist[i][test_index]+dist[test_index][j];
           dist[i][j]=min(dist[i][j],new_dist);
        }   
    }
    long long sum=0;
    for(int i=0;i<=k;k++){
        for(int j=0;j<=k;k++){
            sum+=dist[del_no[i]][del_no[j]];
        }
    }
    ans.push_back(sum);
 }
 reverse(ans.begin(),ans.end());
 for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
 }




return 0;}