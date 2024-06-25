#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++){
cin>>arr[i];
}
int count =0;
for(int i=0; i<n; i++){
    for(int j=i+1;j<n;j++)
    {
        if(arr[i]>arr[j]){
            if(j>i){
                count++;
            }
        }
    }
}
cout<<count<<endl;
//given an array a of size n . Find the number of indexes j<i such that a[j]>a[i].


return 0;}