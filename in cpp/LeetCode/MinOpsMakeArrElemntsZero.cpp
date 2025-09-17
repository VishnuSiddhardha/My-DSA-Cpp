#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countOperations(int l, int r)
    {
        vector<int> res;
        // [0,1] bucket
        if (r >= 0)
        {
            int lo = max(l, 0);
            int hi = min(r, 1);
            if (lo <= hi)
                res.push_back(hi - lo + 1);
        }
        // buckets [2^k, 2^(k+1)-1] for k >= 1
        int cntr = 1;
        for (int k = 1; k <= 30; k++)
        {
            if (!(k&1)) cntr++; // if not an odd number
            long long lo = (1 << k);
            long long hi = (1 << (k + 1)) - 1;
            if (lo > r)
                break;
            int left = max(lo, (long long)l);
            int right = min(hi, (long long)r);
            if (left <= right)
            {
                // that many req operations for this range of numbers
                res.push_back((right - left + 1)*cntr); 
            }
        }
        // return res;
        for (int x : res)
            cout << x << " ";
        cout << endl;
        int i = 0, j = res.size()-1;
        long long count = 0;
        // pair the large ops with small and minimize them
        while (i < j) {
            if (res[i] > res[j]) {
                swap(res[i], res[j]);
                continue;
            }
            count += res[i];
            res[j] = res[j] - res[i];
            i++;
        }
        count += (res[j]/2 + res[j]%2);
        return count;
    }

public:
    long long minOperations(vector<vector<int>> &queries)
    {
        long long count = 0;
        for (vector<int> &nums : queries)
        {
            count += countOperations(nums[0], nums[1]);
            cout << endl;
        }
        return count;
    }
};

int main()
{
    Solution obj;
    obj.countOperations(2, 20);
    return 0;
}