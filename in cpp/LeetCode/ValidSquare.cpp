#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getDistSq(vector<int>& p1, vector<int>& p2) {
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<int> distances;

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int d = getDistSq(points[i], points[j]);
                if (d == 0) return false;  // overlapping points
                distances.insert(d);
            }
        }

        // For a square: 4 equal sides, 2 equal diagonals → only 2 unique distances
        return distances.size() == 2;
    }
};


int main()
{
    vector<int> p1 = {0,0}, p2 = {1,1}, p3 = {0,1}, p4 = {1,0};
    Solution obj;
    cout << obj.validSquare(p1, p2, p3, p4);
    return 0;
}