#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool palindrome_check(int left,int right,string s){
int i=left;
int j=right;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        
        i++;
        j--;

    }
    return true;
}
void function_n(int index,vector<vector<string> >&ans,vector<string>&temp,string s){
    if(index>=s.length()){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<s.length();i++){
        string special=s.substr(index,i-index+1);
        if(palindrome_check(index,i,s)){
            //cout<<special<<"->"<<"index "<<index<<"\n";
            temp.push_back(special);
             function_n(i+1,ans,temp,s);
            temp.pop_back();       
        }
    }


}
int main(){
    string s;
    cin>>s;
vector<vector<string> >ans;
vector<string>temp;
function_n(0,ans,temp,s);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
}


return 0;}