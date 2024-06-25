#include <bits/stdc++.h>
using namespace std;
vector<map<int,int>> tree;
vector<long long> tree2;
void update(int node,int nl,int nr,int l,int r,int y,int pre){
    if(l>nr or r<nl)return;
    if(l<=nl and r>=nr){
        tree[node][y]++;
        tree[node][pre]--;
        return;
    }
    int mid=(nl+nr)>>1;
    update(2*node,nl,mid,l,r,y,pre);
    update(2*node+1,mid+1,nr,l,r,y,pre);
    tree[node][y]++;
    tree[node][pre]--;
    tree2[node]=tree[2*node].size()+tree[2*node+1].size()+tree[node].size();
}
long long query(int node,int nl,int nr,int l,int r){
    if(l>nr or r<nl)return 0;
    if(l<=nl and r>=nr)return tree2[node];
    int mid=(nl+nr)>>1;
    return query(2*node,nl,mid,l,r)+query(2*node+1,mid+1,nr,l,r);
}
vector<long long> findScore(int n, int q, vector<int> &vv, vector<vector<int>> &queries) {
    // Write your code here.
    int al=n;
    vector<int> v=vv;
    while(__builtin_popcount(n)!=1){
        n++;
        v.push_back(0);
    }
    vector<long long> ans;
    tree.resize(2*n);
    tree2.resize(2*n);
    for(int i=0;i<n;i++){
        tree[i+n][v[i]]++;
        tree2[i+n]++;
    }
    for(int i=n-1;i>=1;i--){
        for(auto x:tree[2*i])tree[i][x.first]++;
        for(auto x:tree[2*i+1])tree[i][x.first]++;
        tree2[i]=tree[i].size()+tree[2*i+1].size()+tree[2*i].size();
    }
    for(int i=0;i<q;i++){
        int x=queries[i][0];
        int y=queries[i][1];
        update(1,0,n-1,x,x,y,v[x]);
        v[x]=y;
        ans.push_back(query(1,0,n-1,0,al-1));
    }
    return ans;

}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>> queries(q);
    for(int i=0;i<q;i++)cin>>queries[i][0]>>queries[i][1];
    vector<long long> out=findScore(n,q,v,queries);
    for(auto x:out)cout<<x<<" ";cout<<endl;
}