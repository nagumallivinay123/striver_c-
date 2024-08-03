#include<bits/stdc++.h>
using namespace std;

 //deeniki logic same as infinix conversions 
   //prefix to infix logic lagga lne 
   //first reverse string 
   //operands eduraithe push into stack 
   //operator ayithe last two ni pop chesi , last ki (pop out daniki ) operator add chesi push cheyali  
    string preToPost(string s) {
        reverse(s.begin(),s.end());
        stack<string>store;
        for(auto it:s){
            if((it>='a' && it<='z') ||(it>='A' && it<='Z')){
                string temp="";
                temp+=it;
                store.push(temp);
            }
            else{
                string a=store.top();store.pop();
                string b=store.top();store.pop();
                string temp="";
                temp+=it;
                store.push(a+b+temp);
            }
        }
        return store.top();
        
        
    }
int main(){
    string s;
    cin >> s;
    cout<<preToPost(s)<<endl;
return 0;
}