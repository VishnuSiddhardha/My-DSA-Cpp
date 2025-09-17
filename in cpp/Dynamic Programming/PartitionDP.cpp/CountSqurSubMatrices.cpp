#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int sum = 0;
        // 1st row
        for (int i = 0; i < m; i++) {
            if (matrix[0][i]) {
                sum++;
                dp[0][i] = 1;
            }
        } 
        //1st col
        for (int i = 1; i < n; i++) {
            if (matrix[i][0]) {
                sum++;
                dp[i][0] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j]) {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                    sum += dp[i][j];
                }
            }
        }
        return sum;
    }
};

int main()
{

    return 0;
}