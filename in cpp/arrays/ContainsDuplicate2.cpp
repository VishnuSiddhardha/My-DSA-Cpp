#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {

            if (mp.find(nums[i]) != mp.end())
            {
                int dist = i-mp[nums[i]];
                if (dist <= k) return true;
            }
            mp[nums[i]] = i;
            cout << "nums[i]: " << nums[i] << " , mp[nums[i]]: " << mp[nums[i]] << endl;
           
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,1,2,3,4,1,2,3};
    Solution obj;
    cout << obj.containsNearbyDuplicate(nums, 6);
    return 0;
}