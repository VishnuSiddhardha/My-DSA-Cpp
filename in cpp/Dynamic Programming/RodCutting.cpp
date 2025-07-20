#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int ind, int len, vector<int> &price, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return len * price[0];
        }
        if (dp[ind][len] != -1) return dp[ind][len];
        int nonPick = solve(ind - 1, len, price, dp);
        int pick = INT_MIN;
        if (len >= ind+1)
            pick = price[ind] + solve(ind, len - (ind + 1), price, dp);
        return dp[ind][len] = max(nonPick, pick);
    }
public:
    int cutRod(vector<int> &price)
    {
        // code here
        int n = price.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(n - 1, n, price, dp);
        // tabulization
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // sapce optimization
        vector<int> prev(n + 1, 0), cur (n + 1, 0);
        // base case
        for (int ln = 1; ln <= n; ln++)
            prev[ln] = ln * price[0];
        
        for (int ind = 1; ind < n; ind++)
        {
            for (int len = 1; len <= n; len++)
            {
                int nonPick = prev[len];
                int pick = INT_MIN;
                if (len >= ind + 1)
                    pick = price[ind] + cur[len - (ind + 1)];
                cur[len] = max(nonPick, pick);
            }
            prev = cur;
        }
        return prev[n];
    }
    // you can also optimize it to 1 array
};

int main()
{

    return 0;
}