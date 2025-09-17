#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        if (forget < delay) return n > forget;
        queue<pair<int, int>> waiting;       // -> store <intime, count>
        queue<pair<int, int>> toDelete;      // -> store <outtime, count> 
        waiting.push({delay+1, 1});
        toDelete.push({forget+1, 1});
        int curExecuting = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (toDelete.front().first == i) {
                curExecuting -= toDelete.front().second;
                toDelete.pop();
            }
            if (waiting.front().first == i) { 
                curExecuting += waiting.front().second;
                waiting.pop();
            }
            if (curExecuting) {
                waiting.push({i+delay, curExecuting});
                toDelete.push({i+forget, curExecuting});
            }
        }
        while (!waiting.empty()) {
            curExecuting += waiting.front().second;
            waiting.pop();
        }
        return curExecuting;
    }
};

int main()
{

    return 0;
}