#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here
        int n = s1.size(), m = s2.size();
        int ans = 0;
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s1[ind1 - 1] == s2[ind2 - 1]) {
                    cur[ind2] = 1 + prev[ind2 - 1];
                    ans = max(ans, cur[ind2]);
                }
                else {
                    cur[ind2] = 0;
                }
            }
            prev = cur;
        }
        return ans;
    }
};

int main()
{
    return 0;
}