#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<vector<int> > divisors(n + 1);
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    for (int i =2; i <= n; i++)
    {
        for(int j=0;j<divisors[i].size();j++)
        cout<<divisors[i][j];
        cout<<endl;
    }
    

    return 0;
}