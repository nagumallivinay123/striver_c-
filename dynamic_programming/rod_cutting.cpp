#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int dp[N];
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    int dp[triangle.size()][traingle.size()];
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle.size(); j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                if (i <= 0)
                {
                    dp[i][j] = triangle[i][j]
                }
                else
                {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = trianle[i][j] + min(dp[i - 1][j - 1], dp[i][j - 1]);
            }
        }
    }
    int main()
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cout << origin(n, v) << "\n";

        return 0;
    }