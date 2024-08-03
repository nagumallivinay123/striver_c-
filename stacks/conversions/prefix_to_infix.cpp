#include<bits/stdc++.h>
using namespace std;
//doubt vaste ekkada refer cheyi -> https://www.youtube.com/watch?v=b6m4f2xwRjM
//first string reverse cheyali endhukanteh 
  //infix lo operands first ravali    mari prefix lo operands mundu untayi so reverse cheyali anna alochana ravali 
  //logic okkata operands ni push cheyi 
  //operator kanipinchagane last two pop cheyi 
  //aa renditiki operator join chesi stack lo pampi
    string preToInfix(string s) {
        // Write your code here
        stack<string>store;
        reverse(s.begin(),s.end());
        for(auto it:s){
            if((it>='a' && it<='z') ||(it>='A' && it<='Z'))
            {
                string p="";
                p+=it;
                store.push(p);
            }
            else{
                string a=store.top();
                store.pop();
                string b=store.top();
                store.pop();
                string p="";
                p+=it;
                store.push("("+a+p+b+")");
            }
            
        }
        return store.top();
    }

int main(){
    string s;
    cin>>s;
    cout<<preToInfix(s)<<endl;

return 0;
}