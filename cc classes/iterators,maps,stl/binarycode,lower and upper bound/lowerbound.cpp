#include <iostream>
using namespace std;
// lower bound annadi emi evvaliante index annadhi evvali
//  okavela binary search lo aa key element array lo unte dani index evvali lekapothe
// dani next index aa key element kanna ekkuva unna element dhi return cheyali
int lowerbound(int arr[], int lower, int upper, int key)

{
    while(lower<upper){
        int mid=(lower+upper)/2;
        if(arr[mid]>=key){
            upper=mid;
        }
        else{
            lower=mid+1;
        }
    }
    return lower;
}
int upperbound(int arr[],int lower,int upper,int key){
    while(lower<upper){
        int mid=(lower+upper)/2;
        if(arr[mid]>key){
            upper=mid;
        }
        else{
            lower=mid+1;
        }
    }
    return lower;
}
int main()
{

    int arr[] = {1, 5, 5, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lowerbound(arr, 0, n - 1, 5) << endl;
    cout << upperbound(arr, 0, n - 1, 5) << endl;


    return 0;
}