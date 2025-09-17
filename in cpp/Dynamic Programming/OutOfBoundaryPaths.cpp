#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> delta = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    const int MOD = 1e9 + 7;
    int dfs(int r, int c, int m, int n, int moves, vector<vector<vector<int>>> &dp)
    {
        if (r < 0 || c < 0 || r >= m || c >= n) return 1;
        if (moves == 0) return 0;
        if (dp[r][c][moves] != -1) return dp[r][c][moves]; 
        long long count = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r+delta[i][0], nc = c+delta[i][1];
            count = (count + dfs(nr, nc, m, n, moves-1, dp)) % MOD;
        }
        return dp[r][c][moves] = count;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, m, n, maxMove, dp);
    }
};

int main()
{

    return 0;
}