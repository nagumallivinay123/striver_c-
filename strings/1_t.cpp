#include <iostream>
#include <vector>
#include <string>
#include <climit>
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the minimum cost
int buyCandies(int K, vector<string> combos, vector<int> cost, int N)
{
    int maxMask = (1 << K) - 1;      // All flavours present mask
    vector<int> dp(1 << K, INT_MAX); // DP array to store the minimum cost for each mask
    dp[0] = 0;                       // No flavours, zero cost

    // Loop through each combo
    for (int i = 0; i < N; i++)
    {
        int mask = 0;
        // Create mask for current combo
        for (int j = 0; j < K; j++)
        {
            if (combos[i][j] == '1')
            {
                mask |= (1 << j); // Set the j-th flavour bit
            }
        }
        // Update DP for each possible current mask
        for (int currentMask = 0; currentMask <= maxMask; currentMask++)
        {
            if (dp[currentMask] != INT_MAX)
            {
                dp[currentMask | mask] = min(dp[currentMask | mask], dp[currentMask] + cost[i]);
            }
        }
    }

    return (dp[maxMask] == INT_MAX) ? -1 : dp[maxMask]; // If maxMask is not achievable, return -1
}

int main()
{
    // Input Example
    int K = 4;                                                        // Number of flavours
    vector<string> combos = {"1010", "0100", "0001", "1111", "1011"}; // Binary strings representing combos
    vector<int> cost = {5, 5, 5, 10, 2};                              // Cost of each combo
    int N = combos.size();                                            // Number of combos

    int result = buyCandies(K, combos, cost, N);
    cout << "Minimum cost to get all flavours: " << result << endl;

    return 0;
}
