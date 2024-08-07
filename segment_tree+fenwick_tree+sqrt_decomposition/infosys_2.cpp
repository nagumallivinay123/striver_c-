

#include <bits/stdc++.h>
using namespace std;

void precomputeMaxMin(vector<vector<int>> &grid, vector<vector<vector<int>>> &maxVal, vector<vector<vector<int>>> &minVal, int N) {
    for (int size = 1; size <= N; size++) {
        for (int i = 0; i <= N - size; i++) {
            for (int j = 0; j <= N - size; j++) {
                if (size == 1) {
                    maxVal[i][j][size] = grid[i][j];
                    minVal[i][j][size] = grid[i][j];
                } else {
                    int prevMax = maxVal[i][j][size - 1];
                    int placementlelo = minVal[i][j][size - 1];
                    for (int k = 0; k < size; k++) {
                        prevMax = max({prevMax, grid[i + size - 1][j + k], grid[i + k][j + size - 1]});
                        placementlelo = min({placementlelo, grid[i + size - 1][j + k], grid[i + k][j + size - 1]});
                    }
                    maxVal[i][j][size] = prevMax;
                    minVal[i][j][size] = placementlelo;
                    
                }
            }
        }
    }
}

int getBeauty(vector<vector<vector<int>>> &maxVal, vector<vector<vector<int>>> &minVal, int x, int y, int size) {
    return maxVal[x][y][size] - minVal[x][y][size];
}

int get_ans( int N,vector<vector<int>> grid,) {
    vector<vector<vector<int>>> maxVal(N, vector<vector<int>>(N, vector<int>(N + 1, 0)));
    vector<vector<vector<int>>> minVal(N, vector<vector<int>>(N, vector<int>(N + 1, 0)));

    precomputeMaxMin(grid, maxVal, minVal, N);

    int maxBeautySum = 0;

    for (int size1 = 1; size1 <= N; size1++) {
        for (int x1 = 0; x1 <= N - size1; x1++) {
            for (int y1 = 0; y1 <= N - size1; y1++) {
                int beauty1 = getBeauty(maxVal, minVal, x1, y1, size1);

                for (int size2 = 1; size2 <= N; size2++) {
                    for (int x2 = 0; x2 <= N - size2; x2++) {
                        for (int y2 = 0; y2 <= N - size2; y2++) {
                            if ((x1 + size1 <= x2  x2 + size2 <= x1) && (y1 + size1 <= y2  y2 + size2 <= y1)) {
                                int beauty2 = getBeauty(maxVal, minVal, x2, y2, size2);
                                maxBeautySum = max(maxBeautySum, beauty1 + beauty2);
                            }
                        }
                    }
                }
            }
        }
    }

    return maxBeautySum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;


    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }


    int result = get_ans(grid, N);
    cout << result << endl;

    return 0;
}
