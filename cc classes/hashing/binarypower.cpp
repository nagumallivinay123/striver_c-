#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
#define ll long long
// use upper one solving things.
ll binary_exponential_inverse(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = res * x;
            res = res % mod;
        }
        x = x * x;
        x = x % mod;
        n = n / 2;
    }
    return res;
}
ll binary_exponential_power(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return binary_exponential_power(a * a, n / 2);
    }
    else
    {
        return a * binary_exponential_power(a * a, n / 2);
    }
}
int main()
{

    cout << binary_exponential_inverse(3, mod - 2) << endl;
    cout << binary_exponential_power(3, 23) << endl;

    return 0;
}