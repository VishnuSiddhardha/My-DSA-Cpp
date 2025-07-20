#include<bits/stdc++.h>
using namespace std;
// prefix sum techinique
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> right(n), left(n);
    right[0] = height[0];
    left[n-1] = height[n-1];
    for (int i = 1; i < n-1; i++)
    {
        right[i] = max(height[i],right[i-1]);
        left[n-1-i] = max(height[n-1-i], left[n-i]);

    }
    right[n-1] = max(height[n-1],right[n-2]);
    left[0] = max(height[0],left[1]);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int val = min(left[i],right[i]) - height[i];
        sum += val;
    }
    return sum;

}

// two pointer approch

int trap2(vector<int>& height) {
    int sum = 0;
    int leftMax = 0, rightMax = 0;
    int i = 0, j = height.size()-1;
    while (i <= j)
    {
        if (height[i] <= height[j])
        {
            if (leftMax > height[i])
                sum += leftMax - height[i];
            else
                leftMax = height[i];
            i++;
        }
        else
        {
            if (rightMax > height[j])
                sum += rightMax - height[j];
            else
                rightMax = height[j];
            j--;
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {0,1,2,0,3,0,1,2,0,0,4,2,1,2,5,0,1,2,0,2};
    int res = trap2(arr);
    cout << "trapped water: " << res;
    return 0;
}