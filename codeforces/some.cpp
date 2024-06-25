#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+4,vector<int>(m+4,0));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }    
    }
    n=n+4;
    m=m+4;
    int k,l;
    cin>>k>>l;
    map<pair<int,int>,int >filter;
    for(int i=0;i<k;i++){
        for(int j=0;j<l;j++){
            int a;
            cin>>a;
        filter[{i,j}]=a;
        }
    } 
    //erosion 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ans=-1;
            
            for(auto it:filter){
                int add1=it.first.first;
                int add2=it.first.second;
                int some1=add1+i;
                int some2=add2+j;
                if(some1<0 || some2<0 || some1>=n || some2>=m ){
                    continue;
                }
                int few=v[some1][some2];
                int some=it.second;
                if(some==1)
                {
                    if(ans==-1){
                        ans=1;
                    }
                    ans&=(some&few);

                }
            }
               if(i<n-4 && j<m-4){

        
            if(ans==-1){
                cout<<0<<" ";
            }
            else{
            cout<<ans<<" ";
            }
        }
        }
        
        cout<<"\n";
    }


    //dilation 

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         int ans=-1;
            
    //         for(auto it:filter){
    //             int add1=it.first.first;
    //             int add2=it.first.second;
    //             int some1=add1+i;
    //             int some2=add2+j;
    //             if(some1<0 || some2<0 || some1>=n || some2>=m ){
    //                 continue;
    //             }
    //             int few=v[some1][some2];
    //             int some=it.second;
    //             if(some==1)
    //             {
    //                 if(ans==-1){
    //                     ans=0;
    //                 }
    //                 ans|=(some&few);

    //             }
    //         }
    //     if(i<n-4 && j<m-4){

        
    //         if(ans==-1){
    //             cout<<0<<" ";
    //         }
    //         else{
    //         cout<<ans<<" ";
    //         }
    //     }
    //     }
    //     cout<<"\n";
    // }





return 0;}