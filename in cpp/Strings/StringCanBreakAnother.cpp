#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canBreak(const string& s1, const string& s2) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) return false;
        }
        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return canBreak(s1, s2) || canBreak(s2, s1);
        int n = s1.size();
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] >= s2[i]) count1++;
            if (s2[i] >= s1[i]) count2++;
        }
        return count1 == n || count2 == n;
    }
};

class Solution {
 public:
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> count1(26);
    vector<int> count2(26);

    for (const char c : s1)
      ++count1[c - 'a'];

    for (const char c : s2)
      ++count2[c - 'a'];

    return canBreak(count1, count2) || canBreak(count2, count1);
  }

 private:
  // Returns true if count1 can break count2.
  bool canBreak(const vector<int>& count1, const vector<int>& count2) {
    int diff = 0;
    for (int i = 0; i < 26; ++i) {
      diff += count2[i] - count1[i];
      // count2 is alphabetically greater than count1.
      if (diff < 0)
        return false;
    }
    return true;
  }
};


int main()
{

    return 0;
}