#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    pair<int,string>p,p4;
    p=make_pair(1,"string");
    
    cout<<p.first<<p.second<<endl;
    //parity ante okati odd unte onkoti even untundi adhe
    pair<int,string> p2=p;
    p2.first=7;
    cout<<p2.first<<p2.second<<endl;
    pair<int ,string>&p3=p;
    p3.first=37;
cout<<p.first<<p.second<<endl;




return 0;}