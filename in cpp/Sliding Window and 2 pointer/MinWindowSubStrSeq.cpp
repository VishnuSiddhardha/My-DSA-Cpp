#include<bits/stdc++.h>
using namespace std;

string minWindow(string& s1, string& s2) {
    // Write your Code here
    int len = INT_MAX, start = -1;
    int left = 0, right = 0;
    int ptr = 0;
    while (right < s1.size()) {
        if (s1[right] == s2[ptr]) ptr++;

        if (ptr == s2.size()) {
            ptr--;
            left = right;
            while (ptr >= 0) {
                if(s1[left] == s2[ptr]) ptr--;
                left--;
            }
            left++;
            if (len > (right-left+1)) {
                len = right-left+1;
                start = left;
            }
            right = left;
            ptr = 0;
        }
        right++;
    }
    return start == -1 ? "" : s1.substr(start, len);
}

int main()
{
    return 0;
}