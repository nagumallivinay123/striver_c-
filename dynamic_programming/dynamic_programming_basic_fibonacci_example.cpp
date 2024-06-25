//dynamic programming lo rendu methods untayi okati top down approach marokati top up approach.
//top down approach ante recurions lo vadevi  enduku ante pai nunchi kindaki vastamu kabatti 
//top up approach kinda nunchi paiki velatamu
//prefix fibonacci seris example of top up approacch
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define  N 100001

int dp[N];
int fibonacci(int x){
    if(x==0){
        return 0;
    }
    if(x==1){
        return 1;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    dp[x]=fibonacci(x-1)+fibonacci(x-2);
    return dp[x];
}
int main(){
    memset(dp,-1,sizeof(dp));//edhi chala important function endhukante endulo manam mundu konta value evvachchu 
    //dynamic programming lo o(2^n) to o(n).o(n!)to o(2^n)
    int n;
    cin>>n;
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    //edhe dynammic programming lo o(2^n)problem
    for(int i=2;i<n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<endl;




return 0;}