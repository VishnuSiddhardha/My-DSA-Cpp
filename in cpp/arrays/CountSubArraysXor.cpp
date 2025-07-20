#include<bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int,int> mp;
    int result = 0,sum = 0;
    mp[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
        sum = sum ^ a[i];
        if (mp.count(sum^b)){
            cout << "adding: " << mp[sum^b] << endl;
            result += mp[sum^b];
        }
        mp[sum]++;
    }
    return result;
}

int main()
{
    vector<int> a = {7 ,7 ,6 ,8 ,5 ,5 ,13, 16, 17 ,0 ,1,18, 4, 19, 13 ,13 ,3 ,0 ,2 ,1, 0 };
    int count = subarraysWithSumK(a,0);
    cout << "count:" << count;
    return 0;
}