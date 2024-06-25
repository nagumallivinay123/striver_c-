#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    //1.inbuilt-implementation
    //2.hash table annadi use avutundi 
    //3.valid keys
    //neeku unordered kava
//Q  Given N strings and Q queries in each query you are given a string print frequency of that string 
//N<=10^6:
//|s|<=1000
unordered_map<string,int>m;
int n;
cin>>n;
for(int i=0;i<n;i++){
    string p;
    cin>>p;
    m[p]++;
}
unordered_map<string,int>::iterator it;
for(it=m.begin();it!=m.end();it++){
    cout<<it->second<<endl;
}
multimap<pair<int,int>,string>m;//multimap pedda ga ekkuva use avvadu competitive coding 

return 0;}