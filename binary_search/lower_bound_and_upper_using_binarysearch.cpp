#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int lower_bound_binary_search(vector<int> v, int key)
{
    int lower = 0;
    int upper = v.size() - 1;
    while (upper - lower > 1)
    {
        int mid = (upper + lower) / 2;
        if (v[mid] < key)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }
    if (v[lower] >= key)
    {
        return lower;
    }
    if (v[upper] >= key)
    {
        return upper;
    }
    return -1;
}
int upper_bound_binary_search(vector<int> v, int key)
{
    int lower = 0;
    int upper = v.size() - 1;
    while (upper - lower > 1)
    {
        int mid = (upper + lower) / 2;
        if (v[mid] <= key)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid;
        }
    }
    if (v[lower] > key)
    {
        return lower;
    }
    if (v[upper] > key)
    {
        return upper;
    }
    return -1;
}
//luv agarwal sir 
int  binary_search(int arr[],int lower,int upper,int key){
   while(upper-lower>1){
    int mid=(lower+upper)/2;
      if(arr[mid]<key){
lower=mid+1;
      }
      else{
        upper=mid;
      }
   }
   if(arr[lower]==key){
    return lower;
   }
   if(arr[upper]==key){
    return upper;
   }
   return -1;
}
void normal_binary_search(int arr[],int lower,int upper){

}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // ekkada manam lower bound mariyu upper_bound_of_element_find_chestunnamu_using_binary_search
    int index = lower_bound_binary_search(v, 3);
    int index1 = upper_bound_binary_search(v, 3);
    cout << "upper bound of 3 =" << v[index1] << endl;
    cout << "lower_bound of 3 = " << v[index] << endl;

    return 0;
}