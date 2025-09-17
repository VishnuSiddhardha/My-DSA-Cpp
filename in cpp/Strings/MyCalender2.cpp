#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
    vector<pair<int,int>> intervals, overLapping;
    map<int, int> mp;
public:
    MyCalendarTwo() {}

    bool book(int startTime, int endTime)
    {
        for (auto &p : overLapping) {
            if (max(p.first, startTime) < min(p.second, endTime))
                return false; 
        }
        for (auto &p : intervals) {
            int l = max(startTime, p.first), r = min(endTime, p.second);
            if ( l < r ) {
                overLapping.push_back({l,r});
            }
        }
        intervals.push_back({startTime, endTime});
        return true;
    }
    bool book(int start, int end) 
    {
        int bookings = 0;
        mp[start]++;
        mp[end]--;
        for (auto &p : mp)
        {
            bookings += p.second;
            if (bookings > 2) {
                mp.erase(start);
                mp.erase(end);
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}