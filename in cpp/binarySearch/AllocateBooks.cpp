#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int students, int pages) {
    int curPages = arr[0];
    students--;
    int n = arr.size();
    cout << "isPossbile for pages: " << pages << endl;
    for (int i = 1; i < arr.size(); i++) {
        cout << "curPages: " << curPages << " and arr[i] + curPages: " << arr[i] + curPages << endl;
        if (arr[i] + curPages > pages || (n-i) <= students) {
            curPages = 0;
            students--;
        }
        curPages += arr[i];
    }
    cout << "final students <= 0 : " << students << endl;
    return students == 0;

}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (n < m) return -1;
    int low = arr[0];
    int high = 0;
    for (auto x : arr) {
        low = max(low, x);
        high += x;
    }
    cout << "low: " << low << " high: " << high << endl;

    while (low <= high) {
        int mid = (low+high)/2;
        if (isPossible(arr, m, mid)) {
            cout << "possbile one: " << mid << endl;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int minPages = findPages(arr,5,4);

    cout << "final: min Possible pages are: " << minPages;
    return 0;
}