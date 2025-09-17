#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int lastIdx = 0;
        int lisLen = 1;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if ((nums[i] % nums[j] == 0) && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (dp[i] > lisLen)
            {
                lisLen = dp[i];
                lastIdx = i;
            }
        }
        // printing the sequence
        vector<int> result;
        result.push_back(nums[lastIdx]);
        while (hash[lastIdx] != lastIdx)
        { // check it once if possible
            lastIdx = hash[lastIdx];
            result.push_back(nums[lastIdx]);
        }
        return result;
    }
};

int main()
{

    return 0;
}