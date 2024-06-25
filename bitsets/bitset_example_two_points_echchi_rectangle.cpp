#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// https :// practice.geeksforgeeks.org/contest/gfg-weekly-158-rated-contest/problems lo 4 th question
// neeku konni(like 1000) 2-D points echchesadu
// neeku andhulo evaina two 2-D points adhi rectangel form cheste aa madyalo enni points vastayi dani count enta annadi kannukovali
int main()
{
    int n;
    int queries;
    int k;
    cin >> n >> k >> queries;
    vector<vector<int>> points(n, vector<int>(2, -1));

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        points[i][0] = a;
        points[i][1] = b;
    }
    bitset<1000> up[n + 1];
    bitset<1000> down[n + 1];
    for (int i = 0; i < n; i++)
    {
        int x = points[i][0];
        int y = points[i][1];

        for (int j = 0; j < n; j++)
        {
            int x1 = points[j][0];
            int y1 = points[j][1];
            if (i == j)
            {
                continue;
            }
            else if (x1 > x && y1 < y)
            {
                down[i][j] = 1;
            }
            else if (x1 < x && y1 > y)
            {
                up[i][j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < queries; i++)
    {
        int index1, index2;
        cin >> index1 >> index2;
        bitset<1000> temp = down[index1] & up[index2];
        int ans = temp.count();
        cout << ans << "\n";
    }

    return 0;
}