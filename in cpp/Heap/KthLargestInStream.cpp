#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() == k && pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
            else if (pq.size() < k)
                pq.push(nums[i]);
        }
        
    }
    
    int add(int val) {
        if (pq.size() < size)
            pq.push(val);
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

int main()
{
    return 0;
}