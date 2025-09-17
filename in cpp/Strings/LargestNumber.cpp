#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        s.reserve(nums.size());
        for (int x : nums) s.push_back(to_string(x));

        auto cmp = [](const string& a, const string& b) {
            return a + b > b + a; // sort descending by concatenation
        };
        sort(s.begin(), s.end(), cmp);

        if (s[0] == "0") return "0"; // all zeros

        string res;
        res.reserve(11 * s.size()); // small optimization: average int length
        for (auto& t : s) res += t;
        return res;
    }
};


int main()
{
    Solution obj;
    vector<int> nums = {};
    cout << "final number: " << obj.largestNumber(nums);
    return 0;
}