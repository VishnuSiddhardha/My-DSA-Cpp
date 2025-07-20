#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || arr[0] == target)
                return 1;
            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];

        int nonPickCount = solve(ind - 1, target, arr, dp);
        int pickCount = 0;
        if (arr[ind] <= target)
            pickCount = solve(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = nonPickCount + pickCount;
    }

public:
    int perfectSum(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solve(n-1, target, arr, dp);
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // tabulation
         // Base case:
        if (arr[0] == 0)
            dp[0][0] = 2;  // pick or not pick
        else
            dp[0][0] = 1;  // don't pick

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;  // pick if <= target
        for (int ind = 1; ind < n; ind++)
        {
            for (int t = 0; t <= target; t++)
            {
                int nonPick = dp[ind - 1][t];
                int pick = 0;
                if (arr[ind] <= t) pick = dp[ind - 1][t - arr[ind]];
                dp[ind][t] = pick + nonPick;
            }
        }
        return dp[n-1][target];
    }
    // i haven't written the space optimization here, 
    // but thats easy, you can think it
};

int main()
{

    return 0;
}