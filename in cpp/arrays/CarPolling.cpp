#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> st;
        for (vector<int> &t : trips) {
            st.push_back({t[1], t[0]});
            st.push_back({t[2], -t[0]});
        }
        sort(st.begin(), st.end());
        int cap = 0;
        for (pair<int, int> &p : st) {
            cap += p.second;
            if (cap > capacity) return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}