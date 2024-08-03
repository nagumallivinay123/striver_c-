#include<bits/stdc++.h>
using namespace std;
int distinct(string s){
    int n=s.length();
    vector<int>dp(n+1,1);
    map<char,int>mp;
    for(int i=1;i<=n;i++){
        //in general take and not take case untaadi kabatti 
        dp[i]=2*dp[i-1];
        //okavela ee character choose chesukunnadi mundhu unteh konni subsequence remove cheyali 
        if(mp.find(s[i-1])!=mp.end()){
            int j=mp[s[i-1]];
            //careful gaa observe cheste pattern kanipistadi 
            dp[i]-=dp[j-1];
            
        }
        mp[s[i-1]]=i;
    }
    return dp[n];
}
int main(){
    int count=distinct("abcba");
    cout<<count<<"\n";
    return 0;
}