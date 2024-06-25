#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(10, 1);
    vector<int> arr2(10, 1);
    // pass by reference lambda function & pettinappudu global scope untudi so main lo unni anni element andhuloki vachchestundii
    // pass by reference lo nuvvu edaina change chesukovachchu ..adhi change chesina function bayata ki vachchesariki maripothudi

    auto sum = [&]()
    {
        int sums = 0;

        for (auto it : arr)
        {
            sums += it;
        }
        arr[5] = 11;
        return sums;
    };
    cout << sum()
         << "\n";
    cout << arr[5] << "\n";

    // pass by value matrame edhi
    auto sum_2 = [=]()
    {
        int sum = 0;
        for (auto it : arr2)
        {
            sum += it;
        }
        return sum;
    };
    cout << sum_2()
         << "\n";
    cout << arr2[5] << "\n";

    return 0;
}