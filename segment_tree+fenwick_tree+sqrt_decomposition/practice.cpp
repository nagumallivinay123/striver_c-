#include<bits/stdc++.h>
using namespace std;

class Fenwick{
    int n;
    vector<int>fn;
    public:
    Fenwick(int size){
     n=size+1;
     fn.resize(n+1,0);
    }
    void build(vector<int>&arr){
        for(int i=0;i<arr.size();i++){
           update(arr[i],i+1); 
        }
    }
    void update(int val,int index){
        while(index<=n)
        {
          fn[index]+=val;
          int right=(index & (-index));
          index+=(right);
        }
    }
    
    int sum(int end_index)
    {
        int ans=0;
        int index=end_index;
        while(index>0){
            ans+=fn[index];
            int right=index&(-index);
            index=index-(right);
        }
        return ans;
    }
    int range(int l,int r){
        return sum(r)-sum(l-1);
    }


    
};
int main(){
    vector<int>arr;
    for(int i=0;i<10;i++){
        arr.push_back(i+1);
    }
    Fenwick some(arr.size());
    some.build(arr);
    cout<<some.range(1,10)<<"\n";
    cout<<some.range(5,9)<<"\n";

return 0;
}