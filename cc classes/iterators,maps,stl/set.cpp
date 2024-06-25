#include<iostream>
#include<bits/stdc++.h>


using namespace std;
int main(){

set<int>s;
unordered_set<int>p;
multiset<int>t;
s.insert(2);
s.insert(3);
s.insert(3);
s.insert(4);
s.insert(3);

for(auto it:s)
cout<<it<<endl;

return 0;}