//ekkada backtracing ne vadali 
//permutations of all letter of array 
//1 2 3 
// pick not pick method ne vadali same 
//maps leda vector vadukvatam manchidi 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void find_permutations(vector<vector<int> >&ans,vector<int>temp,vector<int>store,vector<int>&v){
    if(v.size()==store.size()){
        ans.push_back(store);
        return;
    }
    for(int i=0;i<v.size();i++){
        if(temp[i]!=0){
            continue;
        }
        store.push_back(v[i]);
        temp[i]=1;
        find_permutations(ans,temp,store,v);
        temp[i]=0;
        store.pop_back();


    }

}
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=i+1;
    };
    vector<vector<int> >ans;
    vector<int>store;
    vector<int>temp(n,0);
    find_permutations(ans,temp,store,v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }



return 0;}
