#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
#include <cstring>
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
using namespace std;
// bfs simple shortest distance vadadaniki chestaru
// bfs lo levels untayi danibatti manam shortest distance findout_chestamu
//
// chess board lo 8 *8 untayi kabatti
const int INF = 1000;
int vertex[8][8];
int level[8][8];

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vertex[i][j] = 0;
            level[i][j] = INF;
        }
    }
}
int getx(string s1)
{
    return (int)(s1[0] - 'a');
}
int gety(string s1)
{
    return (int)(s1[1] - '1');
}
bool isvalid(int x, int y)
{
    if ((x >= 0 && y >= 0) || (x < 8 && y < 8))
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector<pair<int, int> > movements;
int modified_bfs(string s1, string s2)
{
    int sourcex = getx(s1);
    int sourcey = gety(s1);
    int destx = getx(s2);
    int desty = gety(s2);
    queue<pair<int, int> > q;
    vertex[sourcex][sourcey] = 1;
    level[sourcex][sourcey] = 0;
    q.push(pair<int, int>(sourcex, sourcey));
    cout<<movements[4].first<<movements[4].second<<"\n";

    // while (!q.empty())
    // {
    //     pair<int, int> p = q.front();
    //     q.pop();
    //     for (int i = 0; i < movements.size(); i++)
    //     {
    //         int testx = p.first + movements[i].first;
    //         int testy = p.second + movements[i].second;
    //         if (isvalid(testx, testy) == false)
    //         {
    //             continue;
    //         }
    //         if (vertex[testx][testy] != 1)
    //         {
    //             vertex[testx][testy] = 1;
    //             q.push(pair<int, int>(testx, testy));
    //             level[testx][testy] = level[p.first][p.second] + 1;
    //         }
    //         if (level[destx][desty] != INF)
    //         {
    //             break;
    //         }
    //     }
    // }
    return level[destx][desty];
}

int main()
{
    int t;
    cin >> t;
    // vector<pair<int, int> > movements = { {1, 2}, {2, 1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}, {-1, 2}, {2, -1} };
    movements.push_back(pair<int, int>(1, 2));
    movements.push_back(pair<int, int>(2, 1));
    movements.push_back(pair<int, int>(1, 2));
    movements.push_back(pair<int, int>(1, -2));
    movements.push_back(pair<int, int>(-2, 1));
    movements.push_back(pair<int, int>(-2, -1));
    movements.push_back(pair<int, int>(-1, -2));
    movements.push_back(pair<int, int>(-1, 2));
    movements.push_back(pair<int, int>(2, -1));

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        reset();
        cout << modified_bfs(s1, s2) << endl;
    }
    return 0;
}