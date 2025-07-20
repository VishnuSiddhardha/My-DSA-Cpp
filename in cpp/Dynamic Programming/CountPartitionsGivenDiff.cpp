#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &arr, int d)
    {
        // Code here
        int n = arr.size();
        int sum = 0;
        for (int x : arr) sum += x;
        int target = sum - d;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        // perform the count the subset sum with k logic
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
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
};

int main()
{
    Solution obj;
    vector<int> arr = {0, 1, 2, 2, 2, 3, 0, 3, 0, 1};
    cout << obj.countPartitions(arr, 12);
    return 0;
}