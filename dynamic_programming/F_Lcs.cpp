#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//actual two strings yokka dp table find out cheyali 
//dp table find out chesina taravata backtracing cheste ayipoddi
string s1,s2;
int main(){
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int> >v(m+1,vector<int>(n+1,0));
    //creation of dp table like fibonacci series 
    //seniors chepparu kada ala 
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                v[i][j]=v[i-1][j-1]+1;
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //backtracing
    int x=m,y=n;
    string ans="";
    while(x!=0 && y!=0){
        
        if(v[x][y]==v[x-1][y]){
            x--;
        }
        else if(v[x][y]==v[x][y-1]){
            y--;
        }
        else{
            ans=s1[x-1]+ans;
            x--;
            y--;
        }

    }
    cout<<ans<<"\n";


return 0;

}
// priority_queue<string> sp;
// string s, m;
// void recursion(int first, int second, int length1, int length2, string sub)
// {
//     if (first == length1|| second == length2)
//     {
//         cout<<sub<<"\n";
//         sp.push(sub);
//         return;
//     }
//     bool test=false;
//     string temp=sub;
//     int second_temp=second;
//     for(int i=second;i<length2;i++){
//         if(m[i]==s[first]){
//             sub=sub+m[i];
//             second=i;
//             test=true;
//             first=first+1;
//             break;
//         }
//     }
//     if(test==false){
//         recursion(first+1,second,length1,length2,sub);
//     }
//     else{
//         recursion(first,second_temp,length1,length2,temp);
//         recursion(first,second,length1,length2,sub);
//     }
// }

// int main()
// {
//     string subsequence;
//     cin >> s >> m;
//     subsequence = "";

//     recursion(0, 0, s.length(), m.length(), subsequence);
//     cout<<sp.top()<<"\n";

//     return 0;
// }