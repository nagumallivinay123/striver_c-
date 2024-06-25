#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long dp[101][N];
long long solve(int index, long long weight, long long arr[], long long value[])
{
    if (index == 0)
    {
        if (arr[0] <= weight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][weight] != -1)
    {
        return dp[index][weight];
    }
    long long take = 0;
    long long not_take = 0;
    if (arr[index] <= weight)
    {

        long long d = solve(index - 1, weight - arr[index], arr, value);
        take = value[index] + d;
    }
    not_take = solve(index - 1, weight, arr, value) + 0LL;
    dp[index][weight] = max(take, not_take) + 0LL;
    return dp[index][weight];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    long long weight;
    cin >> n >> weight;
    long long wet[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wet[i] >> value[i];
    }

    cout << solve(n - 1, weight, wet, value) << "\n";

    return 0;
}