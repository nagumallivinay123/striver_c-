#include <iostream>
#include <bits/stdc++.h>
const int N= 1e3 + 10;
const int M =1e3 + 10;
const int INF =1e4 + 7;
using namespace std;

int visited[N][M];
int level[N][M];
int value[N][M];
int n, m;
vector<pair<int, int> > movements;
bool check(int x, int y)
{
    if ((x < n && y < m) && x >= 0 && y >= 0)
    {
        return true;
    }
    return false;
}
void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            level[i][j] = INF;
            value[i][j] = 0;
        }
    }
}
int bfs()
{
    int ans = 0;
    int max_find = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            max_find = max(max_find, value[i][j]);
        }
    }
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (value[i][j] == max_find)
            {
                q.push(pair<int, int>(i, j));
                level[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < movements.size(); i++)
        {
            int child_x = p.first + movements[i].first;
            int child_y = p.second + movements[i].second;
            if (check(child_x, child_y))
            {
                if (visited[child_x][child_y] != 1)
                {
                    visited[child_x][child_y] = 1;
                    q.push(pair<int,int>(child_x,child_y));
                    level[child_x][child_y] = 1 + level[p.first][p.second];
                    ans = max(ans, level[child_x][child_y]);
                }
            }
            else
            {
                continue;
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    movements.push_back(pair<int,int>(1,0));
    movements.push_back(pair<int,int>(-1,0));
    movements.push_back(pair<int,int>(0,1));
    movements.push_back(pair<int,int>(0,-1));
    movements.push_back(pair<int,int>(1,1));
    movements.push_back(pair<int,int>(1,-1));
    movements.push_back(pair<int,int>(-1,-1));
    movements.push_back(pair<int,int>(-1,1));

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> value[i][j];
            }
        }
        cout << bfs() << "\n";

    }

    return 0;
}