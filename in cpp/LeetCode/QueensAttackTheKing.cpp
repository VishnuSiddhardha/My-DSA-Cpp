#include <bits/stdc++.h>
using namespace std;

class Solution
{
    set<pair<int, int>> st;
    void findQueen(int r, int c, vector<int> &dir, vector<vector<int>> &res) {
        while (r >= 0 && c >= 0 && r < 8 && c < 8) {
            if (st.count({r,c})) {
                res.push_back({r, c});
                return;
            }
            r += dir[0];
            c += dir[1];
        }
    }
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        for (vector<int> &pos : queens) st.insert({pos[0], pos[1]});

        vector<vector<int>> res;
        for (int i = 0; i < 8; i++) {
            findQueen(king[0], king[1], dirs[i], res);
        }
        return res;
    }
};

int main()
{

    return 0;
}