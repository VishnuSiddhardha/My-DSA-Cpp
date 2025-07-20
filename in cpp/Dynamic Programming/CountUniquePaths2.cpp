#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &grid)
    {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0 || grid[m][n] == 1) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        int up = solve(m-1, n, dp, grid);
        int left = solve(m, n-1, dp, grid);

        return dp[m][n] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1,dp, obstacleGrid);

        // space optimization
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                }
                else if (i == 0 && j == 0) temp[j] = 1;
                else {
                    int up = 0, left = 0;
                    up = dp[j];
                    if (j > 0) left = temp[j-1];
                    temp[j] = up+left;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};

int main()
{

    return 0;
}