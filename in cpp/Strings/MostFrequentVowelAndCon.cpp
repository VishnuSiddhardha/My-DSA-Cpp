#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> arr(26, 0);
        int cMax = 0, vMax = 0;
        for (char &ch: s) {
            arr[ch-'a']++;
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') vMax = max(vMax, arr[ch-'a']);
            else cMax = max(cMax, arr[ch-'a']);
        }
        return cMax+vMax;
    }
};

int main()
{

    return 0;
}