#include<bits/stdc++.h>
using namespace std;


 string postToPre(string s) {
        // Write your code here
        stack<string>store;
        
        for(auto it:s){
            if((it>='a' && it<='z') || (it>='A' && it<='Z')){
                string temp="";
                temp+=it;
                store.push(temp);
                // cout<<temp<<" ";
            }
            else{
                
                string a=store.top();store.pop();
                string b=store.top();store.pop();
                string ans="";
                ans+=it;
                
              
                
               
                store.push(it+b+a);
                
                //post to prefix/infix  vachchina order b a 
            }
        }
        return store.top();
    }
int main(){
    string s;
    cin>>s;;
    cout<<postToPre(s)<<endl;

return 0;
}