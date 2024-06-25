#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>isprime(n+1,1);
    vector<int>divisorscount(n+1,1);//if primefactorization done for numbers
    isprime[1]=0;
    for(int i=2;i<=n;i++){
        
        if(isprime[i]==1){
            for(int j=2*i;j<=n;j=j+i)
            {
                isprime[j]=0;
                int copytheJ=j;
                int count=0;
                while(copytheJ%i==0){
                    count++;
                    copytheJ=copytheJ/i;
                }
                divisorscount[j]*=(count+1);
            }
        }
    }
for(int i=1;i<=n;i++){
    cout<<divisorscount[i]<<endl;
}


return 0;}