#include<bits/stdc++.h>
using namespace std;

int countSubArrs(vector<int> &nums, int k)
{
    if (k<0) return 0;
    int sum = 0;
    unordered_map<int, int> mp;
    int left = 0, right = 0;
    while (right < nums.size())
    {
        mp[nums[right]]++;
        while (mp.size() > k) {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0)
                mp.erase(nums[left]);
            left++;
        }
        sum += (1+right-left);
        right++;
    }
    return sum;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return countSubArrs(nums, k) - countSubArrs(nums, k-1);
}

int main()
{
    return 0;
}