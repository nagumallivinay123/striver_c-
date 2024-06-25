#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// N queen problem
// diagonal check cheyadaniki eppudu  row+col rendu boxes equal ayithe aa rendu diagonal ki chendinavi  ->edhi lower diagonal check chest
// diagonal check cheyadaniki eppudu  n-1+col-row rendu boxes equal ayithe aa rendu diagonal ki chendinavi  ->edhi upper  diagonal check cheyadaniki
// optimization cheyali diagonal
// oka row lo pettasaka adhe row lo pettadaniki alochinnchakudau
//
void function_n(int col, vector<vector<string>> &ans, vector<string> board, vector<int> &left_rows, vector<int> &lower_diagonal, vector<int> &upper_diagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int rows = 0; rows < n; rows++)
    {
        if (left_rows[rows] == 0 && lower_diagonal[rows + col] == 0 && upper_diagonal[n - 1 + col - rows] == 0)
        {
            left_rows[rows] = 1;
            board[rows][col] = 'Q';
            lower_diagonal[rows + col] = 1;
            upper_diagonal[n - 1 + col - rows] = 1;
            function_n(col + 1, ans, board, left_rows, lower_diagonal, upper_diagonal, n);
            left_rows[rows] = 0;
            board[rows][col] = '-';
            lower_diagonal[rows + col] = 0;
            upper_diagonal[n - 1 + col - rows] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '-');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> left_rows(n, 0);
    vector<int> lower_diagonal(2 * n - 1, 0);
    vector<int> upper_diagonal(2 * n - 1, 0);
    function_n(0, ans, board, left_rows, lower_diagonal, upper_diagonal, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << "\n";
        }

        cout << "\n\n";
    }

    return 0;
}