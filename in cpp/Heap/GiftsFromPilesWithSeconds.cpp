#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>> pq;
        for (int &x: gifts) pq.push(x);
        while (!pq.empty() && k) {
            int top = pow(pq.top(), (float)0.5);
            pq.pop();
            if (top) pq.push(top);
            k--;
        }
        int remPiles = 0;
        while (!pq.empty()) {
            remPiles += pq.top();
            pq.pop();
        }
        return remPiles;
    }
};

int main() {
    
    return 0;
}