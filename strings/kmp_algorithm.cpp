#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//pattern matching -> pattern dhe 
//okasari abdul bari example chudu intuition baaga vastundi -> https://www.youtube.com/watch?v=V5-7GzOfADQ
//o(m*n) time complexity dhi o(m+n) kinda marustundi 
//gfg kuda refere cheyi -> https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

//mundu pattern vetike string taaluka lps array annadi kanipettali 
void find_lps(string pattern,int lps[])
{
int len=0;
int right=0;
int m=pattern.size();
lps[right]=0;
right++;
while(right<m){
    if(pattern[right]==pattern[len]){
    len++;
    lps[right]=len;
    right++;
    }
    else{
        if(len>0)
        {
        len=lps[len-1];
        }
        else{
            lps[right]=len;
            right++;
        }
    }
    
}
}
  int kmp_algo(string txt,string pattern){
    int m=pattern.size();
    int n=txt.size();
    int lps[m];
     find_lps( pattern,lps);
     int j=0,i=0;
     int ans=-1;
     while(i<n && j<m){
         if(txt[i]==pattern[j])
         {
             i++;
             j++;
         }
        else{
             if(j>0)
             {
             j=lps[j-1];
             }
             else{
                i++;
             }
            
         }
        if(j==m)
        {
            ans=i-m+1;
            return ans;
            j=lps[j-1];
        }
         
         
     }
     
     return -1;
}

int main(){
    string txt="abcdefghabc";
    string pattern="abc";
    //it will return index of matched string 
    cout<<kmp_algo(txt,pattern)<<"\n";



return 0;}