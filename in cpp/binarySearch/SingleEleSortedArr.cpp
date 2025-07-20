#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while (low < high) {
        int mid = (low+high)/2;
        if (mid%2 == 0) {
            if (mid != nums.size()-1 && nums[mid] == nums[mid+1]) { low = mid+1; }
            else {high = mid; }
        }
        else{
            if (mid != 0 && nums[mid] == nums[mid-1]) { low = mid+1; }
            else { high = mid; }
        }
    }
    return nums[low];
}

int main()
{
    vector<int> arr = {3,3,7,7,10,10,11,11,12};
    int result = singleNonDuplicate(arr);
    cout << "element: " << result;
    return 0;
}