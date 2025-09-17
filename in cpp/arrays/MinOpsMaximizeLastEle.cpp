#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int mx = max(nums1[n-1], nums2[n-1]);
        int mn = min(nums1[n-1], nums2[n-1]);
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int a = nums1[i], b = nums2[i];
            if (max(a,b) > mx || min(a,b) > mn) return -1; // invalid condition
            if (a > nums1[n - 1] || b > nums2[n - 1]) // case where the last numbers are not swapped
                count1++;
            if (a > nums2[n- 1] || b > nums1[n - 1]) // case where the last numbers are swapped
                count2++;
        }
        return min(count1, 1+count2);
    }
};

int main()
{

    return 0;
}