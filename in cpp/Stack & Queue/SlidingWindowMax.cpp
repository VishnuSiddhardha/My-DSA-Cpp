#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> qu;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!qu.empty() && qu.front() <= i-k) qu.pop_front();
        while (!qu.empty() && nums[i] >= nums[qu.back()])
            qu.pop_back();
        qu.push_back(i);
        if (i >= k-1) result.push_back(nums[qu.front()]);
    }
    return result;
}

int main()
{
    vector<int> arr = {1,3,1,2,0,5};
    vector<int> slidingMax = maxSlidingWindow(arr, 3);
    for (auto x : slidingMax)
        cout << x << " ";
    cout << endl;
    return 0;
}