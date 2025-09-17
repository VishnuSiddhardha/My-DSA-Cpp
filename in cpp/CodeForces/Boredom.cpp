#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int solveBoredom(vector<int> &arr)
        {
            unordered_map<int, int> cnt;
            int maxi = 0;
            for (int x : arr) {
                cnt[x]++;
                maxi = max(maxi, x);
            }
            // dp array
            vector<int> dp(maxi+1, 0);
            // base cases
            dp[0] = 0;
            dp[1] = cnt[1];
            // logic for other states
            for (int i = 2; i <= maxi; i++)
                dp[i] = max(dp[i-1], i * cnt[i] + dp[i-2]);

            return dp[maxi];
        }
};

int main() {
    
    return 0;
}