#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vl vector<ll>
using namespace std;
//maps lo insertion and deletion ki time complexity log(n) avutundi dinni binary trees lo store chesukuntundi
int main()
{
    // find no of subarrays in array list such that sum of subarray is equal to k
    //{1 2 3 4 5 } endulo subarrays find cheyali evidanga ante sum of subarray is equal to 5;
    int num[5] = {1, 2, 3, 4, 5};
    // find prefix sumes
    int prefix_sum[5];
    prefix_sum[0] = 1;
    for (int i = 1; i < 5; i++)
    {
        prefix_sum[i] += num[i];
    }
    // prefix_sum[i]-prefix_sum[j]=k (concept behind it)i>j
    // prefix_sum[i]=k+prefix_sum[j];
    map<int, int> m;
    int ans = 0;
    int k=4;
    m[0]++;
    for (int i = 0; i < 5; i++)
    {
        
            if (m.find(prefix_sum[i] - k) != m.end())
                ans += m[prefix_sum[i] - k];
        
        m[prefix_sum[i]]++;
    }
cout<<ans<<endl;
    return 0;
}