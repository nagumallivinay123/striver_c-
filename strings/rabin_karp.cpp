#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// pattern matching algorithms
const long long mod = 1e6;
long long power(int primes, int n)
{
    long long ans = 1;
    long long prime = primes;
    while (n > 1)
    {
        if (n % 2 == 1)
        {
            ans = (ans * prime) % mod;
        }
        prime = (prime * prime) % mod;
        n = n / 2;
    }
    return ans;
}
// rabin karp deniki anteh strings lo unna substrings compare cheyadamu chaala kastam
// ala compare cheyad
// ekkada assala string b annadi  a lo exit avutunda ledha ani cheyadanik
//  bool kunal_kushwaha_rabin_karp(string a,string b){
//      int m=b.size();
//      int prime=101;
//      long long target_code=0;
//      for(int i=0;i<m;i++)
//      {
//          target_code=target_code+b[i]*power(prime,i);
//      }
//      long long hash_code=0;
//      int j=0;
//      while(j<a.size()){
//          if(j>=m){
//              hash_code=(hash_code-a[j-m])/prime;
//          }
//          hash_code=hash_code+a[i]*power(prime,)
//      }
//  }
bool rabin_karp(string a, string b)
{
    int m = b.size();
    int target_code = 0;
    for (int i = 0; i < m; i++)
    {
        target_code = (target_code * 31 + b[i]) % mod;
    }
    int power = 1;
    for (int i = 0; i < m; i++)
    {
        power = (power * 31) % mod;
    }
    int hash_code = 0;
    for (int i = 0; i < a.size(); i++)
    {
        hash_code = (hash_code * 31 + a[i]) % mod;
        if (i < m - 1)
        {
            continue;
        }
        else if (i >= m)
        {
            hash_code = (hash_code - a[i - m] * power) % mod;
        }
        if (hash_code < 0)
        {
            hash_code += mod;
        }
        if (hash_code == target_code)
        {
            if (b == a.substr(i - m + 1, m))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    cout << rabin_karp("abcdefghij", "ghk");

    return 0;
}