#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int n = fruits.size();
        vector<bool> selected(n, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            bool placed = false;
            for (int j = 0; j < n; j++)
            {
                if (baskets[j] >= fruits[i] && !selected[j])
                {
                    selected[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) count++;
        }
        return count;
    }
};

int main()
{

    return 0;
}