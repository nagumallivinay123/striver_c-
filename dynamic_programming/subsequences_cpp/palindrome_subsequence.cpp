#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//pep coding vallu chaala baaga explain chesaru chudu 
//kachchitanga chusi cheyavalisinadhe..
int countPalindromicSubsequences(string &s){
	// Write your code here.
	//doubt vaste veedhidi chudu https://www.youtube.com/watch?v=YHSjvswCXC8
	int n=s.size();
	   const int mod=1e9+7;

        vector<vector<long long int>> dp(n,vector<long long int>(n,0));
	for(int len=0;len<n;++len){
		for(int start=0,end=len;end<n;++start,++end){
			if(len==0){
				dp[start][end]=1;
			}
			else if(len==1){
				dp[start][end]=(s[start]==s[end])?3:2;
			}
			else
			{
				if(s[start]!=s[end]){
					dp[start][end]=(dp[start+1][end]+dp[start][end-1]-dp[start+1][end-1])%mod;
				}
				else{
					dp[start][end]=(dp[start+1][end]+dp[start][end-1]+1)%mod;
				}
			}
		}
	}
	return (dp[0][n-1]+mod)%mod;

	
}
int main(){



return 0;}