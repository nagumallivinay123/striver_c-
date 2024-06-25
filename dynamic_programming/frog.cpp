#include <iostream>
#include <bits/stdc++.h>
const int N = 1e5 + 7;
using namespace std;
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
int frog(int n, int arr[])
{
    if (n == 0)
    {
        dp[n] = 0;
        return dp[n];
    }
    if (n == 1)
    {
        dp[n] = difference(arr[n], arr[n - 1]);
        return dp[n];
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = min(difference(arr[n - 1], arr[n]) + frog(n - 1, arr), difference(arr[n - 2], arr[n]) + frog(n - 2, arr));

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << frog(n - 1, arr) << "\n";

    return 0;
}