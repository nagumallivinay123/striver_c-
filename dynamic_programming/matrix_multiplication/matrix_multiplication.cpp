#include <bits/stdc++.h>
using namespace std;

//edhi naa own code refer cheyi chaala sarulu 
int func(int index1, int index2, int arr[])
{
    if (abs(index1 - index2) <= 1)
    {
        return 0;
    }
    int sum = INT_MAX;
    for (int i = index1 + 1; i < index2; i++)
    {

        int val = arr[index1] * arr[index2] * arr[i] + func(index1, i, arr) + func(i, index2, arr);
        sum = min(val, sum);
    }
    return sum;
}
int matrixMultiplication(int N, int arr[])
{
    // code here
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
    for (int len = 2; len < N; len++)
    {
        int i = 0;
        int j = i + len;
        // diagonal anni first olve chesukuntunnam

        // aa taravata anni vetukuntamu
        while (i < N && j < N)
        {
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], arr[k] * arr[i] * arr[j] + dp[i][k] + dp[k][j]);
            }

            i++;
            j++;
        }
    }

    return dp[0][N - 1];
}
int main()
{
    return 0;
}