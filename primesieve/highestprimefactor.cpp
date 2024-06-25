#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> isprime(n + 1, 1);
    vector<int> hpf(n + 1, -1);
    vector<int> lpf(n + 1, -1); // ll=pf
    isprime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        
        if (isprime[i] == 1)
        { 
            hpf[i]=i;
            lpf[i]=i;
            
            for (int j = 2*i; j <= n; j = j + i)
            {
                isprime[j] = 0;
                hpf[j] = i; // edi change avutu untundi constant ga undadu no no  ki anduke ala pettamu
                if (lpf[j] == -1)
                {
                    lpf[j] = i; // edi oka sare value teesukovali andhuke ela rasamu
                }
            }
        }
        
    }
    for(int i = 2; i <= n; i++){
        cout<<i<<" "<<"h.p.f = "<<hpf[i]<<" l.p.f = "<<lpf[i]<<endl;
    }

    return 0;
}