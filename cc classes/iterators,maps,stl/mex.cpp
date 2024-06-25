// mex ante enti ante oka sequence lo first non negaitive integer that should not be present in the sequence.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int arr1[100001];
int main(){
    //arr[5]=1 5 6 0 4 
    //mex of arr[5]=0 0 0 2 2 
    int arr[5]={1,5,6,0,4};
    for(int i=0;i<5;i++){
        arr1[arr[i]]++;
        for(int j=0;j<5;j++){
            if(arr1[j]==0)
            {
                cout<<j<<endl;
                break;
            }
        }
    }
    


return 0;}