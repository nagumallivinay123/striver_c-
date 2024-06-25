#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int arr[5]={5,7,8,9,1};
set<int>a;
for(int i=0; i < 5; i++){
    a.insert(i);
};
for(int i=0; i < 5; i++){
    if(a.find(arr[i])!=a.end())
       a.erase(arr[i]);
cout<<*a.begin()<<endl;
}



return 0;}