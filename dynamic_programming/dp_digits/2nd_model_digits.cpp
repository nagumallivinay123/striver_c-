#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long dp[20][2];
//ee sum model enthi 
//oka certain range l-r madaya enni numbers taluka sum of all digits taluka value find_out cheyali 
long long count(string &num,int no_of_digits,bool constraint){
    if(constraint==false){
        return (pow(10,no_of_digits)+0.1);
    }
    if(no_of_digits==0){
       return 1;
    }
    ll cnt=0;
     int up_bound=constraint?(num[num.length()-no_of_digits]-'0'):9;
     for(int digit=0;digit<=up_bound;digit++){
        cnt+=count(num,no_of_digits-1,constraint && up_bound==digit);
     }
     return cnt;
}

long long sum_digits(string &num,int no_of_digits,bool constraint){
    if(no_of_digits==0){
        return 0;
    }
    if(dp[no_of_digits][constraint]!=-1){
        return dp[no_of_digits][constraint];
    }
    long long ans=0;
    int up_bound=constraint?(num[num.length()-no_of_digits]-'0'):9;
    for(int digit=0;digit<=up_bound;digit++){
    ans+=digit*(count(num,no_of_digits-1,constraint && (up_bound==digit)));
    ans+=sum_digits(num,no_of_digits-1,constraint && (up_bound==digit));
    }
    return dp[no_of_digits][constraint]=ans;
}

//o-r summation find chestamu 
//0-l summation find chestamu 
//r-l annadu kabbatti r-l varuku mottam testamu
int main(){
    long long l,r;
    cin>>l>>r;
    string right=to_string(r);
    int no_of_digits_r=right.length();
    string left=to_string(l);
    int no_of_digits_l=left.length();
    memset(dp,-1,sizeof(dp));
    long long  sum_right=sum_digits(right,no_of_digits_r,true);
    memset(dp,-1,sizeof(dp));
    long long sum_left=sum_digits(left,no_of_digits_l,true);
    cout<<sum_right-sum_left<<"\n";


return 0;}