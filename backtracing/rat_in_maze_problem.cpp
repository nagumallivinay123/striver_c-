#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool ispossible(int row, int column, int l, int r, vector<vector<int> > &mat)
{
    int n = mat.size();
    if (row + l < 0 || row + l > n)
    {
        return false;
    }
    if (column + r < 0 || column + r > n)
    {
        return false;
    }
    if (mat[row + l][column + r] == 0)
    {
        return false;
    }
    return true;
}

void function_n(int row, int column, vector<vector<int> > &mat, vector<vector<int> > &store, map<char,pair<int, int> > &mp, vector<string> &ans, vector<char> &temp)
{

    if (row >= mat.size() - 1 && column >= mat.size() - 1)
    {
        string p = "";
        for (int i = 0; i < temp.size(); i++)
        {
            p += temp[i];
        }
        ans.push_back(p);
        return;
    }

    map<char,pair<int, int> >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        int l = it->second.first;
        int r = it->second.second;
        if (ispossible(row, column, l, r, mat) && store[row + l][column + r] == 0)
        {
            store[row + l][column + r] = 1;
            temp.push_back(it->first);
            function_n(row + l, column + r, mat, store, mp, ans, temp);
            temp.pop_back();
            store[row + l][column + r] = 0;
        }
    }
}

int main()
{
    map<char,pair<int, int> > mp;
    mp['D'] = pair<int, int>(1, 0);
    mp['L'] = pair<int, int>(0, -1);
    mp['R'] = pair<int, int>(0, 1);
    mp['U'] = pair<int, int>(-1, 0);
    int n;
    cin >> n;
    vector<vector<int> > mat;
    for (int i = 0; i < n; i++)
    {
        vector<int> p;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            p.push_back(a);
        }
        mat.push_back(p);
    }
    vector<char> temp;
    vector<string> ans;
    vector<vector<int> > store(n, vector<int>(n, 0));
    store[0][0] = 1;
    // cout<<store.size()<<store[0].size()<<"\n";
    function_n(0, 0, mat, store, mp, ans, temp);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
