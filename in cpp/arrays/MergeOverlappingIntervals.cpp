#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), [](vector<int> one, vector<int> two)
         {
            if (one[0]==two[0]) return one[1] < two [1];
            else 
            return one[0] < two[0]; });
    int ptr = 0;
    while (ptr < intervals.size())
    {
        int one = intervals[ptr][0];
        int two = intervals[ptr][1];
        cout << "ptr-> " << ptr << " one-> " << one << " two-> " << two << endl;
        ptr++;
        while (ptr < intervals.size()) {
            if (two >= intervals[ptr][1]) 
                ptr++;
            else if (two >= intervals[ptr][0]) 
            {
                two = intervals[ptr][1];
                ptr++;
            }
            else break;
        }
        result.push_back({one, two});
    }
    return result;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);
    cout << "After processing:\n";
    for (auto x : result)
    {
        for (int ele : x)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}