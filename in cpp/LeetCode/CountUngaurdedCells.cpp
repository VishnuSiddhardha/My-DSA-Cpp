#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int m, n;
    void markCells(int row, int col, vector<vector<int>> &board) {
        int r, c;
        // top
        r = row-1;
        while (r >= 0) {
            if (board[r][col] == 2) break;
            board[r][col] = 0;
            r--;
        }
        // right
        c = col+1;
        while (c < n) {
            if (board[row][c] == 2) break;
            board[row][c] = 0;
            c++;
        }
        // down
        r = row+1;
        while (r < m) {
            if (board[r][col] == 2) break;
            board[r][col] = 0;
            r++;
        }
        // left
        c = col-1;
        while (c >= 0) {
            if (board[row][c] == 2) break;
            board[row][c] = 0;
            c--;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // 0 -> visited, 1 -> not visited, 2 -> rock, gaurd
        this->m = m; this->n = n;
        vector<vector<int>> board(m, vector<int>(n, 1));
        for (auto &g : guards) board[g[0]][g[1]] = 2;
        for (auto &w : walls) board[w[0]][w[1]] = 2;
        
        for (auto &grd : guards) 
            markCells(grd[0], grd[1], board);

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) count++;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}