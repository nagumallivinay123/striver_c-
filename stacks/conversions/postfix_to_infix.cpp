#include<bits/stdc++.h>
using namespace std;
//same as prefix to infix kani ekkada string reverse cheyamu + pop chesi malli pettatappudu edhi mudhu edhi taravata chusukovali 
string postToInfix(string exp) {
        // Write your code here
         stack<string> s;
       int n = exp.length();
       for(int i = 0 ; i<n ;i++){
           char ch = exp[i];
    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        string res;
        res.push_back(ch);
        s.push(res);
    }
    else{
        string res ;
        string A = s.top();
        s.pop();
        string B = s.top();
        s.pop();
        res = "("+B+ch+A+")";
        s.push(move(res));
    }
       }
       return s.top();
    }
int main(){
    string s;
    cin>>s;
    cout<<postToInfix(s)<<endl;
return 0;
}