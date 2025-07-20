#include<bits/stdc++.h>
using namespace std;
// naive + time complexity exceded
void generateAllSubSequences(vector<int> &nums, int ind, int minN, int maxN, int target, int& count) 
{
    if ((minN+maxN) > target) return;
    if (ind == nums.size()) {
        if ((minN+maxN) <= target) {
            count = (count + 1) % 1000000007;
        }
        return;
    }
    generateAllSubSequences(nums, ind+1, minN, maxN, target, count);
    generateAllSubSequences(nums, ind+1, min(minN, nums[ind]), max(maxN, nums[ind]) , target, count);
    // driver code;
    // int count = 0;
    // int mod = 1000000007;
    // generateAllSubSequences(nums, 0, INT_MAX, INT_MIN, target, count);
    // count %= mod;
    // return count-1;
}

int numSubseq(vector<int>& nums, int target) {
    int mod = 1000000007;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        // for element self check
        int minVal = nums[i], maxVal = nums[i];
        if (minVal+maxVal <= target) {
            count = (count+1) % mod;
        }
        for (int j = i+1; j < nums.size(); j++) {
            minVal = min(nums[j], minVal);
            maxVal = max(nums[j], maxVal);
            if ((minVal + maxVal) <= target) {
                count += ((int)pow(2, (j-i-1))) % mod;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {7,10,7,3,7,5,4};
    int noOfSubs = numSubseq(arr, 12);
    cout << "No of sub sequences are: " << noOfSubs << endl;
    return 0;
}