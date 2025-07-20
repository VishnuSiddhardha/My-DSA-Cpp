#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size()-1;
    int maxProd = nums[0], left = 1, right = 1;
    
    for (int i = 0; i <= n; i++) {
        // from left to right
        left *= nums[i];
        maxProd = max(maxProd,left);
        if (left==0) left = 1;

        // from right to left
        right *= nums[n-i];
        maxProd = max(maxProd,right);
        if (right==0) right = 1;
    }
    return maxProd;
    
}

int main()
{
    vector<int> arr = {-1, -3, -10, 0, 6};
    int result = maxProduct(arr);
    cout << result;
    return 0;
}