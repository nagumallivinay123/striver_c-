#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int largest_rectangle(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = 0;
    stack<int> store;
    for (int i = 0; i <=n; i++)
    {
        while (!store.empty() && (i==n || arr[store.top()] >= arr[i]))
        {
            int right_index = i;
            int height = arr[store.top()];
            int index=store.top();
            store.pop();
            int left_index;
            if (store.empty())
            {
                left_index = -1;
            }
            else
            {
                left_index = store.top();
            }
            int width=right_index-left_index-1;
            maxArea=max(maxArea,width*height);
            // cout<<index<<" "<<height*width<<" "<<endl;
            

        }
        store.push(i);
    }
    return maxArea;
}
int main()
{
    int n;
    cin>>n;
    vector<int> area(n);
    for(int i=0; i<n; i++){
       cin>> area[i];
    }
    cout<<largest_rectangle(area)<<endl;

    return 0;
}