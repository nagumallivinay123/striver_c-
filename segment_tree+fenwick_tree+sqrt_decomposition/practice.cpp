#include<bits/stdc++.h>
using namespace std;

class SegTree{
    public:
    vector<int>seg;
    vector<int>lazy;
    SegTree(int n){
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void build(int index,int low,int high,vector<int>&given){
        if(low==high){
            seg[index]=given[low];
            return;
        }
        int mid=(low+high)>>1;
        build(2*index+1,low,mid,given);
        build(2*index+2,mid+1,high,given);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    void update(int index,int low,int high,int val,int at){
        if(low==high){
            if(low==at){

             seg[index]=val;
            }
            return;
        }
        int mid=(low+high)>>1;
        if(at<=mid){

        update(2*index+1,low,mid,val,at);
        }
        else{
          update(2*index+2,mid+1,high,val,at);
        }
        seg[index]=seg[2*index+1]+seg[2*index+2];
        
    }
    int query(int index,int low,int high,int given_l,int given_r)
    {

        if(lazy[index]!=0)
        {
            seg[index]+=((high-low)+1*lazy[index]);
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
            lazy[index]=0;
        }
        //noting commong or  no overalapping at all




         if(high<given_l || low>given_r){
            return 0;
         }


        //complete overlapping 
        if(given_l<=low && high<=given_r){
            return seg[index];
        }



        //partial overlapping 
        int mid=(low+high)>>1;
        int a=query(2*index+1,low,mid,given_l,given_r);
        int b=query(2*index+2,mid+1,high,given_l,given_r);
       return a+b;
    }
    void range_update(int index,int low,int high,int given_l,int given_r,int val)
    {
        if(lazy[index]!=0)
        {
            seg[index]+=((high-low)+1*lazy[index]);
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
            lazy[index]=0;
        }
        //not overlapping  
        if(high<given_l || low>given_r){
            return;
         }



         if(given_l<=low && high<=given_r){
            seg[index]+=val*(high-low+1);

            if(low!=high){

            lazy[2*index+1]+=val;
            lazy[2*index+2]+=val;

            }

            return;
        }



        //partial overlapping 
        int mid=(low+high)>>1;
        range_update(2*index,low,mid,given_l,given_r,val);
        range_update(2*index+1,mid+1,high,given_l,given_r,val);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    
};

class Fenwick {
    //1 based indexing nunchde start avutundi fenwick tree lo 
    public:
    vector<int>fen;
    Fenwick(int n){
       fen.resize(n+1,0); 
    }
    void update(int given_index,int val){
      //echchina index ni 1 based indexing gaa marchali 
      int index=given_index+1;
      int n=fen.size();
      while(index<n){
         fen[index]+=val;
         int some=index&(-index);
         index=index+some;
      }
    }
    int sum(int given_index){
        int index=given_index+1;
        int ans=0;
        while(index>0){
            ans+=fen[index];
            int some=index&(-index);
            index=index-some;
        }
        return ans;

    }
    int query(int given_l,int given_r){
        return sum(given_r)-sum(given_l-1);
    }
    void build(vector<int>&arr){
        for(int i=0;i<arr.size();i++){
            update(i,arr[i]);
        }

    }
};
int main(){
    vector<int>a;
    for(auto i=1;i<=10;i++){
       a.push_back(i);
    }
    int n=a.size();
    Fenwick some(n);
    some.build(a);
    cout<<(7&(-7))<<"\n";
    cout<<some.query(0,4)<<endl;
    cout<<some.query(5,9)<<endl;
    cout<<some.query(8,8)<<endl;

    some.update(8,10-9);
    cout<<some.query(8,8)<<endl;
    cout<<some.query(0,9)<<endl;
return 0;
}