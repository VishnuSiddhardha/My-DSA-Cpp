#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>> &board, vector<vector<int>> &visited)
    {
        visited[r][c] = 1;
        // check for neightbour nodes
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 4; i++) 
        {
            int nrow = r + deltaRow[i];
            int ncol = c + deltaCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 1)
                dfs(nrow, ncol, board, visited);
        }
    }
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // for 1st row and last row
        for (int i = 0; i < m; i++)
        {
            if (!vis[0][i] && grid[0][i]) {
                dfs(0, i, grid, vis);
            }
            if (!vis[n-1][i] && grid[n-1][i]) {
                dfs(n-1, i, grid, vis);
            }
        }
        // for 1st col and last col
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0]) {
                dfs(i, 0, grid, vis);
            }
            if (!vis[i][m-1] && grid[i][m-1]) {
                dfs(i, m-1, grid, vis);
            }
        }
        
        // marking in the original grid
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}