//find tha largest subarray such that it contains double ones of zeros in binaray array\

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 1, 0, 0, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -2;
    }
    int sumarray[n];
    sumarray[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        sumarray[i] = sumarray[i - 1] + arr[i];
    }
    map<int, int> m;
    int start = 0, end = 0;
    int maxsize = 0;
    for (int i = 0; i < n; i++)
    {
        if (sumarray[i] == 0)
        {
            maxsize = i + 1;
            start = 0;
            end = i;
        }
        if (m.find(sumarray[i]) != m.end())
        {
            if (maxsize < i - m[sumarray[i]])
            {
                maxsize = i - m[sumarray[i]];
                start = m[sumarray[i]] + 1;
                end = i;
            }
        }
        else
        {
            m[sumarray[i]] = i;
        }
    }
    cout << "maxsize is " << maxsize << " starting index " << start << " ending index " << end << endl;

    return 0;
}