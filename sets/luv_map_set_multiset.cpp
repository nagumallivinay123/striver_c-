//map lo insertion (logn) lo avutundi
//given n strings ,print unique string in lexicographical order with their frequency
//map lo set lo anni order lo vastayi
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
map<string,int>m;
int n;
cin>>n;
for(int i=0;i<n;i++){
    string p;
    cin>>p;
    m[p]++;
}
map<string,int>::iterator it;
for( it=m.begin();it!=m.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
}


return 0;}