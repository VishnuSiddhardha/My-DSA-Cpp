#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &arr, int d)
    {
        int n = arr.size();
        int sum = 0;
        for (int x : arr) sum += x;
        int target = sum - d;
        if (target < 0 || target % 2 != 0) return 0;
        target /= 2;
        // perform the count the subset sum with k logic
        vector<int> prev(target+1, 0), cur(target + 1, 0);
        if (arr[0] == 0)
            prev[0] = 2;  // pick or not pick
        else
            prev[0] = 1;  // don't pick

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;  // pick if <= target
        for (int ind = 1; ind < n; ind++)
        {
            for (int t = 0; t <= target; t++)
            {
                int nonPick = prev[t];
                int pick = 0;
                if (arr[ind] <= t) pick = prev[t - arr[ind]];
                cur[t] = pick + nonPick;
            }
            prev = cur;
        }
        return prev[target];
    }
};

int main()
{

    return 0;
}