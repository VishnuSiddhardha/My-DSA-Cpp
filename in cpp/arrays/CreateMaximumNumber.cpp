#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<int> st;

public:
    vector<int> buildMaxLargestSubSeq(vector<int> &nums, int n, int k)
    {
        vector<int> st;    
        int drops = n - k; 
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.back() < nums[i] && drops > 0)
            {
                st.pop_back();
                drops--;
            }
            if (st.size() < k)
            {
                st.push_back(nums[i]);
            }
            else
            {
                drops--;
            }
        }

        return st; //
    }
    void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &res)
    {
        int i = 0, j = 0, iend = arr1.size(), jend = arr2.size();
        int k = 0;
        while (i < iend && j < jend)
        {
            if (arr1[i] < arr2[j])
            {
                res[k] = arr2[j];
                j++;
            }
            else
            {
                res[k] = arr1[i];
                i++;
            }
            k++;
        }
        while (i < iend)
        {
            res[k] = arr1[i];
            i++;
            k++;
        }
        while (j < jend)
        {
            res[k] = arr2[j];
            j++;
            k++;
        }
    }
    bool compare(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] > nums2[i])
                return false;
            else if (nums1[i] < nums2[i])
                return true;
        }
        return false;
    }

public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(k, 0), temp(k, 0);
        for (int pick = 0; pick <= k; pick++)
        {
            int len2 = k - n2;
            if (len2 > n2)
                continue;

            vector<int> arr1 = buildMaxLargestSubSeq(nums1, n1, pick);
            vector<int> arr2 = buildMaxLargestSubSeq(nums2, n2, len2);
            merge(arr1, arr2, temp);
            if (compare(ans, temp))
                ans = temp;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {9, 1, 2, 5, 8, 3};
    stack<int> st;
    Solution obj;
    obj.buildMaxLargestSubSeq(arr, arr.size(), 6, st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}