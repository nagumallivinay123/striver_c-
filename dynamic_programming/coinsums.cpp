// coins sum normal ga cheyachchu ani anukuntavu kani array dwara cheyachchu ani kani recurssions dwara cheayali konni cases wrong yipotayi
#include <iostream>
#include <bits/stdc++.h>
#define n 1e5 + 1
using namespace std;

vector<int> v(n);
int dp[10000];

int t;
int least(int amount)
{
    if (amount == 0)
    {
        static int p=0;
        p=p+1;
        return 0;
    }
    // if(dp[amount]!=-1){
    //     return dp[amount];
    // }
    int cost = INT_MAX;
    for (int i = 0; i < t; i++)
    {    if(amount>=v[i])
        cost = min(cost, least(amount - v[i])+1);
    }
    return cost;
}

int main()
{
    int amount;
    cin >> t>>amount;
memset(dp,-1,sizeof(dp));
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    cout<<least(amount)<<endl;
 
    return 0;
}