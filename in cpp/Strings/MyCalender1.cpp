#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
    map<int, int> booked; // start -> end
public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = booked.lower_bound(start);

        // Case 1: overlap with next interval
        if (it != booked.end() && it->first < end) 
            return false;

        // Case 2: overlap with previous interval
        if (it != booked.begin()) {
            auto prevIt = std::prev(it); // use std::prev()
            if (prevIt->second > start) 
                return false;
        }

        booked[start] = end;
        return true;
    }
};


int main()
{

    return 0;
}