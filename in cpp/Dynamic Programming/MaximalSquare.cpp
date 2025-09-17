#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxEle = 0;
        for (int i = 0; i < n; i++) {
            int up = i-1;
            for (int j = 0; j < m; j++) {
                int back = j-1;
                if (matrix[i][j]-'0') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + min(dp[up][j], min(dp[i][back], dp[up][back]));
                    maxEle = max(maxEle, dp[i][j]);
                }
            }
        }
        return maxEle*maxEle;
    }
};

int main()
{

    return 0;
}