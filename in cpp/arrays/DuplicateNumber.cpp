#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int x : nums)
        {
            int ind = abs(x)-1;
            if (nums[ind] < 0) return ind+1;
            nums[ind] = -nums[ind];
        }
        return 0;
    }
};

int main()
{

    return 0;
}