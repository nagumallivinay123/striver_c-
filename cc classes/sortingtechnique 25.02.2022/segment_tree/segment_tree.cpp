//elaithe merge sort lo divide chestamo adhevidanga  
//alane ekkada kuda segment 
//deeniki code ela rayalante segment tree diagram teesukuni ravali
#include<iostream>
#include<bits/stdc++.h>
int tree[10000];
int a[];
//okavela neeku a array lo n elements unte 4*n elements tree lo maximum anne untayi
void build (int node,int start ,int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        int mid=(start +end)/2;
        build(2*node,start,mid);
        build(2*node,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    //edhi nlogn lo avutundi
}
//ee segment tree endhuku ante 
void node_change(int node,int start ,int end,int index_change_arr,int change_number){
    if(start<=index_change_arr & & index_change_arr<=end){
        if(start==end){
            tree[node]=change_number;
        }
        else{
            int mid=(start+end)/2;
            node_change(2*node,start,mid,index_change_arr,change_number);
            node_change(2*node+1,mid+1,end,i;ndex_change_arr,change_number);
            tree[node]=tree[2*node+1]+tree[2*node];
        }
    }
    //edhi logn lo avutundi
}
int sum_l_to_right(int node,int start,int end,int left,int right){
    if(right<start || left>end ){
        return 0;
    }
    if(left<=start && end<=right)return tree[node];
    
}
using namespace std;
int main(){



return 0;}
