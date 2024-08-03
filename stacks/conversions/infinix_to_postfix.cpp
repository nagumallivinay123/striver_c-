#include<bits/stdc++.h>
using namespace std;

//jenny's lecture chudu okasari neeku ardamavutundi 
    //https://www.youtube.com/watch?v=PAceaOSnxQs
    string infixToPostfix(string s) {
        // Your code here
        map<char,int>mp;
        stack<char>store;
        mp['+']=0;
        mp['-']=0;
        mp['*']=1;
        mp['/']=1;
        mp['^']=2;
        mp['(']=-1;
        string ans="";
        for(auto it:s){
            if(it=='+' || it=='-' || it=='*' || it=='/' || it=='^'){
                if(!store.empty() && mp[it]<=mp[store.top()])
                {
                    while(!store.empty() && mp[it]<=mp[store.top()]){
                        ans+=store.top();
                        store.pop();
                    }
                    
                }
                store.push(it);
            }
            else if(it=='('){
               store.push(it) ;
            }
            else if(it==')'){
                while(!store.empty() && mp[store.top()]!=-1){
                    ans+=store.top();
                    store.pop();
                }
                store.pop();
            }
            else{
                ans+=it;
            }
        }
        while(!store.empty()){
            ans+=store.top();
            store.pop();
        }
        return ans;
    }


int main()
{
    string s;
    cin>>s;
    cout<<infixToPostfix(s)<<endl;

return 0;
}