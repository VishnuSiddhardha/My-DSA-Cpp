#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // vector<vector<int>> matrix;
    unordered_set<int> mp;
    int m, n;
    int randInRange(int L, int R)
    {
        return L + rand() % (R - L + 1);
    }
public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        // matrix.resize(m, vector<int>(n, 0));
    }

    vector<int> flip()
    {
        int up = m*n - 1;
        int randomNum = randInRange(0,up);

        while (mp.find(randomNum) != mp.end())
            randomNum = randInRange(0, up);
        mp.insert(randomNum);
        int r = randomNum / n, c = randomNum % n;
        return {r, c};
    }

    void reset()
    {
        mp.clear();
    }
};

class Solution {
    int m, n;
    int total;  // remaining unflipped cells
    unordered_map<int, int> mp;

    int randInRange(int L, int R) {
        return L + rand() % (R - L + 1);
    }

public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
        srand(time(0));
    }

    vector<int> flip() {
        int randIdx = randInRange(0, total - 1);

        // If randIdx is already remapped, use the mapped value
        int actualIdx = mp.count(randIdx) ? mp[randIdx] : randIdx;

        // Decrease the total
        total--;

        // Map randIdx -> last available index
        mp[randIdx] = mp.count(total) ? mp[total] : total;

        // Convert 1D index back to 2D
        int r = actualIdx / n;
        int c = actualIdx % n;
        return {r, c};
    }

    void reset() {
        mp.clear();
        total = m * n;
    }
};


int main()
{

    return 0;
}