#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    void solve(int ind, vector<int> &nums, vector<vector<int>> &res, vector<bool> &used)
    {
        if (ind == n-1) {
            res.push_back(nums);
        }
        for (int i = ind; i < n; i++)
        {
            if (i != ind && nums[i] == nums[ind]) continue;
            swap(nums[ind], nums[i]);
            solve(ind+1, nums, res, used);
            swap(nums[ind], nums[i]);
        }
    }
    void helper(vector<int> &arr, vector<vector<int>> &res, unordered_map<int, int> &cntr)
    {
        if (arr.size() == n) {
            res.push_back(arr);
            return;
        }
        for (auto &p: cntr)
        {
            int ele = p.first;
            int count = p.second;
            if (count == 0) continue;
            p.second--;
            arr.push_back(ele);
            helper(arr, res, cntr);
            p.second++;
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // n = nums.size();
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> res;
        // vector<bool> used(n, false);
        // solve(0, nums, res, used);

        // return res;
        vector<vector<int>> res;
        unordered_map<int, int> counter;
        for (int &ele : nums) counter[ele]++;
        vector<int> arr;
        helper(arr, res, counter);
        return res;
    }

};
int main()
{
    vector<vector<int>> result;
    Solution obj;
    vector<int> nums = {1,1,4};
    result = obj.permuteUnique(nums);
    for (auto x : result) {
        for (int ele : x)   
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}