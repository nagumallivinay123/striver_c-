#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> nge(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // cout << arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }
        if (s.empty()==true)
        {
            s.push(arr[i]);
            nge[i] = -1;
        }
        else
        {
            nge[i] = s.top();
            s.push(arr[i]);
        }
    }
    for(int i=0; i<nge.size();i++){
        cout<<nge[i]<<" "<<endl;
    }

    return 0;
}