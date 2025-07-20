#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;  // max-heap by first if second equal
        return a.second < b.second;    // max-heap by second
    }
};
// O(klogn)
vector<int> topKFrequent2(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int x : nums)
        mp[x]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxheap;
    for (pair<int, int> x : mp)
        maxheap.push(x);
    vector<int> topK;
    for (int i = 0; i < k; i++) {
        topK.push_back(maxheap.top().first);
        maxheap.pop();
    }
    return topK;
}
// O(n)
vector<int> topKFrequent(vector<int> &nums, int k) 
{
    unordered_map<int, int> mp;
    for (int x : nums)
        mp[x]++;
    vector<vector<int>> vc(nums.size()+1);
    for (pair<int, int> x : mp) {
        vc[x.second].push_back(x.first);
    }
    vector<int> topK;
    int i = vc.size()-1, j = 0;
    while (topK.size() < k) {
        if (vc[i].size() != 0 && j != vc[i].size()) {
            topK.push_back(vc[i][j]);
            j++;
        }
        else {
            i--;
            j = 0;
        }
    }
    return topK;
}

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result = topKFrequent(nums, 2);
    for (int x : result)
        cout << x << " ";
    return 0;
}