#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//ekkada summation segment tree 
//summation segment tree anteh range of[L R ] nunchi summation of that array teesukuntamu 
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
        seg[index]=(seg[2*index+1]+seg[2*index+2]);
    }

    void update(int index,int low,int high,int given_update_index,int val){
       //it is base case 
       //given_update_array index reach ayipoyavu ani ardam, so value update  chestavu
        if(high==low){
        seg[index]+=val;
        return ;
        }
        int mid=(low+high)>>1;
        if(given_update_index<=mid){
            update(2*index+1,low,mid,given_update_index,val);
        }
        else{
            update(2*index+2,mid+1,high,given_update_index,val);
        }
        seg[index]=(seg[2*index+1]+seg[2*index+2]);
    }
    int query(int index,int low,int high,int given_l,int given_r){

        //no overlap
        //[given_l given_r][low high] or [low high][given_l given_r]
        if(given_r<low || high<given_l){
            return 0;
        }
        //complete overlap 
        //[given_l low high given_r]
        if(given_l<=low && high<=given_r){
            return seg[index];
        }
        int mid=(low+high)/2;
        int left=query((2*index+1),low,mid,given_l,given_r);
        int right=query((2*index+2),mid+1,high,given_l,given_r);
        return left+right;
        //partial overlap 
    
    }
    void print()
    {
        for(auto it:seg)
        {
            cout<<it<<" ";
        }
    }


};
int merge(int low,int mid,int high,int arr[]){
    //base case 
    if(low==high){
        return 0;
    }
    int l_max=mid-low+1;
    int r_max=high-mid;
    int left[l_max];
    int right[r_max];
    int index=0;;
    for(int i=low;i<=mid;i++){
        left[index]=arr[i];
        index++;
    }
    index=0;
    for(int i=mid+1;i<=high;i++){
          right[index]=arr[i];
          index++;
    }
    int l=0,r=0;
    index=low;
    int inversion_count=0;
    while(l<l_max && r<r_max){
       if(left[l]<=right[r]){
        arr[index]=left[l];
        l++;
        index++;
       }
       else{
        arr[index]=right[r];
        inversion_count+=(l_max-l);
      
        r++;
        index++;
       }
    }

    while(l<l_max)
    {
        arr[index]=left[l];
        l++;
        index++;

    }
    while(r<r_max){
        arr[index]=right[r];
        r++;
        index++;
    }
    return inversion_count;
}
int  inversion_merge_sort(int low,int high,int arr[])
{
    if(high<=low){
        return 0;
    }
    int mid=(low+high)/2;
   int left= inversion_merge_sort(low,mid,arr);
    int right=inversion_merge_sort(mid+1,high,arr);
   int merging= merge(low,mid,high,arr);
   return left+right+merging;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=0;
    int inversion_count=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    maxi=maxi+1;
    int freq[maxi];
    memset(freq,0,sizeof(freq));
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    SGTree sg1(maxi);
    sg1.build(0,0,maxi,freq);
    for(int i=0;i<n;i++){
    sg1.update(0,0,maxi,arr[i],-1);
    inversion_count+=sg1.query(0,0,maxi,0,arr[i]-1);
    }
    cout<<inversion_count<<endl;

//example 
//n=6
// 6 5 4 3 2 1 
//ans=should be 15 

//inversion_count using mege_sort   ->neeku telusu 

    // cout<<inversion_merge_sort(0,n-1,arr)<<"\n";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    







return 0;}