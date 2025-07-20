#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int nrow, ncol;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dr[] = {1, 0, -1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};

// for (int deltarow = -1; deltarow <= -1; deltarow++)
// {
//     for (int deltacol = -1; deltacol <= -1; deltacol++)
//     {
//         int nrow = row + deltarow;
//         int ncol = col + deltacol;
//         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
//         {
//             visited[nrow][ncol] = 1;
//             q.push({nrow, ncol});
//         }
//     }
// }
int main()
{

    return 0;
}