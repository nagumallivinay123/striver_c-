#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int invest(int N, int D, vector<int> A)
{
    vector<int> S = A;
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    unordered_map<int, int> compress;
    for (int i = 0; i < S.size(); ++i)
    {
        compress[S[i]] = i;
    }
    vector<unordered_map<int, int>> dp(N + 1);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        int Ai = A[i - 1];
        int cAi = compress[Ai];
        dp[i][cAi] = max(dp[i][cAi], 1);
        for (int j = max(1, i - D); j < i; ++j)
        {
            for (auto &p : dp[j])
            {
                int c = p.first;
                int len = p.second;
                if (cAi > c)
                {
                    dp[i][cAi] = max(dp[i][cAi], len + 1);
                }
                else
                {
                    dp[i][c] = max(dp[i][c], len);
                }
            }
        }
    }
    int ans = 0;
    for (auto &p : dp[N])
    {
        ans = max(ans, p.second);
    }
    return ans;
}

int main()
{
    int N, D;
    cout << "Enter the number of days N: ";
    cin >> N;
    cout << "Enter the maximum day difference D: ";
    cin >> D;

    vector<int> A(N);
    cout << "Enter the earnings for each day: ";
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int result = invest(N, D, A);
    cout << "Maximum possible days Wael will allow you to invest: " << result << endl;
    return 0;
}
