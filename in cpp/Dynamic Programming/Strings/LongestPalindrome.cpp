#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxLen = 1, start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++){ // single length strings
            dp[i][i] = true;
        }
        for (int i = 0; i < n-1; i++) { // length 2 strings
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                maxLen = 2;
                start = i;
            }    
        }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n-len; i++)
            {
                int j = i+len-1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{

    return 0;
}