#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums) {
//     vector<vector<int>> result;
//     for (int i = 0; i < nums.size()-2; i++)
//     {
//         int req = -nums[i];
//         unordered_map<int,int> mp;
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if (mp.count(req-nums[j])) {
//                 result.push_back({-req,req-nums[j],nums[j]});
//             }
//             mp[nums[j]] = 1;
//         }
//         mp.clear();
//     }
//     return result;
// }

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int i = 0;
    while (i < n-2) {
        int j = i+1, k = n-1;
        int sum = nums[i] + nums[j] + nums[k];
        while (j < k) {
            if (sum==0) {
                result.push_back({nums[i],nums[j++],nums[k--]});
                while (j < n && nums[j] == nums[j-1]) j++;
                while (k > 0 && nums[k] == nums[k+1]) k--;
                if (j < n && k > 0) sum = nums[i] + nums[j] + nums[k];
            }
            else if (sum < 0) {
                sum -= nums[j++];
                sum += nums[j];
            }
            else {
                sum -= nums[k--];
                sum += nums[k];
            }
        }
        i++;
        while (i < n && nums[i] == nums[i-1]) i++;
    }
    return result;
} 

int main()
{
    vector<int> arr = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> result = threeSum(arr);
    for (vector<int> v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}