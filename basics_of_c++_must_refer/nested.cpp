#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main(){
    map<pair<string,string>,vector<int> >m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string fn,ln;
        int count;
        cin>>fn>>ln>>count;
        for(int j=0;j<count;j++){
            int x;
            cin>>x;
            m[{fn,ln}].push_back(x);
        }

    }
    for(auto &pr:m){
        auto &gh=pr.first;
        auto &list=pr.second;
        cout<<gh.first<<" "<<gh.second<<endl;
        cout<<list.size()<<endl;
        for(auto &element:list){
            cout<<element<<" ";
        }
        
    }



return 0;}