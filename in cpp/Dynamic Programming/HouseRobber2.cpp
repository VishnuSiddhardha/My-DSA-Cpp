#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rob1(vector<int> &nums, int beg, int end)
    {
        int one = 0;
        int two = nums[beg];

        for (int i = beg+1; i < end; i++) 
        {
            int inc = nums[i] + one;
            int notInc = two;

            one = two;
            two = max(inc, notInc);
        }
        return two;
    }
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int firstHalf = rob1(nums, 0, n-1);
        int secondHalf = rob1(nums, 1, n);
        return max(firstHalf, secondHalf);
    }
};

int main()
{

    return 0;
}