#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n, m;
    void longesCommonSubSeq(string &s1, string &s2, vector<vector<int>> &dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1] ) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        n = str1.size();
        m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // bulid the lcs dp talbe
        longesCommonSubSeq(str1, str2, dp);

        int i = n, j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (str1[i-1] == str2[j-1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                ans.push_back(str1[i - 1]);
                i--;
            }
            else {
                ans.push_back(str2[j - 1]);
                j--;
            }
        }
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    string s1 = "geek", s2 = "eke";
    cout << obj.shortestCommonSupersequence(s1, s2);

    return 0;
}