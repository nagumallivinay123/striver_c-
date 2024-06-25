#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//distinct permutation of repeated numbers in array 
 void func(int index,map<int,int>&mp,vector<int>&temp,vector<vector<int>>&ans){
      if(index==0){
          ans.push_back(temp);
          return ;
      }
      for(auto it:mp){
          if(it.second>=1){
              temp.push_back(it.first);
              mp[it.first]--;
              func(index-1,mp,temp,ans);
              temp.pop_back();
              mp[it.first]++;
          }
      }
      return;
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        func(n,mp,temp,ans);
        return ans;
        
    }
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    auto ans= uniquePerms(arr,n);
    for(auto it:ans){
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    



return 0;}