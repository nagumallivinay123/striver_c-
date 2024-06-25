#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    //c++ lo priority queue implement cheste adhi emi vastadi ante max heap vastadi
    //java lo priority queue implement cheste ahdi min heap vastadi
    //c++ lo min heap kavalante -arr symbol add chesi priority queue tosivestavu

priority_queue<int>q;
int n;
cin>>n;
//inbuilt max heap vastundi
//daniki reverse cheyalani priority queue -a pmapincha ante min heap 
//implementing min heap 
for(int i=0; i<n; i++){
    int a;
    cin>>a;
    q.push(-a);

}
while(!q.empty()){
    cout<<-q.top()<<" ";
    q.pop();//ekkada pop chesettappudu prati sari malli max heap chestundi andhuke doubt vastundi 

}



return 0;}