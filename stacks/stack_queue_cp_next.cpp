//next greater element eppudu hackerrank question diniki eppudu stack upiyouginchi cheyadame
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int>v){
    stack<int>s;
    vector<int>vinay(v.size());
    for(int i=0; i<v.size(); i++){
        while(!s.empty() && v[i]>v[s.top()]){
            vinay[s.top()]=i;
            s.pop();
        }
       
        s.push(i);
    }
    while(!s.empty()){
        vinay[s.top()]=-1;
        s.pop();
    }
    return vinay;

}
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    vector<int>next_greater_element=nge(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<"next_greater_element = "<<(next_greater_element[i]==-1?-1:v[next_greater_element[i]])<<endl;
    }



return 0;}