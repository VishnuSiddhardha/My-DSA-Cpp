#include<bits/stdc++.h>
using namespace std;

int totalSubSets(vector<int> arr, int value) {
    int curVal = arr[0], sets = 1;
    cout << "for value: " << value << endl;
    for (int i = 1; i < arr.size(); i ++) {
        cout << "curval: " << curVal << " arr[i]+curval : " << arr[i] + curVal << endl;
        if (arr[i] + curVal > value) {
            cout << "setting value to 0: " << curVal << endl;
            curVal = 0;
            sets++;
        }
        curVal += arr[i];
    }
    cout << "Returning sets: " << sets << endl;
    return sets;
}

int splitArray(vector<int>& nums, int k) {
    int low = 0, high = 0;
    for (auto x : nums) {
        low = max(low,x);
        high += x;
    }

    while (low <= high) {
        int mid = (low + high)/2;
        if (totalSubSets(nums, mid) <= k) {
            cout << "entered 1st: " << mid << endl;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {1,4,4};
    int k = splitArray(arr, 3);
    cout << "Final answer: " << k << endl;
    return 0;
}