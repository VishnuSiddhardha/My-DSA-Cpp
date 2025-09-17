#include <bits/stdc++.h>
using namespace std;

bool customComparison(string a, string b)
{
    return a.length() < b.length(); // it sorts in ascending order
}
class Solution
{
    bool isNextSequence(string s1, string s2)
    {
        int i = 0, j = 0;
        int n = s1.length(), m = s2.length();
        if (n+1 != m) return false;
        bool once = true;
        while (i < n && j < m)
        {
            if (s1[i] == s2[j]){
                i++;j++;
            }
            else if (once) {
                once = false;
                j++;
            }
            else return false;
        }
        return true;
    }
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), customComparison);
        vector<int> dp(n, 1);

        int lisLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
            {
                if ((isNextSequence(words[j], words[i])) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            lisLen = max(lisLen, dp[i]);
        }
        return lisLen;
    }
    
};

class Solution {
public:
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        int maxLen = 1;
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.length(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[word]);
        }

        return maxLen;
    }
};


int main()
{
    Solution obj;
    // obj.longestStrChain();
    return 0;
}