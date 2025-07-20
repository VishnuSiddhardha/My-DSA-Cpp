#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (r == 0 && c == 0) return grid[0][0];
        if (r <0 || c < 0) return 201;
        if (dp[r][c] != -1) return dp[r][c];

        int up = grid[r][c] + solve(r-1, c, grid, dp);
        int down = grid[r][c] + solve(r, c-1, grid, dp);
        return dp[r][c] = min(up, down);
    }
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 0);
        // return solve(n-1, m-1, grid, dp);
        // tabulation
        for (int row = 0; row < n; row++)
        {
            vector<int> temp(m, 0);
            for (int col = 0; col < m; col++)
            {
                if (row == 0 && col == 0) temp[col] = grid[row][col];
                else 
                {
                    int left = INT_MAX;
                    int up = grid[row][col] + dp[col];
                    if (col > 0) left = grid[row][col] + temp[col-1];
                    temp[col] = min(up, left);
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
};

int main()
{

    return 0;
}