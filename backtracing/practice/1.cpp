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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n], arr2[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        map<pair<int,int>, int> mp;
        int maxt = 0;
        for (int i = 0; i < n; i++)
        {
            pair<int,int>s;
            s.first=arr[i];
            s.second=arr2[i];
            maxt+=mp[s];
            s.first=arr2[i];
            s.second=arr[i];
            mp[s]++;
        }
        cout<<maxt<<endl;
    }
}