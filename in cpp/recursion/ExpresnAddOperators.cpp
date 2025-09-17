#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        dfs(num, target, 0, 0, 0, path, res);
        return res;
    }

private:
    void dfs(const string &num, long target, int pos, long eval, long multed,
             string &path, vector<string> &res) {
        
        if (pos == num.size()) {
            if (eval == target) res.push_back(path);
            return;
        }

        long cur = 0;
        int len = path.size();  // store size for backtracking

        for (int i = pos; i < num.size(); i++) {
            // skip numbers with leading zero
            if (i > pos && num[pos] == '0') break;

            cur = cur * 10 + (num[i] - '0');
            string curStr = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                // first number, no operator
                path += curStr;
                dfs(num, target, i + 1, cur, cur, path, res);
                path.resize(len);  // backtrack
            } else {
                // '+'
                path += "+" + curStr;
                dfs(num, target, i + 1, eval + cur, cur, path, res);
                path.resize(len);

                // '-'
                path += "-" + curStr;
                dfs(num, target, i + 1, eval - cur, -cur, path, res);
                path.resize(len);

                // '*'
                path += "*" + curStr;
                dfs(num, target, i + 1, eval - multed + multed * cur, multed * cur, path, res);
                path.resize(len);
            }
        }
    }
};


int main()
{
    Solution obj;
    vector<string> res = obj.addOperators("232",8);
    for (string s: res)
    cout << s << endl;
    return 0;
}
