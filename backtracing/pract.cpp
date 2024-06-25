#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void create(vector<string>&ans,string &temp,int left,int right,int n){
        if(left==n && right==n){
            ans.push_back(temp);
        }
        string any=temp;
        if(left<=n){
            temp+="(";
            create(ans,temp,left+1,right,n);     
        }
        if(left> right)
        {
            any+=")";
            create(ans,any,left,right+1,n);

        }
        
    }
int main(){
    vector<string>ans;
    int n;
    cin>>n;
    string temp;
    create(ans,temp,0,0,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }



return 0;}