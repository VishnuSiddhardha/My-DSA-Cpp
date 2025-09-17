#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n + 1, 0);
        unordered_set<long long> edgeSet;

        // Encode edges in hash set for O(1) lookup
        for (auto &e : edges) {
            int u = min(e[0], e[1]);
            int v = max(e[0], e[1]);
            degree[u]++;
            degree[v]++;
            edgeSet.insert(((long long)u << 32) | v);
        }

        auto hasEdge = [&](int u, int v) {
            if (u > v) swap(u, v);
            return edgeSet.count(((long long)u << 32) | v);
        };

        // Find odd degree nodes
        vector<int> oddDegNodes;
        for (int i = 1; i <= n; i++) {
            if (degree[i] & 1) {
                oddDegNodes.push_back(i);
            }
        }

        int odds = oddDegNodes.size();
        if (odds == 0) return true;           // Already Eulerian
        if (odds != 2 && odds != 4) return false; // Only 0, 2, or 4 works

        if (odds == 2) {
            int a = oddDegNodes[0], b = oddDegNodes[1];
            // If they are not directly connected, add edge (a, b)
            if (!hasEdge(a, b)) return true;
            // Else try connecting them through some other node
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b && !hasEdge(a, i) && !hasEdge(b, i))
                    return true;
            }
            return false;
        }

        // Case when odds == 4
        int a = oddDegNodes[0], b = oddDegNodes[1];
        int c = oddDegNodes[2], d = oddDegNodes[3];

        // We need to check if we can pair them up with two edges
        if ((!hasEdge(a, b) && !hasEdge(c, d)) ||
            (!hasEdge(a, c) && !hasEdge(b, d)) ||
            (!hasEdge(a, d) && !hasEdge(b, c)))
            return true;

        return false;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};
    cout << (sol.isPossible(n, edges) ? "true" : "false") << endl;
    return 0;
}


int main() {
    
    return 0;
}