#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int Max = 1e6;
int dp[N];
int difference(int a, int b)
{
    if (a > b)
    {
        return a - b;
    }
    else
    {
        return b - a;
    }
}
int frog2(int n, int arr[], int k)
{
    if (n == 0)
    {
        dp[n] = 0;
        return dp[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = Max;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ans = min(ans, frog2(n - i, arr, k) + difference(arr[n], arr[n - i]));
        }
    }
    dp[n] = ans;
    return dp[n];
}
int main()
{
    int n, k_jump;
    cin >> n >> k_jump;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    cout << frog2(n - 1, arr, k_jump) << "\n";

    return 0;
}