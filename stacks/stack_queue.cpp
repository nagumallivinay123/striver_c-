#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
stack<int>s;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}
queue<int>q;
q.push(67);
q.push(65);
q.push(56);
q.push(54);
while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
}

return 0;}