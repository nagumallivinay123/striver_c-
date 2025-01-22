#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    vector<vector<int>>table(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                table[i][j]=1+table[i-1][j-1];
            }
            else{
                table[i][j]=max(table[i][j-1],table[i-1][j]);
            }
        }
    }
    int lcs_len=table[n][m];
    cout<<lcs_len<<endl;
    string lcs_string="";
    for(int i=0;i<lcs_len;i++){
        lcs_string+='$';
    }
    int i=n;
    int j=m;
    int index=lcs_len-1;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
             lcs_string[index]=a[i-1];
             index--;
             i--;
             j--;
        }
        else{
            if(table[i-1][j]>=table[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<lcs_string<<"\n";

return 0;
}