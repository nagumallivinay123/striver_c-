#include<bits/stdc++.h>
using namespace std;

void striver_approach_next_smaller_element(vector<int>&v,int n){
    
    vector<int>nse(n,-1);
    stack<int>store;
    for(int i=n-1; i>=0; i--)
    {
        while(!store.empty() && v[store.top()]>=v[i]){
            
            store.pop();
        }
        if(store.empty()){
           nse[i]=-1;
        }
        else
        {
            nse[i]=store.top();

        }
        store.push(i);
    }
    for(int i=0;i<n;i++)
    {
        if(nse[i]==-1){
            cout<<nse[i]<<" ";
        }
        else{
            cout<<v[nse[i]]<<" ";
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //nse next smaller element 
    vector<int>nse(n,-1);
    //nse lo index store chesta //last lo v lo  index taluka value  kannukunta   
    //stack lo manam always store index  in general    
     //stack lo ekkada increasing order lo store ayyi untayi 
     //dry run chesi 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    stack<int>store;
    for(int i=0; i<n; i++)
    {
        while(!store.empty() && v[store.top()]>v[i]){
            nse[store.top()]=i;
            store.pop();
        }
        store.push(i);
    }
    for(int i=0;i<n;i++){
        if(nse[i]==-1){
            cout<<nse[i]<<" ";
        }
        else{
            cout<<v[nse[i]]<<" ";
        }
    }
    cout<<"\n";
    striver_approach_next_smaller_element(v,n);
return 0;
}