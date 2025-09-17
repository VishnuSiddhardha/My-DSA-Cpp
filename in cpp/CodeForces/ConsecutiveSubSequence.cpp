// #include <bits/stdc++.h>
// using namespace std;

// // O(n^2)
// void longestSubSeq(int &n, vector<int> &arr)
// {
//     vector<int> dp(n, 1), hash(n);
//     int maxIndex = 0;
//     for (int i = 0; i < n; i++)
//     {
//         hash[i] = i;
//         for (int j = i-1; j >= 0; j--)
//         {
//             if (arr[i] == arr[j]+1){
//                 dp[i] = 1 + dp[j];
//                 hash[i] = j;
//                 break;
//             }
//         }
//         if (dp[maxIndex] < dp[i]) maxIndex = i;
//         // cout << "for dp[" << i << "] value is: " << dp[i] << endl;
//         // cout << "for hash[" << i << "] value is: " << hash[i] << endl;
//     }
//     vector<int> order;
//     order.push_back(maxIndex+1);

//     while (maxIndex != hash[maxIndex])
//     {
//         maxIndex = hash[maxIndex];
//         order.push_back(maxIndex+1);
//     }
//     for (int i = order.size()-1; i >= 0; i--) {
//         cout << order[i] << " ";
//     }
// }

// void longestConSubSeq(int &n, vector<int> &arr)
// {
//     unordered_map<int, int> dp, hash, arrIdx;
//     for (int i = 0; i < n; i++) arrIdx[arr[i]] = i; // store the indexs of elements

//     int idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (dp.find(arr[i]-1) != dp.end()){ // if there is a previous element
//             dp[arr[i]] = 1 + dp[arr[i]-1];
//             if (dp[arr[idx]] < dp[arr[i]]) idx = i;
//             hash[i] = arrIdx[arr[i]-1];
//             // cout << "hash[arr["<<i<<"]] -> " << hash[i] << endl;
//         }
//         else {
//             dp[arr[i]] = 1;
//             hash[i] = i;
//         }
//     }
//     cout << dp[arr[idx]] << endl;
//     // for (auto &ele : hash){
//     //     cout << "ele: " << ele.first << " & idx: " << ele.second << endl;
//     // }
//     vector<int> order;
//     order.push_back(idx+1);

//     while (idx != hash[idx])
//     {
//         idx = hash[idx];
//         order.push_back(idx+1);
//     }
//     for (int i = order.size()-1; i >= 0; i--) {
//         cout << order[i] << " ";
//     }
// }

// int main() {
//     // int n;
//     // cin >> n;
//     // vector<int> arr(n);
//     // for (int i = 0; i < n; i++){
//     //     cin >> arr[i];
//     // }

//     vector<int> arr = {6, 7, 8, 3, 4, 5, 9, 10, 11};
//     int n = arr.size();
//     // longestSubSeq(n, arr);
//     longestConSubSeq(n, arr);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void longestConsecutiveSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1);              // dp[i] = length of longest subsequence ending at i
    vector<int> prev(n, -1);           // prev[i] = previous index in the subsequence
    unordered_map<int, int> lastIndex; // maps value to its last occurring index in arr

    int maxLen = 1;
    int lastIdx = 0;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        if (lastIndex.find(val - 1) != lastIndex.end())
        {
            int j = lastIndex[val - 1];
            dp[i] = dp[j] + 1;
            prev[i] = j;
            if (dp[i] > dp[lastIdx]) lastIdx = i;
        }
        lastIndex[val] = i;
    }
    cout << dp[lastIdx] << "\n";

    vector<int> indices;
    while (lastIdx != -1)
    {
        indices.push_back(lastIdx + 1); // convert to 1-based index
        lastIdx = prev[lastIdx];
    }

    for (int i = indices.size()-1; i >= 0; i--)
        cout << indices[i] << " ";
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    vector<int> arr = {6, 7, 8, 3, 4, 5, 9, 10, 11};
    int n = arr.size();
    longestConsecutiveSubsequence(n, arr);
    return 0;
}
