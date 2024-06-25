#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int count1 = 0;
    long long int count2min = LONG_MAX;
    long long int count3min = LONG_MAX;
    long long int other = 0;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            count1++;
        }
        else if (arr[i] % 2 == 0)
        {
            count2min = min(arr[i], count2min);
        }
        else if (arr[i] % 3 == 0)
        {
            count3min = min(arr[i], count3min);
        }
        else
        {
            other++;
        }
    }
    if (other > 1 && other < n)
    {
        cout << -1 << "\n";
    }
    else if (other == n)
    {
        cout << 0 << "\n";
    }
    else
    {
        long long int ans = 0;
        vector<long long int> something(n + 1, 0);
        for (long long int i = 0; i < n; i++)
        {
            long long int temper = arr[i];
            while (temper != 1)
            {
                if (temper % 2 == 0)
                {
                    temper = temper / 2;
                }
                else
                {
                    temper = temper / 3;
                }
                something[i] += 1;
            }
        }
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += something[i];
        }
        if (count1 > 0 || (count2min != LONG_MAX && count3min != LONG_MAX && count2min != count3min))
        {

            cout << sum << "\n";
        }
        else if (count2min != LONG_MAX && count3min == LONG_MAX)
        {
            long long worry = count2min;
            long long partial_s = 0;
            while (worry != 1)
            {
                if (worry % 2 == 0)
                {
                    worry = worry / 2;
                }
                else
                {
                    worry = worry / 3;
                }
                partial_s += 1;
            }
            cout << sum - n * partial_s << "\n";
        }
        else if (count3min != LONG_MAX)
        {
            long long worry = count3min;
            long long partials = 0;
            while (worry != 1)
            {
                if (worry % 2 == 0)
                {
                    worry = worry / 2;
                }
                else
                {
                    worry = worry / 3;
                }
                partials += 1;
            }
            return sum - n * partials << "\n";
        }
    }
    return 0;
}