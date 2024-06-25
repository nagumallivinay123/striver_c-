
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long dp[65][65];
long long count(long long int places, long long int ones)
{
    if (dp[places][ones] != -1)
    {
        return dp[places][ones];
    }
    if (places < ones || places < 0)
    {
        return 0;
    }
    if (places == ones)
    {
        return dp[places][ones] = 1;
    }
    if (ones == 0)
    {
        return dp[places][ones] = 1LL << places;
    }
    return dp[places][ones] = count(places - 1, ones) + count(places - 1, ones - 1);
}
// ee function atmost kannukutadi
long long func(long long some, int k)
{

    if (k <= 0)
    {
        // cout << "func-> " << some << " " << k << "->" << 0 << "\n";

        return 0;
    }

    vector<int> store(64, 0);
    int highest = -1;
    long long ans = 0;
    long long num = some;
    while (num > 0)
    {
        if ((num & 1) == 1)
        {
            store[highest + 1] = 1;
        }
        highest++;
        num = num >> 1;
    }

    // cout<<b<<"\n";
    // cout<<"count->"<<"highest = "<<highest<<" k= "<<k+1<<" ->"<<b<<"\n";
    long long val = 0;
    int index = 1;
    for (int i = highest; i >= 0; i--)
    {
        if (store[i] == 1)
        {

            val |= (1 << i);
            if (k - index == 0)
            {
                ans += (some - val);
                // cout<<some<<"->"<<val<<"\n";
            }

            if (k + 1 - index > 0)
            {
                ans += count(i, k + 2 - index);
            }

            index++;
        }
    }
    int add = 0;
    // if(__builtin_popcount(some)<=k){
    //     add=1;
    // }
    return some + 1+add - (ans );
}

long long findNthNumber(int n, int k)
{
    // code here
    long long low = 0;
    long long high = 1e9;
    while (low < high)
    {
        long long mid = (low + high) / 2;
        long long val = func(mid, k);
        if (val < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << findNthNumber(5,1) << "\n";

    return 0;
}