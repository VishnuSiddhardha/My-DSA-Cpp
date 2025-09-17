#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_set<int> cantCom;
        unordered_map<int, int> mp;
        for (auto &x: friendships) {
            int u = x[0], v = x[1];
            for (int &la: languages[u-1]) mp[la] = 1;
            bool common = false;
            for (int &la : languages[v-1]) {
                if (mp.find(la) != mp.end()) {
                    common = true;
                    break;
                }
            }
            if (!common) {
                cantCom.insert(u-1);
                cantCom.insert(v-1);
            }
            mp.clear();
        }
        vector<int> comLangs(n+1, 0);
        int maxCount = 0;
        for (auto &ele : cantCom) {
            for (int lan: languages[ele]) {
                comLangs[lan]++;
                maxCount = max(maxCount, comLangs[lan]);
            }
        }
        return cantCom.size() - maxCount;
    }
};

int main()
{

    return 0;
}