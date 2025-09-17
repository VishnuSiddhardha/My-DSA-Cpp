#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i, int m, int n, vector<pair<int, int>> &nums, vector<vector<vector<int>>> &dp)
    {
        if (i == nums.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];

        int curZeros = nums[i].first;
        int curOnes = nums[i].second;
        int pick = INT_MIN;
        if (m-curZeros >= 0 && n-curOnes >= 0)
            pick = 1 + solve(i+1, m-curZeros, n-curOnes, nums, dp);
        int notPick = solve(i+1, m, n, nums, dp);
        return dp[i][m][n] = max(pick, notPick);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr; // pair<zeros, ones>
        for (string &s: strs) {
            int z = 0, o = 0;
            for (char &bit: s) {
                if (bit == '0') z++;
                else o++;
            }
            arr.push_back({z, o});
        }
        int aSize = arr.size();
        vector<vector<vector<int>>> dp(aSize, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, m, n, arr, dp);

        // tabulation
        vector<vector<vector<int>>> dp(aSize+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        // base case already initialized in the dp declaration
        for (int i = aSize-1; i >= 0; i--) {
            for (int j = 0; j<= m; j++) {
                for (int k = 0; k <= n; k++) {
                    int curZeros = arr[i].first;
                    int curOnes = arr[i].second;
                    int pick = INT_MIN;
                    if (j-curZeros >= 0 && k-curOnes >= 0)
                        pick = 1 + dp[i+1][j-curZeros][k-curOnes];
                    int notPick = dp[i+1][j][k];
                    dp[i][j][k] = max(pick, notPick);
                }
            }
        }
        return dp[0][m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> arr; // pair<zeros, ones>
        for (string &s: strs) {
            int z = 0, o = 0;
            for (char &bit: s) {
                if (bit == '0') z++;
                else o++;
            }
            arr.push_back({z, o});
        }

        // 2D DP: dp[j][k] = max strings with j zeros and k ones
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (auto &[curZeros, curOnes] : arr) {
            // iterate backwards so we don’t overwrite states we still need
            for (int j = m; j >= curZeros; j--) {
                for (int k = n; k >= curOnes; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j-curZeros][k-curOnes]);
                }
            }
        }

        return dp[m][n];
    }
};


int main() {
    vector<string> strs = {"10","0001","111001","1","0"};
    Solution obj;
    cout << obj.findMaxForm(strs, 5, 3);
    return 0;
}