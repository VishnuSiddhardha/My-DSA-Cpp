#include<bits/stdc++.h>
using namespace std;

int countSubArrays(vector<int> &nums, int goal)
{
    if (goal < 0) return 0;
    int odds = 0;
    int left = 0, count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] & 1) odds++;
        while (odds > goal) {
            if (nums[left] & 1) odds--;
            left++;
        }
        count += right-left+1;
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return countSubArrays(nums, k) - countSubArrays(nums, k-1);
}

int main()
{
    return 0;
}