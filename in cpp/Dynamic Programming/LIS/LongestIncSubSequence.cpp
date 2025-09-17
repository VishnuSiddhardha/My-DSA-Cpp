#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    // memoization
    int solve(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == n) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notPick = solve(ind + 1, prev, nums, dp);
        int pick = 0;
        if (prev == -1 || nums[prev] < nums[ind])
            pick = 1 + solve(ind + 1, ind, nums, dp);
        return dp[ind][prev + 1] = max(notPick, pick);
    }
public:
    int lengthOfLIS(vector<int> &nums)
    {
        n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solve(0, -1, nums, dp);

        // ***tabulation***

        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // vector<int> next(n+1, 0), cur(n+1, 0);
        
        // for (int ind = n-1; ind >= 0; ind--)
        // {
        //     for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        //     {
        //         int notTake = next[prev_ind + 1];
        //         int take = 0;
        //         if (prev_ind == -1 || nums[ind] > nums[prev_ind]) 
        //             take = 1 + next[ind + 1];
        //         cur[prev_ind+1] = max(take, notTake);
        //     }
        //     next = cur;
        // }
        // return next[0];


        // ***1-D optimized -> tabulation solution*** 

        vector<int> dp(n, 1), hash(n);
        int lastIdx = 0;
        int lisLen = 1;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            // lisLen = max(lisLen, dp[i]);
            if (dp[i] > lisLen) {
                lisLen = dp[i];
                lastIdx = i;
            }
        }
        // printing the sequence
        vector<int> result;
        while (hash[lastIdx] != lastIdx) {  // check it once if possible
            result.push_back(nums[hash[lastIdx]]);
            lastIdx = hash[lastIdx];
        }
        reverse(result.begin(), result.end());
        return lisLen;


        // ***Binary Search Method***
        vector<int> temp = {nums[0]};
        int len = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            }
            else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};

int main()
{

    return 0;
}