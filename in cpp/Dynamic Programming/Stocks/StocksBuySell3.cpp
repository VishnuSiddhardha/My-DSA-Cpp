#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int n;
    int solve(int ind, int canBuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (canBuy == 4 || ind == n) return 0;

        if (dp[ind][canBuy] != -1) return dp[ind][canBuy];

        if (!(canBuy & 1))
        {
            return dp[ind][canBuy] = max(-prices[ind]+solve(ind+1,canBuy+1,prices,dp), solve(ind+1,canBuy,prices,dp));
        }
        else
            return dp[ind][canBuy] = max(prices[ind]+solve(ind+1,canBuy+1,prices,dp), solve(ind+1,canBuy, prices,dp));
    }
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(4, -1));
        // return solve(0, 0, prices, dp);
        
        // tabulation
        vector<vector<int>> dp(n+1, vector<int>(5, 0));

        for (int ind = n-1; ind >= 0; ind--)
        {
            for (int canBuy = 3; canBuy >= 0; canBuy--)
            {
                if (!(canBuy & 1))
                    dp[ind][canBuy] = max(-prices[ind]+dp[ind+1][canBuy+1], dp[ind+1][canBuy]);
                else
                    dp[ind][canBuy] = max(prices[ind]+dp[ind+1][canBuy+1], dp[ind+1][canBuy]);
            }
        }
        return dp[0][0];

        // space optimization
        vector<int> next(5,0), cur(5,0);

        for (int ind = n-1; ind >= 0; ind--)
        {
            for (int canBuy = 3; canBuy >= 0; canBuy--)
            {
                if (!(canBuy & 1))
                    cur[canBuy] = max(-prices[ind]+next[canBuy+1], next[canBuy]);
                else
                    cur[canBuy] = max(prices[ind]+next[canBuy+1], next[canBuy]);
            }
            next = cur;
        }
        return next[0];
    }
};

int main()
{

    return 0;
}