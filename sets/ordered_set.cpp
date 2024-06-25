#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        s.insert(st);
    }
    //multiset
    set<string>::iterator it;
    for (it=s.begin(); it != s.end(); it++)
    {
        cout << *it << endl;
    }
    multiset<string>b;
    //actual ga set lo rendo sari vachchina values allow cheyadu kani multiset lo allow chestundi

    b.insert("abc");
    b.insert("abc");
    b.insert("ghf");
    b.insert("dcd");
    b.insert("tfg");
    auto it=b.find("abc");
    if(it!=b.end()){
        b.erase(it);//ela iterator vadi cheste okasari okesari rendu value lu unte okate delete chestundi
        
    }
b.erase("abc");//ela rasemu ante mottamanni "abc lu unnivi ani delete ayipothayi kani";

    return 0;
}