#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int ind, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (ind == 0) 
        {
            return (capacity / wt[0]) * val[0];
        }

        if (dp[ind][capacity] != -1) return dp[ind][capacity];

        int nonPick = solve(ind - 1, capacity, val, wt, dp);
        int pick = INT_MIN;
        if (wt[ind] <= capacity)
            pick = val[ind] + solve(ind, capacity - wt[ind], val, wt, dp);
        
        return dp[ind][capacity] = max(pick, nonPick);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        // return solve(n - 1, capacity, val, wt, dp);
        // tabulation
        // vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        // space optimization
        vector<int> prev(capacity + 1, 0), cur(capacity + 1, 0);
        // base case
        for (int cp = wt[0]; cp <= capacity; cp++)
            prev[cp] = (cp / wt[0]) * val[0];

        for (int ind = 1; ind < n; ind++)
        {
            for (int cp = 1; cp <= capacity; cp++)
            {
                int nonPick = prev[cp];
                int pick = INT_MIN;
                if (wt[ind] <= cp)
                    pick = val[ind] + cur[cp - wt[ind]];
                
                cur[cp] = max(nonPick, pick);
            }
            prev = cur;
        }
        return prev[capacity];
    }
};

int main()
{

    return 0;
}