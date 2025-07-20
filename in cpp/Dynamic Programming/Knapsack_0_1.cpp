#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int ind, int cap, vector<int> &val, vector<int>& wt, vector<vector<int>> &dp)
    {
        // base case
        if (ind== 0) {
            if (wt[0] <= cap) return val[0];
            return 0;
        }
        if (dp[ind][cap] != -1) return dp[ind][cap];
        int nonPick = solve(ind-1, cap, val, wt, dp);
        int pick = 0;
        if (cap >= wt[ind])
            pick = val[ind] + solve(ind-1, cap - wt[ind], val, wt, dp);
        
        return dp[ind][cap] = max(pick, nonPick);
    }
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {

        int n = val.size();
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return solve(n-1, W, val, wt, dp);
        
        // vector<vector<int>> dp(n, vector<int>(W+1, 0));
        // tabulation
        // dp base case
        vector<int> prev(W+1, 0), cur(W+1, 0);
        // space optimization 
        for (int i = wt[0]; i <= W; i++) {
            if (W >= i) prev[i] = val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int cap = 1; cap <= W; cap++)
            {
                int nonPick = prev[cap];
                int pick = 0;
                if (wt[ind] <= cap)
                    pick = val[ind] + prev[cap-wt[ind]];
                cur[cap] = max(nonPick, pick);
            }
            prev = cur;
        }
        return prev[W];
    }
};

int main()
{
    vector<int> wt = {}, value = {};
    Solution obj;
    obj.knapsack(7, value, wt);
    return 0;
}