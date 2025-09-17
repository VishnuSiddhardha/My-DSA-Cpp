#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0) return 0;
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) 
            return solve(i - 1, j - 1, word1, word2, dp);
        int insert = 1 + solve(i, j - 1, word1, word2, dp);
        int replace = 1 + solve(i - 1, j - 1, word1, word2, dp);
        int del = 1 + solve(i - 1, j, word1, word2, dp);

        return dp[i][j] = min(insert, min(replace, del));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(n, m, word1, word2, dp);
        // tabulation
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for (int j = 1; j <= m; j++) 
        //     dp[0][j] = j;
        // for (int i = 1; i <= n; i++)
        //     dp[i][0] = i;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++) 
        //     {
        //         if (word1[i - 1] == word2[j - 1]) 
        //             dp[i][j] = dp[i - 1][j - 1];
        //         else {
        //             int insert = 1 + dp[i][j - 1];
        //             int replace = 1 + dp[i - 1][j - 1];
        //             int del = 1 + dp[i - 1][j];

        //             dp[i][j] = min(insert, min(replace, del));
        //         }
        //     }
        // }
        // return dp[n][m];

        // space optimization
        vector<int> prev(m + 1, 0), cur (m + 1, 0);
        for (int j = 1; j <= m; j++) 
            prev[j] = j;
        // for (int i = 1; i <= n; i++)
        //     dp[i][0] = i;
        for (int i = 1; i <= n; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= m; j++) 
            {
                if (word1[i - 1] == word2[j - 1]) 
                    cur[j] = prev[j - 1];
                else {
                    int insert = 1 + cur[j - 1];
                    int replace = 1 + prev[j - 1];
                    int del = 1 + prev[j];

                    cur[j] = min(insert, min(replace, del));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main() {
    string s1 = "mdl", s2 = "qhszmmbgi";
    Solution obj;
    cout << obj.minDistance(s1, s2);
    return 0;
}