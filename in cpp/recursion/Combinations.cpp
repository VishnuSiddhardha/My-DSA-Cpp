#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int start, int n, int k, vector<int> &temp, vector<vector<int>> &res)
    {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        int curSize = temp.size()+1;
        for (int i = start; i <= n; i++) {
            if (n-i < k-curSize) {
                cout << "n: " << n << ", i: " << i << ", n-i: " << n-i << endl;
                cout << "k: " << k << ", curSize: " << curSize << ", k-cursize: " << k-curSize << endl;
                continue;
            }
            temp.push_back(i);
            solve(i+1, n, k, temp, res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1, n, k, temp, res);
        return res;
    }
};

int main() 
{  
    Solution obj;
    vector<vector<int>> ans = obj.combine(4,2);
    for (vector<int> lis : ans) {
        for (int x : lis)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}