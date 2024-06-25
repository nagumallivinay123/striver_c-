#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    //echchina array lo longest increasing subsequence find out cheyali 
//o(n^2 ) badulu o(nlog(n)) ayyedi binary search kavali 
//ekkada length kannukovadaniki upiyogapadutundi gani
int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}
vector<int>temp;
int length=0;
temp.push_back(arr[0]);
for(int i=1; i<n; i++){
    if(arr[i]>temp.back()){
    //array travel chestunnappudu okavela last element of arr[i] kanna greater than unteh temp loki push chestamu 
        temp.push_back(arr[i]);
        length++;
    }
    else{
        int index=lower_bound(temp.begin(), temp.end(),arr[i]);
        temp[index]=arr[i];
    }
}
return length;

return 0;}