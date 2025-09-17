#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<int> st;        // stores potential "2"s (nums[j])
        int third = INT_MIN;  // this is the "2" in 132 pattern

        // scan from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < third) {
                // nums[i] is the "1", third is "2", and stack had "3"
                return true;
            }
            while (!st.empty() && st.top() < nums[i]) {
                // pop smaller numbers, last popped is the best "2"
                third = st.top();
                st.pop();
            }
            st.push(nums[i]); // push potential "3"
        }
        return false;
    }
};


int main() {
    vector<int> arr = {1,0,1,-4,-3};
    Solution obj;
    cout << obj.find132pattern(arr);
    return 0;
}