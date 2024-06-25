#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// finding length of longest subsequence
int function(string s, string l, int index1, int index2, vector<vector<int>> &dp)
{
    // base case
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }
    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }
    if (s[index1] == l[index2])
    {
        return dp[index1][index2] = 1 + function(s, l, index1 - 1, index2 - 1);
    }

    return dp[index1][index2] = max(function(s, l, index1 - 1, index2), function(s, l, index1, index2 - 1));
}
int main()
{
    // only modified dp
    string s, l;
    cin >> s >> l;
    vector<vector<int>> dp(s.size() + 1, vector<int>(l.size() + 1, -1));
    for (int i = 0; i <= s.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= l.size(); i++)
    {
        dp[0][l] = 0;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= l.size(); j++)
        {
            if (s[i - 1] == l[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // dp[n][m] lo neeku maximum length unna subsequence yokka value vastadi
    // uppudu longest string find out chestam
    int length = dp[s.size()][l.size()];
    string ans;
    a
    for (int i = 0; i < length; i++)
    {
        ans += '$';
    }
    int k = s.size(), m = l.size();
    int index = length - 1;
    while (k > 0 && l > 0)
    {
        if (s[k] == s[l])
        {
            ans[index] = s[k];
            k--;
            l--;
            index--;
        }
        else if (dp[k - 1][l] > dp[k][l - 1])
        {
            k--;
        }
        else
        {
            l--;
        }
    }

    return 0;
}