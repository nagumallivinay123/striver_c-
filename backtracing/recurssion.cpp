//backtracking ante 
//recurssion lo backtracking teesukuntamu 
//back vachce option raste adhe backtracking r
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void generate(string  &s,int open,int close){
    if(open==0 && close==0){
        cout<<" \n";
        cout<<"correct string s is = "<<s<<endl;
    }
        static int i=0;
    if(open>0){
        s.push_back('(');
        cout<<s<<" "<<++i<<endl;
        generate(s,open-1,close);
        s.pop_back();
        cout<<s<<" "<<++i<<"hi"<<endl;
    }
    if(close>0){
        if(open<close){
            s.push_back(')');
            cout<<s<<" "<<++i<<endl;
            generate(s,open,close-1);
            s.pop_back();
            cout<<s<<" "<<++i<<endl;
        }
    }

}
using namespace std;
int main(){

int n=2;
string p;
generate(p,n,n);

return 0;}