#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long M = 1e9+7;
// recurssive approach
long long binary_exponential(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long res = binary_exponential(a, b / 2);
    if ((b & 1) == 1)
    {
        return (a * ((res * res) % M)) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
// iterative approach
// follow the approch given by
long long exponential(long long a, long long b)
{
    long long ans = 1;
    while (b != 0)
    {
        if ((b & 1) == 1)
        {
            ans = (ans * a ) % M;
        }
        a = (a * a ) % M;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    cout<<exponential(2,64)<<"\n";

    return 0;
}