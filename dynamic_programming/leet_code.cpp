#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findMaxForm(vector<string> &strs, int m, int n)
{
    int v[strs.size()][2];
    int dp[strs.size()];
    for(int i=0;i<strs.size();i++){
        for(int j=0;j<2;j++){
            v[i][j]=0;
        }
    }
    
    for (int i = 0; i < strs.size(); i++)
    {
        string p = strs[i];
        for (int j = 0; j < p.length(); j++)
        {

            if (p[j] == '1')
            {
                v[i][1]++;
            }
            else if(p[j]=='0')
            {
                v[i][0]++;
            }
        }
    }

    for (int i = 0; i < strs.size(); i++)
    {
        dp[i] = 0;
        if (v[i][0] <= m && v[i][1] <= n)
        {
            dp[i] = 1;
            int temp = -1;
            for (int j = i - 1; j >= 0; j--)
            {

                if ((v[j][0] + v[i][0]) <= m && (v[j][1] + v[i][1]) <= n)
                {
                   int temp2=dp[i];
                   dp[i]=max(dp[j]+1,dp[i]);
                   if(dp[i]>temp2){
                    temp=j;
                   }
                   else if(temp2==dp[j]+1){
                    if(v[temp][0]-v[j][0]>=0 && v[temp][1]-v[j][1]>=0)
                    {
                        temp=j;

                    }
                   }
                   
                }
            }
            if (temp != -1)
            {
                v[i][0]+=v[temp][0];
                v[i][1]+=v[temp][1];
                dp[i]=dp[temp]+1;
            }
        }
             cout<<v[i][0]<<v[i][1]<<" "<<dp[i]<<"\n";
    }
    int ans = -1;
    for (int i = 0; i < strs.size(); i++)
    {
       // cout<<dp[i]<<endl;
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
    string  a;
        cin >> a;
        v.push_back(a);
    }
    int a,b;
    cin>>a>>b;
cout<<findMaxForm(v,a,b)<<"\n";
    return 0;
}