#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findCenter(vector<int> arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        return arr[((n-1)>>1)]; // -> (n-1) / 2  
    }
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        
        int center = findCenter(arr);
        
    }
};

int main() {
    
    return 0;
}