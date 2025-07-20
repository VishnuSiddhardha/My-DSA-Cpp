#include<bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int> &arr, int k) {
    // code here
    long count = 0;
    unordered_map<int, int> mp;
    int xr = 0;
    mp[xr] = 1;
    for (int i = 0; i < arr.size(); i++) {
        xr ^= arr[i];
        if (mp.count(xr ^ k)) {
            count += mp[xr^k];
        }
        cout << " i value: " << i << " and count : " << count << endl;
        mp[xr]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    long count = subarrayXor(arr, 6);
    cout << "count: " << count << endl;
    return 0;
} 