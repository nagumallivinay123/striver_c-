/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool check(int arr[], int mid, int n, int c)
{
    int pre = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pre >= mid)
        {
            count++;
            pre = arr[i];
        }
    }
    if (count >= c)
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans;
        sort(arr, arr + n);
        int lower = 0;
        int upper = arr[n - 1];
        while (lower <= upper)
        {
            int mid = (lower + upper) / 2;

            if (check(arr, mid, n, c) == true)
            {
                lower = mid + 1;
                ans = mid;
            }
            else
            {
                upper = mid - 1;
            }
        }
    cout << ans << endl;
    }

    return 0;
}
