#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
#include <map>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        ll brr[n];
        vector<pair<ll, ll> > vp;
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            vp.push_back(pair<ll, ll>(arr[i], brr[i]));
        }
        sort(vp.begin(), vp.end());
        // for(int i=0;i<vp.size();i++){
        //     cout<<vp[i].first<<" ";
        // }
        //     for(int i=0;i<vp.size();i++){
        //     cout<<vp[i].second<<" ";
        // }
        int max = -1;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (max < vp[i].second)
            {
                ans++;
                max = vp[i].second;
            }
        }
        cout << ans << "\n";
    }
        return 0;
    }