class Solution
{
public:
    int function(int i, int j, int parent, vector<vector<int>> &arr, vector<vector<int>> &matrix)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        if (matrix[i][j] < parent)
        {
            return 0;
        }
        if (arr[i][j] != 0)
        {
            return arr[i][j];
        }
        parent = matrix[i][j];
        int s = function(i + 1, j, parent, arr, matrix);
        int r = function(i - 1, j, parent, arr, matrix);
        int p = function(i, j - 1, parent, arr, matrix);
        int q = function(i, j + 1, parent, arr, matrix);
        s = max(s, r);
        q = max(q, p);
        arr[i][j] += (1 + max(s, q));
        return arr[i][j];
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix[0].size();
        int n = matrix.size();

        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                arr[i][j] = 0;
            }
        }

        long long t = 0, p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (arr[i][j] == 0)
                {
                    p = function(i, j, 0, arr, matrix);
                }
                t = max(p, t);
            }
        }
        return t;
    }
};