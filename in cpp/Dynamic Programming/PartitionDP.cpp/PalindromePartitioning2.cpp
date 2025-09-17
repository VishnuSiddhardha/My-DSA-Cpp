#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    bool isPalindrome(int i, int j, string &s)
    {
        int n = s.length();
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string &s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
                mini = min(mini, 1 + solve(j + 1, s, dp));
        }
        return dp[i] = mini;
    }

public:
    // O(n^3)
    int minCut(string s)
    {
        n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp) - 1;

        // tabulation
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                    mini = min(mini, 1 + dp[j + 1]);
            }
            dp[i] = mini;
        }
        return dp[0]-1;
    }
    // O(n^2)
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> minCuts(n, 0);

        for (int i = 0; i < n; ++i) {
            minCuts[i] = i; 
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    if (j == 0) minCuts[i] = 0;
                    else minCuts[i] = min(minCuts[i], minCuts[j - 1] + 1);
                }
            }
        }

        return minCuts[n - 1];
    }
};

int main()
{

    return 0;
}