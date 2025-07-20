#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> deltaRow = {-1, 0, 1, 0};
    vector<int> deltaCol = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<int>> &visited)
    {
        visited[r][c] = 1;
        // check for neightbour nodes
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 4; i++) 
        {
            int nrow = r + deltaRow[i];
            int ncol = c + deltaCol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O')
                dfs(nrow, ncol, board, visited);
        }
    }
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // for 1st row and last row
        for (int i = 0; i < m; i++)
        {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(0, i, board, vis);
            }
            if (!vis[n-1][i] && board[n-1][i] == 'O') {
                dfs(n-1, i, board, vis);
            }
        }
        // for 1st col and last col
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, vis);
            }
            if (!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, board, vis);
            }
        }
        
        // marking in the original board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{

    return 0;
}