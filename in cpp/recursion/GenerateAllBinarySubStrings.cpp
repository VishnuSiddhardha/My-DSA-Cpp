#include<bits/stdc++.h>
using namespace std;
// 
void getAllPossibleCombinations(string s, int len, vector<string> &res)
{
    if (s.length() > 1 && (s[s.length()-1] == s[s.length()-2] && s[s.length()-1] == '1'))
        return;
    if (s.length() == len) {
        cout << s << endl;
        res.push_back(s);
        return;
    }
    getAllPossibleCombinations(s+"0", len, res);
    getAllPossibleCombinations(s+"1", len, res);

}

vector<string> generateBinaryStrings(int num) {
    // Write your code
    vector<string> result;

    getAllPossibleCombinations("", num, result);
    // getAllPossibleCombinations("0", num, result);
    // getAllPossibleCombinations("1", num, result);
    return result;
}

int main()
{
    int num = 3;
    vector<string> arr = generateBinaryStrings(num);
    // print the combinations
    for (auto x : arr)
        cout << x << " ";
    
    return 0;
}