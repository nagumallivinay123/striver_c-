#include <iostream>
#include <bits/stdc++.h>
// 0_1 knapsack la cheste kudaradu endhukante time complexity maripothundi
// indulo constraints change avutayi
// index emo 100 untayi weights emo 10^9 varuku teesukuntavu
// appudu complexity 10^11 ayipoddi alanti samay lo dp apply cheyalevu
// andhuke weight ki kakunda
using namespace std;
const int N = 1e3 + 7;
long long dp[101][N];
long long solve(int index, long long variable_value, long long arr[], long long value[])
{
    if (variable_value == 0)
    {
        return 0;
    }
    if (index < 0)
    {
        return 1e15;
    }
    if (dp[index][variable_value] != -1)
    {
        return dp[index][variable_value];
    }
    long long ans = solve(index - 1, variable_value, arr, value);
    ans = min(ans, solve(index - 1, variable_value - value[index], arr, value) + arr[index]);
    return dp[index][variable_value] = ans;
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
    for (int i = 1e3; i >= 0; i--)
    {
        if (solve(n - 1, i, wet, value) <= weight)
        {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}