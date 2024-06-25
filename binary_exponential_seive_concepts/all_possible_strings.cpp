#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void func(string s, string &temp, vector<string> &store, int n, int k)
{

    if (k > n)
    {

        return;
    }
    if(temp!=""){
        store.push_back(temp);
    }
    for (int i = k; i < n; i++)
    {
        string take=temp+s[i];
        func(s, take, store, n, i+1);
    }
    return;
}

int main()
{
    string s = "abc";
    int n = s.length();

    vector<string> store;
    string temp = "";
    func(s, temp, store, n, 0);
    for (int i = 0; i < store.size(); i++)
    {
        cout << store[i] << " ";
    }

    return 0;
}