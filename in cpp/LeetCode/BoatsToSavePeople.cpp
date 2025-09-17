#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while (i < j)
        {
            int space = limit - people[j];
            if (people[i] <= space) i++;
            boats++;
            j--;
        }
        return boats;
    }
};

int main() {
    vector<int> arr = {3,8,4,9,2,2,7,1,6,10,6,7,1,7,7,6,4,4,10,1};
    Solution obj;
    cout << obj.numRescueBoats(arr, 10);
    return 0;
}