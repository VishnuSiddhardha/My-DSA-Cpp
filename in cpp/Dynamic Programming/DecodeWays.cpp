#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    int solve(int ind, string &s, vector<int> &dp) {
        if (ind == n) return 1;  // reached end → valid decode
        if (s[ind] == '0') return 0; // can't decode '0' alone
        if (dp[ind] != -1) return dp[ind];

        int count = 0;

        // Single digit
        count += solve(ind + 1, s, dp);

        // Two digits (check bounds + <=26)
        if (ind + 1 < n) {
            int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
            if (num <= 26) {
                count += solve(ind + 2, s, dp);
            }
        }

        return dp[ind] = count;
    }

public:
    int numDecodings(string s) {
        n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp);

        // tabulation
        vector<int> dp(n+1,0);
        // base cases
        dp[n]=1;
        for (int ind = n-1; ind >= 0; ind--)
        {
            if(s[ind]=='0'){
                dp[ind] = 0;
                continue;
            }
            int count = 0;
            count += dp[ind + 1];
            if (ind + 1 < n) {
                int num = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
                if (num <= 26) {
                    count += dp[ind + 2];
                }
            }
            dp[ind] = count;
        }
        return dp[0];
    }
};

int main()
{
    Solution obj;
    cout << obj.numDecodings("11106");
    return 0;
}