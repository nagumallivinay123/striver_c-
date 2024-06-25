#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int a[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int t = 0; t < n; t++)//ekkada neeku doubt vastadi first time run chesinappudu large number end ki velutundi
    //second time run chesinappu 2nd largerst number prefinal ki velutundi
    //  
    {
        for (int j = 0; j < n - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    return 0;
}