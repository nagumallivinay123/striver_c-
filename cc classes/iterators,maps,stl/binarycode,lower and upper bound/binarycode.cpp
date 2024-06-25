//sorted array 
// pradiate function // oka daggari nunchi anni true ayithe onko daggira nunchi anni false avutayi
#include<iostream>
using namespace std;
//lower=0 // upper=n-1 //key=5(neeku vetukovalli anna number)
int binarysearch(int arr[],int lower,int upper,int key){
    int mid=(lower+upper)/2;
    if(arr[mid]==key){return mid;}
    if(arr[mid]>key){
        upper=mid-1;
        return binarysearch(arr,lower,upper,key);
    }
    else{
        lower=mid+1;
        return binarysearch(arr,lower,upper,key);
    }

}
int main(){
    int arr[]={1,2,4,5,7,9,0};
    int n=sizeof(arr)/sizeof(arr[0]);
   cout<< binarysearch(arr,0,n-1,5);




return 0;}