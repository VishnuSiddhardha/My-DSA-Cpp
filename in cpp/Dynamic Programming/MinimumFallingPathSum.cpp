#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int solve(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (row == n - 1)
            return matrix[row][col];
        if (dp[row][col] != INT_MIN)
            return dp[row][col];
        // for all elements in the row

        // for every element
        int maxi = INT_MIN;
        int cur = matrix[row][col];
        for (int j = -1; j < 2; j++)
        {
            int newr = row + 1, newc = col + j;
            if (newr < n && newc >= 0 && newc < n)
                maxi = max(maxi, cur + solve(newr, newc, matrix, dp));
        }
        return dp[row][col] = maxi;
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int result = INT_MIN;
        for (int i = 0; i < n; i++)
            result = max(result, solve(0, i, matrix, dp));
        return result;

        // tabulation
        // space optimization
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = matrix[0][i];

        for (int i = 1; i < n; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                int maxi = INT_MIN;
                int cur = matrix[i][j];
                for (int k = -1; k < 2; k++)
                {
                    int newc = j + k;
                    if (newc >= 0 && newc < n)
                    maxi = max(maxi, cur + dp[newc]);
                }
                temp[j] = maxi;
            }
            dp = temp;
        }
    }
};

int main()
{

    return 0;
}