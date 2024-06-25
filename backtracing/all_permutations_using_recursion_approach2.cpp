#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void find_permutations(int index,vector<vector<int> >&ans,vector<int>temp){
    if(index>=temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<temp.size();i++)
    {
        swap(temp[index],temp[i]);
        find_permutations(index+1,ans,temp);
        swap(temp[index],temp[i]);
    }

}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>temp(n,0);

    for(int i=0;i<n;i++){
        v[i]=i+1;
        temp[i]=i+1;
    };
    vector<vector<int> >ans;
    find_permutations(0,ans,temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }



return 0;}