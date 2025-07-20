#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int k) {
    // code here
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2) return kthElement(b,a,k);

    int lo = max(0,k-n2), hi = min(k, n1);
    while (lo <= hi) {
        int mid1 = (lo + hi) / 2;
        int mid2 = k - mid1;

        int l1 = mid1 == 0 ? INT_MIN : a[mid1-1];
        int r1 = mid1 == n1 ? INT_MAX : a[mid1];

        int l2 = mid2 == 0 ? INT_MIN : b[mid2-1];
        int r2 = mid2 == n2 ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1){
            return max(l1,l2);
        }
        else if (l1 > r2) hi = mid1 - 1;
        else lo = mid1 + 1;
    }
    return 0;

}

int main()
{
    vector<int> a = {1,3};
    vector<int> b = {2};
    int k = kthElement(a,b,3);
    cout << k; 
    return 0;
}