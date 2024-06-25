// inversion count i<j unteh ,arr[j]<arr[i] ayithe danni inversion count antamu
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//board meeda explain chesukuni rasukunnavu
int merge(vector<int> &a, int left, int mid, int right)
{
    vector<int> temp(right - left + 1);
    int left_point = left;
    int right_point = mid + 1;
    int count = 0;
    int k = 0;
    while (left_point <= mid && right_point <= right)
    {
        if (a[left_point] <= a[right_point])
        {
            temp[k] = a[left_point];
            k++;

            left_point++;
        }
        else
        {
            temp[k] = a[right_point];
            k++;
            count += (mid - left_point + 1);
            right_point++;
        }
    }
    while (left_point <= mid)
    {
        temp[k] = a[left_point];
        k++;
        left_point++;
    }
    while (right_point <= right)
    {
        temp[k] = a[right_point];
        k++;
        right_point++;
    }
    k = 0;
    for (int i = left; i <= right; i++)
    {
        a[i] = temp[k];
        k++;
    }
    return count;
}
int mergeSort(vector<int> &a, int left, int right)
{
    if (left < right)
    {

        int mid = (left + right) / 2;
        int ans = mergeSort(a, left, mid);
        ans += mergeSort(a, mid + 1, right);
        ans += merge(a, left, mid, right);
        return ans;
    }
    return 0;
}

int numberOfInversions(vector<int> &a, int n)
{

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> a;
    for(int i=5;i>=1;i--){
        a.push_back(i);
    }
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}