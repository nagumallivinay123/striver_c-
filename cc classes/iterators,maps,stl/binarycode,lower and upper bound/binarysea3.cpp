// euler totient function;
// given a number N find number such that x and n are coprime in each other
// dinni kosam oka
#include <iostream>
using namespace std;
bool check(long long mid, long long num)
{
    long long divide = 5;
    long long function = 0;
    while (divide <= mid)
    {
        function += mid / divide;
        divide *= 5;
    }
    if (function >= num)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long num;
        cin >> num; // Reading input from STDIN
        long long lower = 1, upper = 5 * num;
        long long ans;
        while (lower <= upper)
        {
            long long mid = (lower + upper) / 2;
            if (check(mid, num) == true)
            {
                ans = mid;
                upper = mid - 1;
            }
            else
            {
                lower = mid + 1;
            }
        }
        cout << ans << endl;
    }
}