#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check1(int row, int col, char a, vector<vector<char>> &board)
{
    int actual_row = (row - row % 3);
    int actual_col = (col - col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[actual_row + i][actual_col + j] == a)
            {
                return false;
            }
        }
    }

    return true;
}
bool check2(int row, char a, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == a)
        {
            return false;
        }
    }
    return true;
}
bool check3(int col, char a, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == a)
        {
            return false;
        }
    }
    return true;
}
bool function_find(int row, vector<vector<char>> &board, int column, vector<vector<int>> &temp)
{
    if (row >= 9)
    {
        return true;
    }
    for (int col = column; col < 9; col++)
    {
        if (board[row][col] == '.')
        {
            for (char a = '1'; a <= '9'; a++)
            {
                if (temp[row][a - '1'] == 0)
                {
                    if (check1(row, col, a, board) && check2(row, a, board) && check3(col, a, board))
                    {
                        board[row][col] = a;
                        temp[row][a - '1'] = 1;
                        if (function_find(row, board, col + 1, temp) == false)
                        {
                            board[row][col] = '.';
                            temp[row][a - '1'] = 0;
                        }
            
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    return function_find(row + 1, board, 0, temp);
}
void solveSudoku(vector<vector<char>> &board)
{
    vector<vector<int>> temp(board.size(), vector<int>(board[0].size(), 0));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] != '.')
            {
                temp[i][board[i][j]-'1']==1;
            }
        }
    }
    bool ans = function_find(0, board, 0, temp);
}
int main()
{

    return 0;
}