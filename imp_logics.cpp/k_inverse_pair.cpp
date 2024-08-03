#include<bits/stdc++.h>
using namespace std;

//int method-1;
int func(int n,int k)
{
    if(n==0){
        if(k==0){
            return 1;
        }
        return 0;
    }
   int ans=0;
    for(int i=0;i<=min(n,k);i++){
        ans+=func(n-1,k-i);
    }
    return ans;
}
//method-2 
int func2(int n,int k){
    if(k<=0){
        return (k==0);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=func2(n-1,k-i);
    }
    return ans;
} 


int main(){
    //int n,k vaadu estadu 
    //1,2,3...n varuku k vachche inverse pairs kanipettali 
    int n,k;
    cin>>n>>k;
    cout<<func(n-1,k)<<"\n";
    cout<<func2(n,k)<<"\n";
return 0;
}