#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size.resize(n+1, 0);
        parent.resize(n+1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u), ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet st(n);
        unordered_map<string, int> mp;
        //map the nodes to accordng to their parents
        for (int i = 0; i < n; i++) 
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string s = accounts[i][j];
                if (mp.find(s) != mp.end()) {
                    st.unionBySize(i, mp[s]);
                }
                else {
                    mp[s] = i;
                }
            }
        }
        unordered_map<int, int> name_map;
        vector<vector<string>> res;
        for (auto pr : mp)
        {
            string mail = pr.first;
            int ind = st.findUParent(pr.second);
            // if the node is getting for 1st time
            // then create a vecotr for the node w.r.t the name
            if (name_map.find(ind) == name_map.end()) {
                name_map[ind] = res.size();
                res.push_back({accounts[ind][0]});
            }
            res[name_map[ind]].push_back(mail);
        }
        n = res.size();
        for (int i = 0; i < n; i++)
        {
            sort(res[i].begin()+1, res[i].end());
        }
        return res;
    }
};
// for (int i = 0; i < res.size(); i++) {
//     for (int j = 0; j < res[i].size(); j++)
//         cout << res[i][j] << " ";
//     cout << endl;
// }

int main()
{
    vector<vector<string>> accts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
                                {"John","johnsmith@mail.com","john00@mail.com"},
                                {"Mary","mary@mail.com"},
                                {"John","johnnybravo@mail.com"}};
    Solution obj;
    obj.accountsMerge(accts);
    return 0;
}