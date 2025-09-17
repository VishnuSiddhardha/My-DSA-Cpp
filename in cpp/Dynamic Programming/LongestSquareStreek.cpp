#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_map<int, int> dp;
        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 0;
        for (auto &x : st) {
            int rootNum = pow(x, (float)0.5);
            cout << "normal num: " << x << " , root: " << rootNum << endl;
            if (rootNum*rootNum == x && dp.find(rootNum) != dp.end()) {
                dp[x] = dp[rootNum] + 1;
                maxLen = max(maxLen, dp[x]);
            }
            else dp[x] = 1;
        }
        return maxLen > 1 ? maxLen : -1;
    }
};
// another approch
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int arr[100001]={0};
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int len=1;
            long long x=nums[i];
            long long sq=x*x;
            while(sq<=100000 && arr[sq]>0){
                
                x=sq;
                sq=x*x;
                len++;
            }
            if(len>=2) ans=max(len,ans);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {4,3,6,16,8,2};
    Solution obj;
    obj.longestSquareStreak(arr);
    return 0;
}