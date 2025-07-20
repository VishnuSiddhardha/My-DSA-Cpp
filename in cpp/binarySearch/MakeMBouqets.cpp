#include<bits/stdc++.h>
using namespace std;

bool isPossbile(vector<int> arr, int m, int k, int days) {
    int count = 0, res = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= days) count++;
        else count = 0;
        if (count == k) {
            count = 0;
            res++;
        }
    }
    return res >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {

    if (bloomDay.size() < m * k) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    while (low <= high) {
        int mid = (low+high)/2;

        if (isPossbile(bloomDay,m,k,mid)) {
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {3, 4, 2, 7, 13, 8, 5};
    int days = minDays(arr,3,2);
    cout << "days: " << days;
    return 0;
}