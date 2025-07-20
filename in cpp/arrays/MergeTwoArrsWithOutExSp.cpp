#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = 0;
    while (i >= 0 && j < n)
    {
        if (nums1[i] > nums2[j])
            swap(nums1[i], nums2[j]);
        else 
            break;
        i--;
        j++;
    }  
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
}

int main()
{
    return 0;
}
