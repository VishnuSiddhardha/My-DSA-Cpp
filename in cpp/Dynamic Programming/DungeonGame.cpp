#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;
    int solve(int r, int c, vector<vector<int>> &dungeon, vector<vector<int>> &dp)
    {
        if (r >= n || c >= m) return INT_MAX; // Out of bounds → can't go
        if (r == n - 1 && c == m - 1) {
            // At the princess's cell: need at least 1 HP to survive
            return max(1, 1 - dungeon[r][c]);
        }
        if (dp[r][c] != -1) return dp[r][c];

        // Minimum HP needed if we go right or down
        int right = solve(r, c + 1, dungeon,dp);
        int down = solve(r + 1, c, dungeon,dp);

        int needNext = min(right, down) - dungeon[r][c];
        return dp[r][c] = max(1, needNext);
    }
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        n = dungeon.size(), m = dungeon[0].size();  
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(0,0,dungeon,dp);
        
        vector<vector<int>> dp(n,vector<int>(m, 0));
        
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> board = {{0,-3}};
    cout << "value: " << obj.calculateMinimumHP(board);
    return 0;
}