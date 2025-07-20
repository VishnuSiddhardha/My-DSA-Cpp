#include<bits/stdc++.h>
using namespace std;

vector<int> replaceWithRank(vector<int> &arr, int N) {
    vector<int> result;
    for (int ele : arr) 
        result.push_back(ele);
    sort(result.begin(), result.end());
    unordered_map<int, int> mp;
    int incrmtr = 1;
    for (int i = 0; i < N; i++) {
        if (mp.count(result[i])) continue;
        mp[result[i]] = incrmtr;
        incrmtr++;
    }
    vector<int> result;
    for (int i = 0; i < N; i++) {
        result[i] = mp[arr[i]];
    }
    return result;
}

int main()
{
    // 1 6 3 2 4 5 4
    vector<int> arr = {2, 20, 10, 3, 14, 16, 14};
    vector<int> indices = replaceWithRank(arr, arr.size());
    for (int x : indices)
        cout << x << " ";
    return 0;
}