#include<iostream>
using namespace std;
int n=10000;
vector<int>dp(n+1);
void increasing_subsequences(int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
    }
    
    for(int j=0;j<n;j++){
        ans=max(ans,dp[j]);
    }
    //malli vetiki rasedi oka case undhi
    int *j=upper
   
}
int main(){



return 0;}