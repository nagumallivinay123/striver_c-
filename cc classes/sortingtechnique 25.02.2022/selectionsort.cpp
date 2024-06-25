#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int ind = i;
        for (int j = i + 1; j < n; j++)
        {
            ind = j;
        }
        swap(a[i], a[ind]);
    }

    return 0;
}