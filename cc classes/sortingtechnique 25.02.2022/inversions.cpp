#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    vector<vector<int> > a;
    a.push_back(v);
    for (int i = 0; i < n; i++)
    {

        for (int j = i+1; j < n; j++)
        {
            vector<int> t;
            t = v;
            swap(t[i], t[j]);
            a.push_back(t);
        }
    }
    sort(a.begin(), a.end());
    for(int i=0;i<a.size();i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
    
        cout<<endl;
    }
    cout<<a.size()<<endl;
}
