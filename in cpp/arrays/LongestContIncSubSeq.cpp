#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int prev = nums[0] - 1;
        int longestSeq = 0, maxLen = 0;
        for (int num : nums) {
            if (num > prev)
                longestSeq++;
            else longestSeq = 1;
            prev = num;
            maxLen = max(maxLen, longestSeq);
        }
        return maxLen;
    }
};

int main()
{

    return 0;
}