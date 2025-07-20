#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int row, int col,  vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (row == triangle.size()-1) return triangle[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + solve(row+1, col, triangle, dp);
        int diag = triangle[row][col] + solve(row+1, col+1, triangle, dp);
        
        return dp[row][col] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = triangle[n-1][i];

        for (int i = n-2; i >= 0; i--)
        {
            vector<int> temp(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];
                temp[j] = min(down, diag);
            }
            dp = temp;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}