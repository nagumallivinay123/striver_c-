

#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const long long mod = 1e9 + 7;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool possible=true;
    long long sum=0;
    int prev=INT_MAX;
    for(ll i=n-1;i>=0;i--)
    {
        arr[i]-=sum;
        if(prev>=arr[i])
        {
            prev=arr[i];
        }
        else
        {
          long long count=__builtin_popcount(i+1);
          if(count==1){
            sum+=arr[i]-prev;
            arr[i]=prev;
          }
          else{
            possible=false;
            break;
          }
        }
    }

    if(possible){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


  
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}