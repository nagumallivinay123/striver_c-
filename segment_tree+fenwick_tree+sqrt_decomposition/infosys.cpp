#include <bits/stdc++.h>
using namespace std;
#include <vector>

const int MOD = 1e9 + 7;

int solve(string& S, int K) {
    int N = S.size();
   vector<vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (S[i - 1] == '(') {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            } 
           
            else {
                if (i > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 2][j]) % MOD;
                }
                if (j > 0 && i > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 2][j - 1]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= K; j++) {
        result = (result + dp[N][j]) % MOD;
    }

    return result;
}

int GetAnswer(int N,int K,String S){
    return solve(S,K);
}


int main() {
    string S;
    int K;
    cin >> S >> K;

    int result = solve(S, K);
    cout << result << endl;

    return 0;
}


