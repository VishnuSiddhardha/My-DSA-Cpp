#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) 
{
    vector<int> hashmap(256, 0);
    for (int i = 0; i < t.length(); i++)
        hashmap[t[i]]++;
    int left = 0, right = 0;
    int len = s.length()+1, from = -1, to = -1;
    int count = 0;
    while (right < s.length())
    {
        if (hashmap[s[right]] > 0)
            count++;
        hashmap[s[right]]--;
        while (count == t.length())
        {
            hashmap[s[left]]++  ;
            if (hashmap[s[left]] > 0) count--;
            if (len > (right-left+1)) {
                len = right-left+1;
                from = left;
                to = right;
            }
            left++;
        }
        right++;
    }

    return from == -1 ? "" : s.substr(from, len);
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = minWindow(s, t);
    cout << "result: " << res << endl;
    return 0;
}