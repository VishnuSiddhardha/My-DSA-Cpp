#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> s, int ele) {
    if (s.empty() || s.top() < ele) {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, ele);
    s.push(temp);
}
void SortedStack(stack<int> s) {
    if (s.empty()) return;
    int ele = s.top();
    s.pop();
    SortedStack(s);
    sortedInsert(s, ele);
}

int main()
{
    return 0;
}