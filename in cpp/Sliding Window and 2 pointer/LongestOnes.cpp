#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) 
{
    int maxLength = 0, curLen = 0;
    int zeros = 0, start = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zeros++;
        else
            curLen++;
        if (zeros > k) {
            if (nums[start] == 0)
                zeros--;
            else
                curLen--;
            start++;
        }
        if (zeros <= k)
            maxLength = max(maxLength, curLen+zeros);
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int len = longestOnes(arr, 3);
    cout << "result: " << len << endl;
    return 0;
}