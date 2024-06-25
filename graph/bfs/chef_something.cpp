#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int rows, int columns)
{
    if (x < rows && y < columns && x > -1 && y > -1)
    {
        return true;
    }
    return false;
}
int check2(char a, char b)
{
    if (a == b)
    {
        return 0;
    }
    return 1;
}
int bfs_zero_one_based(int rows, int columns, vector<string> &v)
{
    int startx = 0;
    int starty = 0;
    deque<pair<int, int> > q;
    q.push_back(pair<int, int>(startx, starty));
    int vertex[rows][columns];
    int level[rows][columns];
    vector<pair<int, int> > movements;
    movements.push_back(pair<int, int>(0, -1));
    movements.push_back(pair<int, int>(0, 1));
    movements.push_back(pair<int, int>(1, 0));
    movements.push_back(pair<int, int>(-1, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            vertex[i][j] = 0;
            level[i][j] = 2000;
        }
    }
    vertex[startx][starty] = 0;
    level[startx][starty] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop_front();
        // cout << "{" << v[p.first][p.second] << "} "
        //      << "\n";

        for (int i = 0; i < movements.size(); i++)
        {
            int destx = p.first + movements[i].first;
            int desty = p.second + movements[i].second;
            if (check(destx, desty, rows, columns))
            {
                int vin = check2(v[destx][desty], v[p.first][p.second]);
                if (level[p.first][p.second] + vin < level[destx][desty])
                {
                    level[destx][desty] = level[p.first][p.second] + vin;

                    if (vin == 1)
                    {
                        q.push_back(pair<int, int>(destx, desty));
                        vertex[destx][desty] = 1;
                    }
                    else
                    {
                        q.push_front(pair<int, int>(destx, desty));
                        vertex[destx][desty] = 1;
                    }
                }
            }
        }

        if (level[rows - 1][columns-1] != 2000)
        {
            break;
        }
    }
    return level[rows - 1][columns - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<string> v;
        for (int i = 0; i < r; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        cout << bfs_zero_one_based(r, c, v) << "\n";
    }

    return 0;
}