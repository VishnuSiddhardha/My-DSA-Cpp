#include<bits/stdc++.h>
using namespace std;

void getAllCombinations(string s, int ind, vector<string>& res)
{
    if (ind >= s.size()) {
        res.push_back(s);
        return;
    }
    // for all 1's
    getAllCombinations(s, ind+1, res);
    // now for 0's
    s[ind] = '0';
    getAllCombinations(s, ind+2, res);
    s[ind] = '1';
}

vector<string> validStrings(int n) {
    vector<string> result;
    string s(n,'1');
    getAllCombinations(s, 0, result);
    return result;
}

int main()
{
    int n = 3;
    vector<string> res = validStrings(n);
    cout << "Printing all\n";
    for (auto x : res)
        cout << x << " ";
    return 0;
}