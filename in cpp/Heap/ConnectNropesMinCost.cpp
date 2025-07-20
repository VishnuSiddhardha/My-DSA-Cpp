#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : arr)
        pq.push(x);
    int cost = 0;
    while (pq.size() > 1) {
        int cur = pq.top();
        pq.pop();
        cur += pq.top();
        pq.pop();
        cost += cur;
        pq.push(cur);
    }
    return cost;
}

int main()
{
    return 0;
}