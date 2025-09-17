#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i,int noOfSubs, int k, vector<int> &prefixSum, vector<vector<int>> &dp) {

        if (noOfSubs == 0) return 0;
        if (i >= prefixSum.size()) return INT_MIN/2;
        if (dp[i][noOfSubs] != -1) return dp[i][noOfSubs];

        int pick = prefixSum[i] + solve(i+k, noOfSubs-1, k, prefixSum, dp);
        int notPick = solve(i+1, noOfSubs, k, prefixSum, dp);
        return dp[i][noOfSubs] = max(pick, notPick);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n-k+1, 0);
        int sum = 0;    
        for (int i = 0; i < k; i++) sum += nums[i];
        // build the pefix k sum array
        prefixSum[0] = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i-k];
            prefixSum[i-k+1] = sum;
        }
        n = prefixSum.size();
        vector<vector<int>>  dp(n, vector<int>(4, -1));
        int temp = solve(0, 3, k, prefixSum, dp);
        vector<int> res;
        int i = 0, subs = 3;
        while (subs > 0 && i < n) {
            int pick = prefixSum[i];
            if (i + k < n && subs-1 > 0) pick += dp[i+k][subs-1];

            int notPick = (i+1 < n ? dp[i+1][subs] : INT_MIN/2);
            if (pick >= notPick) {
                // we picked this subarray
                res.push_back(i);
                i += k;   // skip over this window
                subs--;
            }
            else {
                i++;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n - k + 1;
        vector<int> W(m);
        
        // Step 1: window sums
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1) W[i - (k - 1)] = sum;
        }
        
        // Step 2: left best indices
        vector<int> left(m);
        int best = 0;
        for (int i = 0; i < m; ++i) {
            if (W[i] > W[best]) best = i;
            left[i] = best;
        }
        
        // Step 3: right best indices
        vector<int> right(m);
        best = m - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (W[i] >= W[best]) best = i; // >= ensures earliest index on tie
            right[i] = best;
        }
        
        // Step 4: try middle window
        vector<int> ans(3, -1);
        int maxSum = 0;
        for (int j = k; j < m - k; ++j) {
            int i = left[j - k];
            int l = right[j + k];
            int total = W[i] + W[j] + W[l];
            if (ans[0] == -1 || total > maxSum) {
                maxSum = total;
                ans = {i, j, l};
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Sliding window sums for 3 subarrays
        int windowSum1 = 0, windowSum2 = 0, windowSum3 = 0;

        // Best sums found so far
        int bestSum1 = 0, bestSum12 = 0, bestSum123 = 0;

        // Indices for best subarrays
        int bestIndex1 = 0; 
        int bestIndex12_first = 0, bestIndex12_second = k;

        // Final answer indices
        vector<int> result = {0, k, 2 * k};

        // Initialize first windows
        for (int i = 0; i < k; i++) {
            windowSum1 += nums[i];
            windowSum2 += nums[i + k];
            windowSum3 += nums[i + 2 * k];
        }

        bestSum1 = windowSum1;
        bestSum12 = windowSum1 + windowSum2;
        bestSum123 = windowSum1 + windowSum2 + windowSum3;

        // Sliding window across the array
        for (int i = 0; i <= n - 3 * k; i++) {
            if (i > 0) {
                windowSum1 = windowSum1 - nums[i - 1] + nums[i + k - 1];
                windowSum2 = windowSum2 - nums[i + k - 1] + nums[i + 2 * k - 1];
                windowSum3 = windowSum3 - nums[i + 2 * k - 1] + nums[i + 3 * k - 1];
            }

            // Update best single subarray
            if (windowSum1 > bestSum1) {
                bestSum1 = windowSum1;
                bestIndex1 = i;
            }

            // Update best pair of subarrays
            if (bestSum1 + windowSum2 > bestSum12) {
                bestSum12 = bestSum1 + windowSum2;
                bestIndex12_first = bestIndex1;
                bestIndex12_second = i + k;
            }

            // Update best triple of subarrays
            if (bestSum12 + windowSum3 > bestSum123) {
                bestSum123 = bestSum12 + windowSum3;
                result = {bestIndex12_first, bestIndex12_second, i + 2 * k};
            }
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1,2,1,2,1,2,1,2,1};
    Solution obj;
    vector<int> ans = obj.maxSumOfThreeSubarrays(arr, 2);
    for (int x: ans)
        cout << x << " ";
    cout << endl;
    return 0;
}