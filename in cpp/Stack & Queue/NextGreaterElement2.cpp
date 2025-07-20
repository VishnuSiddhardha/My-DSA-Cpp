#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> res(nums.size());
    stack<int> st1;
    // for iterating from front elements
    int incr = 0;
    // checking back the greater ele for every element from back side
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        while (!st1.empty() && st1.top() <= nums[i])
            st1.pop();
        // if the element not found from back side
        // search from front side
        if (st1.empty())
        {
            while (incr < i && nums[incr] <= nums[i])
                incr++;
            if (nums[incr] <= nums[i])
                res[i] = -1;
            else
            {
                res[i] = nums[incr];
            }
        }
        // if the element found from back side
        // simply store it
        else {
            res[i] = st1.top();
        }
        st1.push(nums[i]);
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    vector<int> res = nextGreaterElements(nums);
    for (auto x : res)
        cout << x << " ";
    return 0;
}