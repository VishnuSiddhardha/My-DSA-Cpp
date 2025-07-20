#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> mp;
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
        mp[nums1[i]] = i;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; --i)
    {
        if (mp.count(nums2[i]))
        {
            while (!st.empty() && st.top() < nums2[i])
                st.pop();
            if (st.empty())
                res[mp[nums2[i]]] = -1;
            else
                res[mp[nums2[i]]] = st.top();
        }
        st.push(nums2[i]);
    }
    return res;
}

int main()
{
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    for (auto x : res)
        cout << x  << " ";
    return 0;
}