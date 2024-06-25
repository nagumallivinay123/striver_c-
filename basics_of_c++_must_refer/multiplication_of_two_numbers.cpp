#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int multiply(int a,int b,int mod){
    int sum=0;
    while(b>0){
        if((b&1)==1){
            sum=(sum+a)%mod;
        }
        a=(a*2)%mod;
        b=b>>1;
    }
    return sum;
}
int main(){
    int a=1e6;
    int b=1e7;
    cout<<multiply(a,b,mod)<<" ";


return 0;}