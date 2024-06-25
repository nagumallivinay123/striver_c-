class Solution
{
public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here

        // bool box_check
        bool ans =
            for (int index_i = 0; index_i < N; index_i++)
        {
            for (int index_j = 0; index_j < n; index_j++)
            {
                if (grid[index_i][index_j] == 0)
                {
                    for (int find = 1; find <= 9; find++)
                    {

                        int box_i = index_i % 3;
                        int box_j = index_j / 3;
                        int start_boxi = box_i * 3;
                        int start_boxj = box_j * 3;
                        bool box_check = true;
                        for (int temp_i = start_boxi; temp_i <= 2 + start_boxi; i++)
                        {
                            for (int temp_j = start_boxj; temp_j <= 2 + start_boxj; j++)
                            {
                                if (grid[temp_i][temp_j] == find)
                                {
                                    box_check = false;
                                }
                            }
                        }

                        bool col_check = true;
                        for (int i = 0; i < 9; i++)
                        {
                            if (grid[i][index_j] == find)
                            {
                                col_check = false;
                            }
                        }

                        bool row_check = true;
                        for (int i = 0; i < 9; i++)
                        {
                            if (grid[index_i][i] == find)
                            {
                                row_check = false;
                            }
                        }
                    }
                }
            }
        }
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
};