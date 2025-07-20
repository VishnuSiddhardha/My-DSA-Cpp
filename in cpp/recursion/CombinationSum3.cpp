#include <bits/stdc++.h>
using namespace std;

void getAllCombinations(int ind, int sum, int k, vector<vector<int>> &res, vector<int> temp) {
    if (k == 0) {
        if (sum == 0)
            res.push_back(temp);
        return;
    }

    for (int i = ind; i <= 9; i++) {
        if (i > sum) break;
        temp.push_back(i);
        getAllCombinations(i+1, sum-i, k-1, res, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> nums;
    for (int i = 1; i <= 9; i++)
        nums.push_back(i);

    getAllCombinations(1, n, k, res, {});

    return res;
}

int main()
{
    vector<vector<int>> res = combinationSum3(3, 7);
    cout << "Elements are:\n";
    for (auto vct : res) {
        for (auto ele : vct)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}