#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n; i++){
       cin>>v[i]; 
    }
    int min=*min_element(v.begin(),v.end());//printsminimumu value in array
    int max=*max_element(v.begin(),v.end());
    int sum=accumulate(v.begin(),v.end(),0);//sum of all elements in vector_begin()
  int counts=count(v.begin(),v.end(),5);//5 enni sarulu vachchindi anedi chudavachchu 
  auto it=find(v.begin(),v.end(),6);
  if(it!=v.end()){
      cout<<*it<<endl;
  }
  reverse(v.begin(),v.end());


return 0;}