#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, k;
    int solve(int i, vector<int> &arr, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int upto = min(n, i + k);

        int maxi = arr[i];
        int finalCost = INT_MIN;
        for (int ind = i; ind < upto; ind++)
        {
            maxi = max(maxi, arr[ind]);
            int cost = (ind - i + 1) * maxi + solve(ind + 1, arr, dp);
            finalCost = max(finalCost, cost);
        }
        return dp[i] = finalCost;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        n = arr.size();
        this->k = k;
        vector<int> dp(n, -1);
        return solve(0, arr, dp);

        // tabulation
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int upto = min(n, i + k);

            int maxi = arr[i];
            int finalCost = INT_MIN;
            for (int ind = i; ind < upto; ind++)
            {
                maxi = max(maxi, arr[ind]);
                int cost = (ind - i + 1) * maxi + dp[ind + 1];
                finalCost = max(finalCost, cost);
            }
            dp[i] = finalCost;
        }
        return dp[0];
    }
};

int main()
{

    return 0;
}