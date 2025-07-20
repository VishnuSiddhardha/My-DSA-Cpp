#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int solve(int ind, vector<int> &arr, vector<int> &dp)
    {
        if (ind == 0) return arr[0];
        if (ind < 0) return 0;
        
        if (dp[ind] != -1) return dp[ind];
        int one = solve(ind-1, arr, dp);
        int two = solve(ind-2, arr, dp) + arr[ind];
        
        return dp[ind] = max(one, two);
    }
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int one = 0;
        int two = nums[0];

        for (int i = 1; i < n; i++) 
        {
            int inc = nums[i] + one;
            int notInc = two;

            one = two;
            two = max(inc, notInc);
        }
        return two;
    }
};

int main()
{
    // vector<int> arr = {9, 4, 11, 12, 6, 12};
    vector<int> arr = {9, 10, 5, 7};
    Solution obj;
    cout << obj.rob(arr);
    return 0;
}