#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int>::iterator ptr = lower_bound(a.begin(), a.end(), 5);
    if (ptr == a.end())
    {
        cout << "NOT FOUND";
    }
    else
    {
        cout << *ptr << endl;
    }
    //mapssets lo lower bound mariyu upper bound kavali ante avvadu ela cheyali ante maps.lower_bound sets.upper_bounds

    return 0;
}