#include<bits/stdc++.h>
using namespace std;
void find_lps(string pattern,vector<int>&lps){
    int len=0;
    int r=1;
    lps[0]=0;
    int n=pattern.length();
    while(r<n){
        if(pattern[r]==pattern[len]){
            len++;
            lps[r]=len;
            r++;
        }
        else{
            if(len>0){
                len=lps[len-1]; 
            }
            else{
                lps[r]=len;
                r++;
            }
        }
    }

}
void kmp(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    vector<int>lps(n,0);
    find_lps(pattern,lps);
    int i=0;
    int j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        else{
            if(j>0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        if(j>=m){
            cout<<i-m<<" ";
            j=lps[j-1];
        }
    }
}

int main(){
    string txt="abcdefghabc";
    string pattern="abc";
    //it will return index of matched string 
    kmp(txt,pattern);

return 0;
}