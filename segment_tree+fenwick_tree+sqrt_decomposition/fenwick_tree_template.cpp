#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//reference -1 luv-> https://www.youtube.com/watch?v=DPiY9wFxGIw
//reference-2  striver-> https://www.youtube.com/watch?v=9uaXG62Y8Uw

//fenwick tree baaga ravaali anteh right most bit value logic teliyali  
//fenwick or binary index trees ayina kuda annachchu 
//right most bit easy kannukovali oka echchina x value lo  
//a1b annandi binary number of x anukuntueh 
//b-> anni zero vachchayi 

//-x annadi complement (a`0b`+1)

//*** right_most bit value = x&(-x) ****
// x-(x&-x)enti antheh right most bit value teesinadhi 

//fenwick tree okka array annadi 1 based indexing 

//fenwick tree lo unna each array element emi store chestundi 
//fen[i] stores summation of [j+1 i] elements  where   j=i-(i&-i);
//fen[4] stores summation of [1 4] elements where j=4-(4&-4)-> j=0 



//why we are preferring fenwick over segment trees because size of segmented is o(n) is fenwick tree whereases segment tree size is o(4*n)
class fenwicktree{
    vector<int>fen;
    int n;
    public:
    fenwicktree(int N){
        n=N;
        fen.resize(N+1,0)  ;
    }
    void build(int arr[]){
        for(int i=0;i<n;i++){
           update(i+1,arr[i]);
        }
    }
    //pass only 1 based indexing
    //update passing val should be either increased value  of element at that index or decreased value of that element 
    //time complexity of update is also o(logN)
    void update(int index,int val)
    {
        while(index<=n)
        {
            fen[index]+=val;
            //this logic **imp***
            index=index+(index&(-index));
        }
        return;
    }
//pass only 1 based indexing 
//time of complexity of sum is o(logN )
    int sum(int index){
        int ans=0;
        while(index>0){
            ans+=fen[index];
            //this logic *** imp***
            index=index-(index&(-index));
        }
        return ans;

    }
    int range_sum(int left ,int right){
        return sum(right)-sum(left-1);
    }
    void print(){
        for(int i=1;i<=n;i++)
        {
            int j=i-(i&(-i));
            cout<<i<<") L = "<<j+1<<" "<<"R = "<<i<<" "<<"val = "<<fen[i]<<"\n";
        }
    }
    //fenwick tree lo binary tree lifting  reference -> strivers-> https://www.youtube.com/watch?v=nuUspQ7ORXE

    //fenwick tree lo binary lifting untundi 
//edhi summation lower bound find out cheyadaniki use avutundi
int find_lower_bound(int given_val)
{
    int curr=0,prev_sum=0;
    for(int i=log(n);i>=0;i--){
        if(fen[curr+(1<<i)]+prev_sum<k){
            prev_sum+=fen[curr+(1<<i)];
            curr+=(1<<i);   
        }
    }
    //returning 1 based index after adding it 
    return curr+1;

}

};




int main(){
    int n;
    cin>>n;
    int arr[n];
    fenwicktree ft(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ft.build(arr);
    ft.print();
    ft.update(1,1);
    cout<<"after update "<<"\n";
    ft.print();
    cout<<ft.range_sum(1,5)<<"\n";




return 0;}