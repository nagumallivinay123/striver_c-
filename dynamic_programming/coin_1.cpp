#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N];

int solve(int amount, vector<int> &v)
{
    if (amount == 0)
    {
        return 1;
    }
    else if (amount < 0)
    {
        return 0;
    }
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int c = amount - v[i];
        if (c >= 0)
        {
            temp += solve(c, v);
        }
    }
    dp[amount] = temp;
    return dp[amount];
}

int main()
{
    memset(dp, -1, N);
    int amount;
    int n;
    cin >> n >> amount;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // cout<<amount;
    cout << solve(amount, v) << "\n";
    cout << dp[3] << "\n";
    cout << dp[4] << "\n";

    return 0;
}