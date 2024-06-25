
class Solution
{
public:
    int bobHappiness(int n, int k, int Q, vector<vector<int>> &students, vector<vector<int>> &queries)
    {
        // code here

        // since
        // n ~ 1000
        //-1e9 <= s[i][0],s[i][1] <= 1e9
        // we have atmost 1000 different coordinates
        //-> we can compress the coordinate representation

        // given all x,y coordinates are distinct
        map<int, int> mx, my;
        for (auto &s : students)
        {
            mx[s[0]] = 0;
            my[s[1]] = 0;
        }

        // assign compressed IDs to each x,y coordinates
        int id = 0;
        for (auto &e : mx)
        {
            e.second = id++;
        }

        id = 0;
        for (auto &e : my)
        {
            e.second = id++;
        }

        // occurences of compressed coordinates :
        vector<vector<int>> g(n, vector<int>(n));
        for (auto &s : students)
        {
            int idx = mx[s[0]], idy = my[s[1]];
            g[idx][idy]++;
        }

        // 2D prefix sum :
        vector<vector<int>> pre(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + g[i - 1][j - 1];
            }
        }

        // for each query : find the prefix rectangle sum :
        int cnt = 0;
        for (auto &q : queries)
        {
            int x1 = mx[students[q[0] - 1][0]], y1 = my[students[q[0] - 1][1]];
            int x2 = mx[students[q[1] - 1][0]], y2 = my[students[q[1] - 1][1]];

            int r1 = min(x1, x2) + 1, c1 = min(y1, y2) + 1;
            int r2 = max(x1, x2) + 1, c2 = max(y1, y2) + 1;
            int curr = pre[r2][c2] - pre[r2][c1 - 1] - pre[r1 - 1][c2] + pre[r1 - 1][c1 - 1];
            // cout<<curr<<" ";
            curr -= 2; // excluding the rectangle points
            if (curr <= k)
                cnt++;
        }
        return cnt;
    }
};