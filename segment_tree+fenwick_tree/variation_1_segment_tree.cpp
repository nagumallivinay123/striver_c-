#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// codeforce segment variation problem -> https://codeforces.com/contest/339/problem/D

class SGTree{
    vector<int>seg;
    public:
    SGTree(int n){
        seg.resize(4*n+2);
    }
    void build(int index,int low,int high,int arr[],bool even)
    {
        //base condition 
         if(low==high){
            seg[index]=arr[low];
            return ;
         }
         int mid=(low+high)>>1;
          build(2*index+1,low,mid,arr,!even);
          build(2*index+2,mid+1,high,arr,!even);
         if(even==true){
           
            seg[index]=seg[2*index+1]^seg[2*index+2];
         }
         else{
            seg[index]=seg[2*index+1]|seg[2*index+2];
         }
         return ;
    }
    void update(int index,int low,int high ,int given_index,int val,bool even)
    {  
        if(low==high){
            seg[index]=val;
            return ;
        }
        int mid=(low+high)/2;
        if(given_index<=mid){
            update(2*index+1,low,mid,given_index,val,!even);
        }
        else
        {
            update(2*index+2,mid+1,high,given_index,val,!even);
        }

         if(even==true){
           
            seg[index]=seg[2*index+1]^seg[2*index+2];
         }
         else{
            seg[index]=seg[2*index+1]|seg[2*index+2];
         }
         return ;


    }
    void print()
    {
        cout<<seg[0];
    }
};
int main(){
int n,m;
cin>>n>>m;
int N=pow(2,n);
int arr[N];
SGTree sg1(N);
for(int i=0;i<N;i++){
    cin>>arr[i];
}
bool even=true;
if((n&1)==1){
    even=false;
}
sg1.build(0,0,N-1,arr,even);
while(m--){
    int index,val;
    cin>>index>>val;
    index=index-1;
    sg1.update(0,0,N-1,index,val,even);
    sg1.print();
    cout<<"\n";
}


return 0;}