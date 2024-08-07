#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //instial gaa deniki kuda next greater undadu ani anukuntamu 
    vector<int>nge(n,-1);
    //stack lo indexes matrame store chestamu 
    stack<int>store;
    
    //my apporach //ekkada stack eppudu increasing order lo store ayyi untadi   
    for(int i=0; i<n; i++)
    {
        while(!store.empty() && v[store.top()]<v[i])
        {
            nge[store.top()]=i;
            store.pop();
        }
        store.push(i);
    }
    for(int i=0; i<n; i++){
        if(nge[i]==-1){
            cout<<nge[i]<<" ";
        }
        else{
            cout<<v[nge[i]]<<" ";
        }
    }

return 0;
}