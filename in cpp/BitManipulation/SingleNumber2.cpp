#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0, zeros = 0;
            for (int i = 0; i < n; i++)
            {
                if (nums[i]&1) count++;
                nums[i] = nums[i] >> 1;
                if (!nums[i]) zeros++;
            }
            if (count % 3) {
                res = res | (1 << i);
            }
            if (zeros == n) break;
        }
        return res;
    }
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main()
{

    return 0;
}