#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//doubt vaste striver master class on segment tree chudu -> https://www.youtube.com/watch?v=NEG-SoyigGE
//ekkada segment tree annadi echchind range minimum find chestundi 
//segment tree endhuku 
//range queries avi find out cheyadaniki segment trees anevi avasaram 
class SGTree{
    //seg annadi private lo untaadi 
    vector<int>seg;
    public:

    SGTree(int n){
        //array size n unteh segment size annadi 4*n undali 

        seg.resize(4*n+1);
    }
    //segment tree built cheyadaniki 
    //segment tree building time complexity o(4*n)
    //O(4*n) size node fill chestunnavu 
    void build(int index,int low,int high,int arr[]){
        //base case 
        if(low==high){
            seg[index]=arr[low];
            return ;
        }
        int mid=(low+high)/2;
        //tree lo index ki left index 2*index+1
        build(2*index+1,low,mid,arr);
        //tree lo index ki right index 2*index+2;
       build(2*index+2,mid+1,high,arr);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }

    void update(int index,int low,int high,int given_update_index,int val){
       //it is base case 
       //given_update_array index reach ayipoyavu ani ardam, so value update  chestavu
        if(high==low){
        seg[index]=val;
        return ;
        }
        int mid=(low+high)>>1;
        if(given_update_index<=mid){
            update(2*index+1,low,mid,given_update_index,val);
        }
        else{
            update(2*index+2,mid+1,high,given_update_index,val);
        }
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
    int query(int index,int low,int high,int given_l,int given_r){

        //no overlap
        //[given_l given_r][low high] or [low high][given_l given_r]
        if(given_r<low || high<given_l){
            return INT_MAX;
        }
        //complete overlap 
        //[given_l low high given_r]
        if(given_l<=low && high<=given_r){
            return seg[index];
        }
        int mid=(low+high)/2;
        int left=query((2*index+1),low,mid,given_l,given_r);
        int right=query((2*index+2),mid+1,high,given_l,given_r);
        return min(left,right);
        //partial overlap 
    
    }
    void print(){
        for(auto it:seg){
            cout<<it<<" ";
        }
    }

};
int main(){
    int n1,n2;
    cin>>n1;
    int arr1[n1];
    SGTree sg1(n1);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
        // cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    sg1.build(0,0,n1-1,arr1);
    // sg1.print();
    cin>>n2;
    int arr2[n2];
    SGTree sg2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
        // cout<<arr2[i]<<" ";
    }
    sg2.build(0,0,n2-1,arr2);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        
        //type=2 anteh kevalam updation 
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int mini1=sg1.query(0,0,n1-1,l1,r1);
            int mini2=sg2.query(0,0,n2-1,l2,r2);
            cout<<min(mini1,mini2)<<"\n";
            // cout<<" type -1 ";
        }
        else{
            int type_arr,index,val;
            cin>>type_arr>>index>>val;
            // cout<<"type_2";
            if(type_arr==1){
                arr1[index]=val;
                
                sg1.update(0,0,n1-1,index,val);
            }
            else{
                arr2[index]=val;
                sg2.update(0,0,n2-1,index,val);
            }
        }
    }



return 0;}