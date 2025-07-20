#include <bits/stdc++.h>
using namespace std;

class Solution {
    // memoization
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {   
        if (ind == 0)
        {
            if (amount % coins[0] == 0) return 1;
            return 0;
        }
        if (dp[ind][amount] != -1) return dp[ind][amount];
        int nonPick = solve(ind-1, amount, coins, dp);
        int pick = 0;
        if (coins[ind] <= amount)
            pick = solve(ind, amount - coins[ind], coins, dp);
        
        return dp[ind][amount] = nonPick + pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return solve(n-1, amount, coins, dp);
        
        // space optimization
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for (int amt = 0; amt <= amount; amt++)
            if (amt % coins[0] == 0) prev[amt] = 1;
        
        for (int ind = 1; ind < n; ind++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int nonPick = prev[amt];
                int pick = 0;
                if (coins[ind] <= amt)
                    pick = cur[amt - coins[ind]];
                cur[amt] = nonPick + pick;
            }
            prev = cur;
        }
        return prev[amount];
    }
};

int main() {
    vector<int> coins = {1,2,3};
    Solution obj;
    cout << obj.change(4, coins);
    return 0;
}