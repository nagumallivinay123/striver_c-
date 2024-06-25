#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ones[3];
        ones[0] = 0;
        ones[1] = 0;
        ones[2] = 0;
        int x;
        cin >> x;
        int arr[x];

        for (int i = 0; i < x; i++)
        {
            cin >> arr[i];
            ones[1 + arr[i]]++;
        }
        if (ones[0] ==x - 2)
        {
            cout << "YES" << endl;
        }
        else if (ones[2] == x - 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
