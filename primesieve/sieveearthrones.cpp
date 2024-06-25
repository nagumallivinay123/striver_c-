#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int N = 1e7 + 10;
vector<bool> isprime(N, true);
// first anni primes ani anukuntamu
// complexity of sieve of earthrones
// nuuvu own ga calculate cheste n/2 +n/3 +n/4+n/5+n/6+n/7+n/8 ................
//  so complexity = nlog(n) ->worst case
// in reality complexity n/2+n/3+n/5+n/7+n/11+n/13+n/17+n/19.......
// so real complexity = n(log(log(n)));
//  bool isprime(int n){
//      int count=0;
//      for(int i=2;i<=sqrt(n);i++){
//          if(n%i==0){
//              return true;
//          }
//      }
//      return false;
//  }

// prime factors ela kannukovali
vector<int> lower_prime_factor(N, 0);
vector<int> highest_prime_factor(N, 0);
int main()
{
    int n;
    cin>>n;
    isprime[0] = 1;lower_prime_factor[0]=-1;highest_prime_factor[0]=-1;
    isprime[1] = 1;lower_prime_factor[1]=-1;highest_prime_factor[1]=-1;
    
    // edhi intution ravadaniki vadedi kani real dhi kadhu
    //  for (int i = 2; i < N : i++)
    //  {
    //      if (isprime[i] == true)
    //      {
    //          for (int j = 2 * i; j < N; j += i)
    //          {
    //              isprime[j] = false;
    //          }
    //      }
    //  }
    for (int i = 2; i * i < N; i++)
    {
        if (isprime[i] == true)
        {
            highest_prime_factor[i] = i;
            lower_prime_factor[i] = i;
            for (int j = i*2; j < N; j += i)
            {

                isprime[j] = false;
                highest_prime_factor[j] = i;
                if (lower_prime_factor[j] == 0)
                {
                    lower_prime_factor[j] = i;
                }
            }
        }
    }
    //primefactorization of number 
    vector<int>prime_factorisation_store;
    while(n>1){
        prime_factorisation_store.push_back(highest_prime_factor[n]);
        n=n/highest_prime_factor[n];

    }
    for(int i=0;i<prime_factorisation_store.size();i++){
        cout<<prime_factorisation_store[i]<<"\n";
    }

    return 0;
}