#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    priority_queue<int> pq;
    unordered_map<char, int> mp;
    for (char ch : tasks)
        mp[ch]++;
    for (auto x : mp)
        pq.push(x.second);
    int time = 0;
    queue<pair<int,int>> qu;
    while(!pq.empty() || !qu.empty()) {
        time += 1;
        if (!pq.empty()) {
            int cnt = pq.top() -1;
            pq.pop();
            if (cnt) qu.push({cnt, time+n});
        }
        if (!qu.empty() && qu.front().second == time) {
            pq.push(qu.front().first);
            qu.pop();
        }
    }
    return time;
}

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int time = leastInterval(tasks, 3);
    cout << "Least time: " << time << endl;
    return 0;
}