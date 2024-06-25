#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//edhi main gaa cp lo vadatamu 
//kadane algorithm 
//sub array sum lo ekkuva vadatamu 
// actual o(N^2 ) lo jarige annitini o(N) lo jarigela chestundi 
//main gaa max subarray calculate cheyadaniki vadtamu main gaa 
long long maxSubarraySum(int arr[],int size){
    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
            continue;
        }
    }
    return ans;
}

int main(){
int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;


return 0;}