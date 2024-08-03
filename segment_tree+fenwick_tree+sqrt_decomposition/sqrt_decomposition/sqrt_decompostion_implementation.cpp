#include<bits/stdc++.h>
using namespace std;
vector<int>store;
int blocksize;
int query(int l,int r,vector<int>&arr){
    int left_block=l/blocksize;
    int right_block=r/blocksize;
    int sum=0;
    if(left_block==right_block){
        for(int i=l;i<=r;i++){
            sum+=arr[i];
        }
    }
    else{
        for(int i=l;i<=((left_block+1)*blocksize-1);i++){
            sum+=arr[i];
        }
        for(int i=(left_block+1);i<=(right_block-1);i++){
            sum+=store[i];
        }
        for(int i=right_block*blocksize;i<=r;i++){
            sum+=arr[i];
        }
    }
    return sum;

}

void sqrt_decomposition(int n,vector<int>&arr){
     blocksize=sqrt(n)+1;
    store.resize(blocksize,0);
    for(int i=0;i<n;i++){
        store[i/blocksize]+=arr[i];
    }
}
int main(){
    int n=10;
    vector<int>arr(10,0);
    for(int i=0;i<10;i++){
        arr[i]=i+1;
    }
    sqrt_decomposition(n,arr);
    //o based indexing 
    cout<<query(2,9,arr);

    
return 0;
}