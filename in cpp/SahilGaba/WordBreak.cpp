#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    bool canBreak(int ind, string &s, unordered_set<string> &st, unordered_map<int, bool> &dp)
    {
        if (ind == n)
            return true;
        if (dp.count(ind))
            return dp[ind];

        for (int end = ind + 1; end <= n; end++)
        {
            string word = s.substr(ind, end - ind);
            if (st.count(word) && canBreak(end, s, st, dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> dp;
        return canBreak(0, s, st, dp);

        // tabulation
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // base case: empty string

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main()
{

    return 0;
}