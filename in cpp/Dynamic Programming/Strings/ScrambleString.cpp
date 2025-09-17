#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;
    
    bool dfs(string a, string b) {
        if (a == b) return true;
        string key = a + "#" + b;
        if (memo.count(key)) return memo[key];
        
        if (string(a.begin(), a.end()) != string(b.begin(), b.end())) {
            string sa = a, sb = b;
            sort(sa.begin(), sa.end());
            sort(sb.begin(), sb.end());
            if (sa != sb) return memo[key] = false;
        }
        
        int n = a.size();
        for (int i = 1; i < n; i++) {
            // no swap
            if (dfs(a.substr(0,i), b.substr(0,i)) && dfs(a.substr(i), b.substr(i)))
                return memo[key] = true;
            // swap
            if (dfs(a.substr(0,i), b.substr(n-i)) && dfs(a.substr(i), b.substr(0,n-i)))
                return memo[key] = true;
        }
        return memo[key] = false;
    }
    
public:
    bool isScramble(string s1, string s2) {
        return dfs(s1, s2);
    }
};

int main() {
    
    return 0;
}