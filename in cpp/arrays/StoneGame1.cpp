#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if (i == j) return piles[i];   // only one pile, take it
        if (dp[i][j] != INT_MIN) return dp[i][j];

        int pickLeft  = piles[i] - solve(i+1, j, piles, dp);
        int pickRight = piles[j] - solve(i, j-1, piles, dp);

        return dp[i][j] = max(pickLeft, pickRight);
    }
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        
        // tabulation
        // fill for increasing lengths
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i+1][j],
                               piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;

        // 1D - optimized
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = piles[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i] = max(piles[i] - dp[i+1],
                            piles[j] - dp[i]);
            }
        }
        return dp[0] > 0;
    }
};  

int main()
{

    return 0;
}