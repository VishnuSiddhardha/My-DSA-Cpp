#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> arr(123, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char &ch : s) {
            if (vowels.find(tolower(ch)) != vowels.end()) arr[ch]++;
        }
        int n = s.length(), vIdx = 65;
        for (int i = 0; i < n; i++) {
            while (vIdx < 123 && !arr[vIdx]) vIdx++;
            if (vowels.find(tolower(s[i])) != vowels.end()) {
                s[i] = vIdx;
                arr[vIdx]--;
                if (!arr[vIdx]) vIdx++;
            }
        }
        return s;
    }
};

int main()
{
    Solution obj;
    cout << obj.sortVowels("AlEetcOdea");
    return 0;
}