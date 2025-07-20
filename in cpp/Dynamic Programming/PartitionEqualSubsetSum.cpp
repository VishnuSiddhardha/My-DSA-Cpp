#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
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
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum & 1) return false;
        return isSubsetSum(nums, sum/2);
    }
};

int main()
{

    return 0;
}