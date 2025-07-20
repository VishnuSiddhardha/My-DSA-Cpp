#include<bits/stdc++.h>
using namespace std;

bool isPossbile(vector<int> arr, int threshold, int div) {
    int res = 0;
    for (int i = 0; i < arr.size(); i ++) {
        res += ceil( (double)arr[i] / (double)div );
    }
    return res <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(), nums.end());
    
    while (low <= high) {
        int mid = (low+high)/2;
        if (isPossbile(nums,threshold,mid)) {
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {};
    int k  = smallestDivisor(arr,6);
    return 0;
}