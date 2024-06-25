#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//z algorithm eppudu kuda pattern matching /string matching kosmam 
//o(N^2 ) avvavalisindi o(2*n ) lo ayipothundi 
//gfg lo chusa solution 
//doubt vaste veedu -> https://www.youtube.com/watch?v=CpZh4eF8QBw
//dry run oksari  cheste telustuni 



void z_algo(string s,int z[]){
    int l=0,r=0;
    int n=s.length();
    for(int i=1;i<n;i++){
      if(i>r){
        l=r=i;
        while(r<n && s[r-l]==s[r]){
        r++;
        }
        z[i]=r-l;
        r--;
      }
    
    else
    {
        int k=i-l;
        if(z[k]<r-i+1){
            //mundhu same vastayi 
         z[i]=z[k];
        }
        else{
            l=i;
            while(r<n && s[r-l]==s[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
    }
    }
}
int main(){
string a="abcdbaabc";
string b="abc";
//manam b a lo undha ledha ani kanukuntamu 
//dani kosam a and b ni concat chestamu 
string concat=b+"@"+a;
int l=concat.length();
int z[l];
z_algo(concat,z);
for(int i=b.size()+1;i<l;i++){
    cout<<z[i]<<" ";
}



return 0;}