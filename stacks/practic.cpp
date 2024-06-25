#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count++;
        }
        else
        {
            mp[count]++;
            count = 0;
        }
    }
    long long ans = 0;
    for (auto it : mp)
    {
        int a = it.first;
        int b = it.second;
        long long some = ((a * (a + 1) * 1LL) / 2) * 1LL;
        ans += (1LL * some * b);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>store;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        store.push_back(a);
    }
    cout<<zeroFilledSubarray(store);

    return 0;
}