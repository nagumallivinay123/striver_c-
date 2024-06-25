#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// balanced_parenthesis {[()]} edi balanced ayyinda leda check chestamu ade vidanga
string isbalance(string s)
{
    stack<char> stk;
    unordered_map<char,char>m;
    m[']']='[';
    m['}']='{';
    m[')']='(';
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{'||s[i] == '(')
        {
            stk.push(s[i]);
        }
        else
        {

            if (m[s[i]] == stk.top())
            {
                stk.pop();
            }
            else
            {
                break;
            }
        }
    }
    if (i == s.length())
    {
        string p = "YES";
        return p;
    }
    else
    {
        string p = "NO";
        return p;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << isbalance(s) << endl;
    }

    return 0;
}