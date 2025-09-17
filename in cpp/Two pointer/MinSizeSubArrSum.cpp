#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, sum = nums[0];
        if (sum >= target) return 1;
        int len = INT_MAX;
        for (int right = 1; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                len = min(right-left+1, len);
                sum -= nums[left];
                left++;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
}; 

int main()
{

    return 0;
}