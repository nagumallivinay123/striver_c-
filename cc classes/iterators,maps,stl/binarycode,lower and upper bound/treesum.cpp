// standard woodcutting sum for binary search

// 4 7
// 20 15 10 17
// output=15
// indirect application of binary search
#include <bits/stdc++.h>
using namespace std;
bool required_greater_than_sum(vector<int> &arr, int mid, int key)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= mid)
        {
            sum += arr[i] - mid;
        }
        else
        {
            break;
        }
    }
    if (sum >= key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    int key;
    cin >> n >> key;
    int maximum = 0;
    vector<int>v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        maximum = max(maximum, x);
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int lower = 0;
    int higher = maximum;
    int ans;
    while (lower <= higher)
    {
        int mid = (higher + lower) / 2;
        if (required_greater_than_sum(v, mid, key) == true)
        {
            lower = mid + 1;
            ans = mid;
        }
        else
        {
            higher = mid - 1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
