#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // memoization
    int solve(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (ind1 == 0 || ind2 == 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if (s1[ind1 -1] == s2[ind2 - 1])
            return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s1, s2, dp);
        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s1, s2, dp), solve(ind1, ind2 - 1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, text1, text2, dp);

        // tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base case
        // space optimization
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1]) {
                    cur[ind2] = 1 + prev[ind2 - 1];
                }
                else {
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    void printLongestCommonSubSequence(string s1, string s2, vector<vector<int>> &dp)
    {
        int i = dp.size();
        int j = dp[0].size();

        // build emtpy string
        string s = "";
        for (int k = 0; k <= i; k++)
            s.push_back('$');

        int index = i;
        while (i > 0 && j > 0)
        {
            if (s1[i-1] == s2[j-1]) {
                s[index] = s1[i-1];
                index--;
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) 
                i--;
            else
                j--;
        }
    }
};

int main()
{
    string s1 = "abcde", s2 = "ace";
    Solution obj;
    cout << obj.longestCommonSubsequence(s1, s2);
    return 0;
}