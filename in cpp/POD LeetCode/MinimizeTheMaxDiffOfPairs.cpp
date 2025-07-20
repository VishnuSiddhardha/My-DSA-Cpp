#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int p, int ans)
{
    int count = 0;
    int i = 0, j = 1, n = nums.size();
    while (j < n)
    {
        if (nums[j] - nums[i] < ans) {
            count++;
            i = i+2;
            j = j+2;
        }
        else
        {
            j++;
            i++;
        }
    }
    return count >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());
    int low = 0, high = nums[nums.size()-1];
    while (low <= high)
    {
        int mid = (low+high) >> 1; // divide by 2
        bool temp = isPossible(nums, p, mid);
        if (temp)
            high = mid-1;
        else
            low = mid+1;
    }
    return low;
}

int main()
{

    return 0;
}