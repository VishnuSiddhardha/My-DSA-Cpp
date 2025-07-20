#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int left = 0, right = 0, maxlen = 0;
    int n = fruits.size();
    while (right < n)
    {
        mp[fruits[right]]++;
        if (mp.size() > 2) {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
            left++;
        }
        if (mp.size() <=2 ) {
            auto it = mp.begin();
            int curSum = it->second;
            ++it;
            if (it != mp.end())
                curSum += it->second;
            maxlen = max(maxlen, curSum);
        }
        right++;
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    int len = totalFruit(arr);
    cout << len << endl;
    return 0;
}