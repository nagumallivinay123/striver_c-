//(x,y )se destintation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;//frog1 sum of
// frog on matrix minimum time to reach to end of the node;
// 2 variable vaste dynamic programming lo 2d array rayali
// 3 variables vaste dynamic programming lo 3d array vadali
vector<vector<int>> grid;
int dp[n][m];
int cost(int x, int y)
{
    if (x >= n && y >= n)
    {
        return INT_MAX;
    }
    if (x == n - 1 && y == m - 1)
    {
        return grid[x][y];
    }
    return min(cost(x + 1, y), cost(x, y + 1)) + grid[x][y];
}
int cost(int x, int y)
{
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    if (x == n - 1 && y == m - 1)
    {
        return grid[x][y];
    }

    return dp[x][y] = min(cost(x + 1, y), cost(x, y + 1)) + grid[x][y];
}
int main()
{

    return 0;
}