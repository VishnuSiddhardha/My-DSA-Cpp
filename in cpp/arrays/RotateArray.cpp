#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void rangeRotate(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;
        k = n - k;
        rangeRotate(nums, 0, k-1);
        rangeRotate(nums, k, n-1);
        rangeRotate(nums, 0, n-1);
    }
};

int main()
{

    return 0;
}