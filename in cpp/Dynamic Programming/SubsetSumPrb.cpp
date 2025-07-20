#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoiozation
    bool solve(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return arr[0] == target;
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = solve(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind])
            take = solve(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take | notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        int n = arr.size();
        // vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        vector<bool> dp(sum+1, false), cur(sum+1, false);

        dp[0] = cur[0] = true;
        dp[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[target];
                bool take = false;
                if (target >= arr[ind])
                    take = dp[target - arr[ind]];
                cur[target] = take | notTake;
            }
            dp = cur;
        }
        return dp[sum];
    }
};

int main()
{

    return 0;
}