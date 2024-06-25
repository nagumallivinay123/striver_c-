#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
using namespace std;
const int n = 1000;
vector<vector<int> > vertex(n);
vector<bool> check(n, false);
//ekkada levels endhuku rastunnamu ante avi shortest distance ki useful avutayi
//eppudaina depth first search ki binary search ki difference rayali
vector<int>level(n,0);
void bfs(int vertext)
{
    queue<int> q;
    q.push(vertext);
check[vertext]=true;

    while (!q.empty())
    {
        int p=q.front();
        cout<<p<<" ";
        q.pop();
        for(int i=0;i<vertex[p].size();i++){
            if(check[vertex[p][i]]!=true){
                level[i]=level[p]+1;
                check[vertex[p][i]]=true;
                q.push(vertex[p][i]);
            }
        } 
    }
}
int main()
{
    int no_of_edges;
            cin >>no_of_edges;
    for (int i = 0; i < no_of_edges; i++)
    {
        int a, b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    bfs(1);
    

    return 0;
}