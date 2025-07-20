#include <bits/stdc++.h>
using namespace std;

int countSubArrays(vector<int> &nums, int goal)
{
    if (goal < 0) return 0;
    int sum = 0;
    int left = 0, count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum > goal) {
            sum -= nums[left];
            left++;
        }
        count += right-left+1;
    }
    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return countSubArrays(nums, goal) - countSubArrays(nums, goal-1);
}

int main()
{
    vector<int> arr = {0,0,0,0,0};
    int subArrs = numSubarraysWithSum(arr, 0);
    cout << subArrs << endl;
    return 0;
}