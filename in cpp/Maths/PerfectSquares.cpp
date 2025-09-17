#include <bits/stdc++.h>
using namespace std;

// 1D memoization code
class Solution {
public:
    int solve(int num, vector<int> &dp) {
        if (num == 0) return 0; // no squares needed
        if (dp[num] != -1) return dp[num];

        int ans = 1e9;
        for (int i = 1; i * i <= num; i++) {
            ans = min(ans, 1 + solve(num - i * i, dp));
        }
        return dp[num] = ans;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);

        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for (int i = 1; i*i <= n; i++) {
            int square = i * i;
            for (int num = square; num <= n; num++) {
                dp[num] = min(dp[num], 1 + dp[num - square]);
            }
        }
        return dp[n];
    }
};


class Solution
{
    int solve(int num, int i, vector<vector<int>> &dp)
    {
        if (num == 0) return 0;
        if (i == 1) return num;
        if (dp[num][i] != -1) return dp[num][i];
        int pick = 1e5;
        if ((i*i) <= num)
            pick = 1 + solve(num-i*i, i, dp);
        int notPick = solve(num, i-1, dp);
        return dp[num][i] = min(pick, notPick);
    }
public:
    int numSquares(int n)
    {
        // int i = pow(n, 0.5);
        // cout << i << endl;
        // vector<vector<int>> dp(n+1, vector<int>(i+1, -1));
        // return solve(n, i, dp);

        int end = pow(n, 0.5);
        vector<vector<int>> dp(n+1, vector<int>(end+1, 0));
        // base case
        for (int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }
        for (int num = 0; num <= n; num++)
        {
            for (int i = 1; i <= end; i++) 
            {
                int pick = 1e5;
                if ((i*i) <= num)
                    pick = 1 + dp[num-i*i][i];
                int notPick = dp[num][i-1];
                dp[num][i] = min(pick, notPick);
            }
        }
        return dp[n][end];
    }
};

int main()
{
    Solution obj;
    cout << obj.numSquares(12);
    return 0;
}