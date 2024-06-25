#include<iostream>
#include<bits/stdc++.h>
//top lo fibonacci seris vastundi addition cheyali
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 1 2 3 5 8 13 
int dp[100001];
//dynamic programming deniki ante recurssion tree tagginchindanike vade technique 
//munde alochinchali ekkada normal recurssion tree run cheste fibonacci seris ki complexity city 2 power n  vastundi danni  mari deniki dynamic program o(n)
//
int fib(int n){
    if(n<=1){
        return 1;
    }
    if(dp[n]!=0)
    return dp[n];
    
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}
using namespace std;

int main(){




return 0;}