#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int func(int l, int r, vector<int> &arr)
{
    if (l == r)
    {
        return 1;
    }
    if (l > r)
    {
        return 0;
    }
    // if(dp[l][r]!=-1){
    //     return dp[l][r];
    // }
    int count = 0;
    int i = l;
    while (i <= r && arr[i] == arr[l])
    {
        i++;
        count++;
    }
    int ans = count * count + func(i, r, arr);
    int sum = 0;
    int count2 = count;
    int prev = i - 1;
    for (int index = i; index <= r; index++)
    {
        if (arr[index] == arr[l])
        {
            sum += func(prev + 1, index - 1, arr);
            prev = index;
            count2++;
            ans = max(count2 * count2 + sum + func(index + 1, r, arr), ans);
        }
    }
    return dp[l][r] = ans;
}
int removeBoxes(vector<int> &boxes)
{
    memset(dp, -1, sizeof(dp));
    return func(0, boxes.size() - 1, boxes);
}
int main(){
    vector<int> some = { 1, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1};
    cout << removeBoxes(some)<<"\n";
}