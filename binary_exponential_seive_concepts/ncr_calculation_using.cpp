#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long binary_exponential(long long a,long long b,long long  mod)
{
    long long ans=1;
    while(b!=0){
        
        if((b&1)==1){
           ans=(ans*1LL*a)%mod;
        }
        a=(a*1LL*a)%mod;
       b= b>>1;
    }
    return ans;
}
int ncr(int n,int r){
   long long factorial[n+1];
    factorial[0]=1;
    factorial[1]=1;
    for(int i=2;i<=n;i++){
      factorial[i]=(i*factorial[i-1])%MOD;
    }
    long long some=(factorial[n-r]*1LL*(factorial[r]))%MOD;
    long long ans=(factorial[n]*binary_exponential(some,MOD-2,MOD)*1LL)%MOD;
    cout<<ans<<"\n"; 
}
int main(){
    //giving n and r to find ncr calculation 
    //n!/(n-r)!r!
    //calculate some=(n-r)!r!;
    //ncr mod =(((factorial[n])%mod)*(some^-1)%mod)%mod;
    //some^-1=(some*mod-2)%mod;
    int n,r;
    cin>>n>>r;
    long long factorial[n+1];
    factorial[0]=1;
    factorial[1]=1;
    for(int i=2;i<=n;i++){
      factorial[i]=(i*factorial[i-1])%MOD;
    }
    long long some=(factorial[n-r]*1LL*(factorial[r]))%MOD;
    long long ans=(factorial[n]*binary_exponential(some,MOD-2,MOD)*1LL)%MOD;
    cout<<ans<<"\n";
    



    



return 0;
}