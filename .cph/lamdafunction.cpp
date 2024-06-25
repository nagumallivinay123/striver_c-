#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool is_positive(int x){
    return x>0;
}
int main(){
vector<int>v(5);
v[0]=8;
v[1]=6;
v[2]=-2;
v[3]=5;
v[4]=6;
//lamda function like in python [](int x)({return x%2==0;})
cout<<all_of(v.begin(),v.end(),is_positive)<<endl;
cout<<any_of(v.begin(),v.end(),is_positive)<<endl;//edi ayina okati avuthe chalue
cout<<none_of(v.begin(),v.end(),is_positive);//okkati avakapoyina_appudu true return  ayipothundi 

return 0;}