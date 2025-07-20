#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(int ind, string word, string digits, unordered_map<char, string> &mp,  vector<string> &res) {
    if (ind == digits.size()) {
        res.push_back(word);
        return;
    }

    for (int i = 0; i < mp[digits[ind]].length(); i++) {
        word.push_back(mp[digits[ind]][i]);
        getAllCombinations(ind+1, word, digits, mp, res);
        word.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
    vector<string> nums;
    for (char ch : digits)
        nums.push_back(mp[ch]);
    vector<string> res;

    getAllCombinations(0, "", digits,  mp, res);
    return res;
}

int main()
{
    vector<string> words = letterCombinations("234");
    for (auto str : words)
        cout << str << "  ";
    return 0;
}