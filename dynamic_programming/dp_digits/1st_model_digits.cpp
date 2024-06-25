#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[20][181][2];
int dp_digit(string &num,int No_of_digits,int sum,bool constraint ){
    if(sum<0){
        return 0;
    }
    if(No_of_digits==1){
        if(sum>=0 && sum<=9){
            return 1;
        }
        return 0;
    }
    if(dp[No_of_digits][sum][constraint]!=-1){
        return dp[No_of_digits][sum][constraint];
    }
    int upper_bound=constraint?(num[num.length()-No_of_digits]-'0'):9;
    int ans=0;
    for(int digit=0;digit<=upper_bound;digit++)
    {
        ans+=dp_digit(num,No_of_digits-1,sum-digit,constraint && (digit==upper_bound));

    }
    // cout<<ans<<" ";
    return dp[No_of_digits][sum][constraint]=ans;

}
int main(){
    string num="99";
    memset(dp,-1,sizeof(dp));
    dp_digit(num,2,10,1);
    cout<<dp[2][10][1]<<" ";
    //0 to 99 madyalo  10 vachche sums
    //55 64 46 28 82 91 19 37 73  ->9 sum vachchayi 
    



return 0;}