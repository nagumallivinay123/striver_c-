// C++ program to find largest subarray with equal number of
// 0's and 1's.

#include <bits/stdc++.h>
using namespace std;

// Returns largest subarray with equal number of 0s and 1s

int main()
{
    //int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int arr[]={1,1,1,0,1,0,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    int sum = 0;
    int max_len = 0;
    int starting_index = 0, ending_index = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
            starting_index = 0;
            ending_index = i;
        }
        if (m.find(sum) != m.end())
        {
            if (max_len < i - m[sum])
            {
                max_len = i - m[sum];
                starting_index = m[sum] + 1;
                ending_index = i;
            }
        }
        else
        {
            m[sum] = i;
        }
    }
    cout<<"max_length is "<<max_len<<"  starting index  "<<starting_index<<" ending index "<<ending_index;
    return 0;
}
