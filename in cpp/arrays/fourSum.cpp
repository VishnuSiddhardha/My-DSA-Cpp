#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i,first = 0;
    while (first < n - 3)
    {
        int sum = nums[first];
        i = first+1;
        while (i < n - 2)
        {
            int j = i + 1, k = n - 1;
            long long inner_sum;
            while (j < k)
            {
                inner_sum = nums[i] + nums[j] + nums[k];
                if ( (sum +  inner_sum) == target)
                {
                    result.push_back({nums[first],nums[i], nums[j++], nums[k--]});
                    while (j < n && nums[j] == nums[j - 1])
                        j++;
                    while (k > 0 && nums[k] == nums[k + 1])
                        k--;
                }
                else if ( (sum + inner_sum) < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1])
                i++;
        }
        first++;
        while (first < n && nums[first] == nums[first-1]) first++;
    }
    return result;
}

int main()
{
    vector<int> arr = {1000000000,1000000000,1000000000,1000000000};
    vector<vector<int>> result = fourSum(arr,0);
    for (vector<int> v : result)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}