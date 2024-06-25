
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long prime[100000001];
long long lowerprime[100000001]; // lowerprime number of number //ante oka composite number unte daniki lowest prime factor
// ee precomputation chesamu chudu dinne sieve ani antamu
// lower prime deniki ante prime factorization of number cheyadaniki vadatamu
vector<long long> v; // ee vector deniki ante prime factors store cheyadaniki vadatamu
// number theory
int main()
{

    for (long long i = 2; i < 1e8 + 1;)
    {
        if (prime[i] == 0)
        {
            v.push_back(i);
            lowerprime[i] = i;
            for (long long j = i * i; j < 1e8 + 1; j = j + i)
            {
                prime[j] = 1;
                lowerprime[j] = i;
            }
        }
        if (i == 2)
        {
            i++;
        }
        else
        {
            i += 2;
        }
    }
    int n;
    cin >> n;
    vector<long long> primefactorisation;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
            cout << i << "  ";
    }
    // cout << lowerprime[n] << endl;
    while (n > 1)
    {
        // cout<<lowerprime[n]<<endl;

        primefactorisation.push_back(lowerprime[n]);
        n = n / lowerprime[n];
    }

    for (auto i : primefactorisation)
    {
        cout << i << " ";
    }

    return 0;
}