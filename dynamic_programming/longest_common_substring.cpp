#include<bits/stdc++.h>
using namespace std;
int main(){
    int maxi=0;
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0))
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
           if(a[i-1]==b[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
            maxi=max(dp[i][j],maxi);           }
           
        }

    }
    cout<<maxi<<"\n";
return 0;
}