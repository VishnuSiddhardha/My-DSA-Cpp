#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here
    vector<pair<int, int>> nums;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        nums.push_back({arr[i], dep[i]});
    sort(nums.begin(), nums.end());

    priority_queue<int, vector<int>, greater<int>> platfroms;
    platfroms.push(nums[0].second);
    for (int i = 1; i < n; i++)
    {
        if (platfroms.top() < nums[i].first)
            platfroms.pop();
        platfroms.push(nums[i].second);
    }
    return platfroms.size();
}

int main()
{
    return 0;
}