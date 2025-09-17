#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    bool solve(int i, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(k==0) return true;
        if (i==0) return k==0;
        if (dp[i][k] != -1) return dp[i][k];
        bool pick = false;
        if (arr[i-1] <= k) pick = solve(i-1,k-arr[i-1],arr,dp);
        bool notPick = solve(i-1,k, arr, dp);
        return dp[i][k] = (pick||notPick);
    }
public:
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(n,k,arr,dp);

        // vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
        // space optimization
        vector<int> prev(k+1, false), cur(k+1, false);
        prev[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++) 
            {
                bool pick = false;
                if (arr[i-1] <= j) pick = prev[j-arr[i-1]];
                bool notPick = prev[j];
                cur[j] = (pick||notPick);
            }
            prev = cur;
        }
        return prev[k];
    }
};

int main()
{

    return 0;
}