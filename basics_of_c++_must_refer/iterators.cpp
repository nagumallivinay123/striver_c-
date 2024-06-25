#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){

vector<int>v(5,1);
vector<int>::iterator it;

for( it=v.begin();it!=v.end();it++){
    cout<<*it<<" ";
}
cout<<endl;
//range based loops ani mata
for(int value:v){
    cout<<value<<" ";
}
for(int &value:v){
    value++;
}
cout<<endl;
for(int value:v){
    cout<<value<<" ";
}
cout<<endl;
for(auto it=v.begin();it!=v.end();it++){
    cout<<*it<<" ";
}
return 0;}