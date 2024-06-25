class Solution
{
public:
    const int N = 1e5;
    int dp[N];
    int function(int n, vector<int> &nums)
    {
        int ans = 1;
        if (dp[n] != -1)
        {
            return dp[n]
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[n])
            {
                ans = max(ans, function(i, nums) + 1);
            }
        }
        dp[n] = ans;
        return dp[n];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        for (int i = 0; i < N; i++)
        {
            dp[i] = -1;
        }
        int ans = 1;
        for (int i = 0; i < nums.size())
        {
            ans = max(ans, function(i, nums));
        }
        return ans;
    }
};