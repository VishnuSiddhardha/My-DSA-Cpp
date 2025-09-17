#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i, int rem, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == 0) {
            return rem == 0;
        }
        if (dp[i][rem] != -1) return dp[i][rem];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target, -1));
        int count = solve(n, target, nums, dp);
        return count;
    }
};

int main() {
    
    return 0;
}