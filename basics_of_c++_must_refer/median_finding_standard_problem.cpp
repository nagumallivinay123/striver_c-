
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class median_set
{
private:
    set<pair<int, int>> Front;
    int front_count = 0;
    int back_count = 0;
    set<pair<int, int>> Back;

public:
    // Default constructor

    void input(pair<int, int> a)
    {
        if (front_count == 0)
        {
            Front.insert(a);
            front_count++;
            return;
        }
        int val = prev(Front.end())->first;
        int comp = a.first;
        if (comp < val)
        {
            Front.insert(a);
            front_count++;
        }
        else
        {
            Back.insert(a);
            back_count++;
        }
        if (front_count > back_count + 1)
        {
            auto it = prev(Front.end());
            Back.insert(*(it));
            Front.erase(it);
            front_count--;
            back_count++;
        }
        else if (back_count > front_count)
        {
            auto it = Back.begin();
            Front.insert(*(it));
            Back.erase(it);
            front_count++;
            back_count--;
        }
    }

    void delete_input(pair<int, int> a)
    {
        if (Front.find(a) != Front.end())
        {
            Front.erase(a);
            front_count--;
        }
        if (Back.find(a) != Back.end())
        {
            Back.erase(a);
            back_count--;
        }
        if (back_count > front_count)
        {
            auto it = Back.begin();
            Front.insert(*it);
            Back.erase(it);
            front_count++;
            back_count--;
        }
        else if (back_count + 1 < front_count)
        {
            auto it = prev(Front.end());
            Back.insert(*(it));
            Front.erase(it);
            front_count--;
            back_count++;
        }
        // cout<<f<<s<<"\n";
    }

    double median()
    {
        if (front_count == back_count)
        {
            auto it1 = prev(Front.end());
            auto it2 = Back.begin();
            return (it1->first * 1.0 + it2->first * 1.0) / 2.0;
        }
        else
        {
            return Front.rbegin()->first * 1.0;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    median_set some;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int N = arr[0];
    string ans = "";
    int r = 1;
    int l = 1;
    while (r < n)
    {
        some.input({arr[r], r});
        int a = some.median();
        if (ans == "")
        {
            ans += to_string(a);
        }
        else
        {
            ans += "," + to_string(a);
        }
        r++;
        if (r - l > N)
        {
            some.delete_input({arr[l], l});
            l++;
        }
    }
    cout << ans << " ";

    return 0;
}