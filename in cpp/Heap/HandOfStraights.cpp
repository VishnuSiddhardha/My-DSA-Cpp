#include <bits/stdc++.h>
using namespace std;


// if (hand.size() % groupSize != 0) return false;
// // store the frequencies
// unordered_map<int, int> mp;
// for (int x : hand)
//     mp[x]++;
// // build min_heap
// priority_queue<int, vector<int>, greater<int>> pq;
// for (auto x : mp)
//     pq.push(x.first);

// int size = 0;
// int prev = -1;
// vector<int> tempArr;
// while (!pq.empty()) {
//     int cur = pq.top();
//     pq.pop();
//     cout << "cur is : " << cur << endl;
//     if (prev != -1 && prev+1 != cur) {
//         cout << "breaking\n";
//         break;
//     };
//     prev = cur;
//     size++;
//     mp[cur]--;
//     if(mp[cur] == 0) mp.erase(cur);
//     else tempArr.push_back(cur);
    
//     if(size == groupSize) {
//         size = 0;
//         prev = -1;
//         while(tempArr.size() != 0) {
//             pq.push(tempArr.back());
//             tempArr.pop_back();
//         }
//     }
// }
// if (tempArr.size() == 0)
//     return true;
// return false;
bool isNStraightHand(vector<int> &hand, int groupSize)
{
    map<int, int> mp;
    for (int x : hand)
        mp[x]++;
    
    while (!mp.empty()) {
        int cur = mp.begin()->first;
        for (int i = 0; i < groupSize; i++) {
            if (mp.count(cur+i) == 0) return false;
            mp[cur+i]--;
            if (mp[cur+i] == 0) mp.erase(cur+i);
        }
    }
    return true;
}



int main()
{
    vector<int> hand = {1,1,2,2,3,3};
    if (isNStraightHand(hand, 2)) {
        cout << "Yes possible\n";
    }
    else {
        cout << "No not possible\n";
    }
    return 0;
}