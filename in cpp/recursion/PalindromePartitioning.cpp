#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    void solve(int i, string s, vector<string> &temp, vector<vector<string>> &res, vector<vector<bool>> &isPal)
    {
        if (i==n){
            res.push_back(temp);
            return;
        }
        string cur="";
        for (int it=i;it<n;it++)
        {
            cur.push_back(s[it]);
            if(isPal[i][it]) {
                temp.push_back(cur);
                solve(it+1,s,temp,res,isPal);
                temp.pop_back();
            }
        }
    }
    void fillPalindromTable(string s, vector<vector<bool>> &dp)
    {
        int maxLen = 1, start = 0;
        for (int i = 0; i < n; i++) // single length strings
            dp[i][i] = true;
        for (int i = 0; i < n-1; i++) { // length 2 strings
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
            }    
        }
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n-len; i++)
            {
                int j = i+len-1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        n = s.length();
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        fillPalindromTable(s,isPal);
        vector<string> temp;
        vector<vector<string>> ans;
        solve(0,s,temp,ans,isPal);
        return ans;
    }
};

int main()
{

    return 0;
}