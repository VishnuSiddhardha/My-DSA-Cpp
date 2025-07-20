#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int ele : nums) {
        if (pq.size() == k && (pq.top() < ele)) {
            cout << "popping and adding: " << pq.top() << " " << ele << endl;
            pq.pop();
            pq.push(ele);
        }
        else if (pq.size() < k)
            pq.push(ele);
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {3,2,1,5,6,4};
    cout << findKthLargest(arr, 2);
    return 0;
}