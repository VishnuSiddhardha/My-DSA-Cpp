#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1; // to handle case when subarray starts from index 0
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2) return true; // length >= 2
            } else {
                mp[rem] = i; // store only first occurrence
            }
        }
        return false;
    }
};


int main()
{

    return 0;
}