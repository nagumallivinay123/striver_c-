#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> vin;
    vin.push_back(3);
    vin.push_front(2);
    vin.push_front(5);
    vin.reverse();
    vin.pop_front();
    vin.pop_back();
    list<int>::iterator it;
    for (it = vin.begin(); it != vin.end(); it++)
    {
        cout << *it << "\n";
    }
    return 0;
}