#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e8;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];
        int notPick = solve(ind-1, amount, coins, dp);
        int pick = INT_MAX;
        if (coins[ind] <= amount) 
            pick = 1 + solve(ind, amount - coins[ind], coins, dp);
                
        return dp[ind][amount] = min(notPick, pick);
    }
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return solve(n-1, amount, coins, dp);
        // tabulation
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) prev[i] = i / coins[0];
            else
                prev[i] = 1e8;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int nonPick = prev[amt];
                int pick = 1e8;
                if (coins[ind] <= amt)
                    pick = 1 + cur[amt - coins[ind]];
                cur[amt] = min(pick, nonPick);
            }
            prev = cur;
        }
        if (prev[amount] >= 1e8) return -1;
        return prev[amount];
    }
};

int main()
{

    return 0;
}

