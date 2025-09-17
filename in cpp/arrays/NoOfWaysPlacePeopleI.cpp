#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        cout << "After sorting\n";
        for (vector<int> &arr : points) {
            cout << arr[0] << " " << arr[1] << endl;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            int maxY = -1, yi = points[i][1];
            for (int j = i+1; j < n; j++) {
                int yj = points[j][1];
                if (yj > maxY && yj <= yi) {
                    count++;
                    maxY = points[j][1];
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> points = {{0,3},{0,0}};
    Solution obj;
    obj.numberOfPairs(points);
    return 0;
}