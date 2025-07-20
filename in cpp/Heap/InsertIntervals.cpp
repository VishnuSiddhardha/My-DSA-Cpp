#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0, n = intervals.size();
    vector<vector<int>> resultIntervals;
    while (i < n)
    {
        if (newInterval[0] > intervals[i][1])
            resultIntervals.push_back(intervals[i]);
        else
            break;
        i++;
    }
    while(i < n)
    {
        if (newInterval[1] < intervals[i][0])
            break;
        else
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
        i++;
    }
    resultIntervals.push_back(newInterval);
    while (i < n)
        resultIntervals.push_back(intervals[i]);
    
    return resultIntervals;
}

int main()
{
    return 0;
}