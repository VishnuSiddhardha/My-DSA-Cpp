#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        int up = solve(m-1, n, dp);
        int left = solve(m, n-1, dp);

        return dp[m][n] = up+left;
    }
public:
    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1,dp);

        // tabulation
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) temp[j] = 1;
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