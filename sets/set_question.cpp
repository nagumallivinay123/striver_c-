#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            multiset<int>::iterator it;
            it = s.end();
            it--;
            int p = *it;
            sum += p;
            s.erase(p);
            s.insert(p / 2);
        }
        cout<<sum<<endl;
    }

    return 0;
}