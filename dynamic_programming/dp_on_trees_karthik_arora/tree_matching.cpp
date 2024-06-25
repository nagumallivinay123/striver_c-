#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long func(long long index, vector<long long> tree[], bool include, vector<vector<long long>> &dp)
{
    long long size = tree[index].size();

    if (size == 0)
    {
        return dp[index][include] = 0;
    }

    if (dp[index][include] != -1)
    {
        return dp[index][include];
    }
    if (include)
    {
        if (size == 1)
        {
            return dp[index][include] = 1 + func(tree[index][0], tree, !include, dp);
        }
        vector<long long> includes(size, 0);
        vector<long long> not_includes(size, 0);
        long long all_not_includes = 0;
        for (long long i = 0; i < size; i++)
        {
            includes[i] = func(tree[index][i], tree, !include, dp);
            not_includes[i] =func(tree[index][i], tree, include,dp);
            all_not_includes += not_includes[i];
        }
        long long ans = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            ans = max(ans, all_not_includes - not_includes[i] + includes[i]);
        }

        //    long long left_include= func(tree[index][0],tree,include,dp);
        // long long left_not_include=func(tree[index][0],tree,!include,dp);
        // long long right_include =func(tree[index][1],tree,include,dp);
        // long long right_not_include=func(tree[index][1],tree,!include,dp);
        // return dp[index][include]=1+max(left_include+right_not_include,right_include+left_not_include);
        return dp[index][include] = 1 + ans;
    }

    // long long left_include= func(tree[index][0],tree,!include,dp);
    // long long right_include=size>1?func(tree[index][1],tree,!include,dp):0;
    long long total = 0;
    for (int i = 0; i < size; i++)
    {
        total +=  func(tree[index][i], tree, !include, dp);
    }
    return dp[index][include]=total;

    // return dp[index][include]=left_include+right_include;
}
void remove_parent(long long index, long long parent, vector<long long> tree[])
{
    long unsigned int remove_index = -1;
    for (long unsigned int i = 0; i < tree[index].size(); i++)
    {
        if (tree[index][i] == parent)
        {
            remove_index = i;
            continue;
        }
        remove_parent(tree[index][i], index, tree);
    }
    if (remove_index != -1)
        tree[index].erase(tree[index].begin() + remove_index);
    return;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> tree[n + 1];
    vector<long long> top_element(n + 1, 0);
    vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));
    for (long long i = 0; i < n - 1; i++)
    {
        long long a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        top_element[a]++;
        top_element[b]++;
    }

    long long top = 1;
    int count = 0;
    // for (long long i = 1; i <= n; i++)
    // {
    //     if (top_element[i] ==1)
    //     {
    //         top = i;
    //         break;

    //     }
    // }
    // cout<<"1"<<"count :"<<count<<"\n";
    // cout << top << "\n";
    //  for(int i=1;i<=n;i++){
    //     cout<<i<<"->";
    //     for(auto it:tree[i]){
    //        cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    remove_parent(top, -1, tree);

    // for(int i=1;i<=n;i++){
    //     cout<<i<<"->";
    //     for(auto it:tree[i]){
    //        cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }

    cout <<func(top, tree, true, dp);
    // cout<<func(top,tree,false,dp);

    return 0;
}