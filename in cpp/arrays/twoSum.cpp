#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.count(target-nums[i])) {
            result.push_back(mp[target-nums[i]]);
            result.push_back(i);
        }
        mp[nums[i]] = i;
    }
    return result;
}

int main()
{
    return 0;
}