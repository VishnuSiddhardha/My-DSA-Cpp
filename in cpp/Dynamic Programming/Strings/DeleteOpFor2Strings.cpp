#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int longestCommonSubsequence(string text1, string text2)
        {
            int n = text1.size(), m = text2.size();
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
public:
    int minDistance(string word1, string word2)
    {
        int lcs = longestCommonSubsequence(word1, word2);
        return (word1.length() - lcs) + (word2.length() - lcs);
    }
};

int main()
{

    return 0;
}