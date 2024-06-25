#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
int arr[5]={5,3,2,2,6};
int k=8;
map<int,int>mp;
int sum=0;
mp[0]++;
for(int i=0;i<5;i++){
    if(mp.find(k-arr[i])!=mp.end()){
        sum+=mp[k-arr[i]];
    }
    mp[arr[i]]++;

}
cout<<sum<<endl;

return 0;}