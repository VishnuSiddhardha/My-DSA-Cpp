#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
{
    // code here
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({A[0]+B[0], {0,0}});
    set<pair<int, int>> uniqueCombi;
    uniqueCombi.insert({0,0});

    vector<int> topK;
    for (int count = 0; count < K; count++) {
        pair<int, pair<int, int>> top = pq.top();
        topK.push_back(top.first);

        int i = top.second.first, j = top.second.second;
        pq.pop();

        if (i+1 < N && (uniqueCombi.find({i+1, j}) == uniqueCombi.end())) {
            pq.push({A[i+1]+B[j], {i+1,j}});
            uniqueCombi.insert({i+1, j});
        }
        if (j+1 < N && (uniqueCombi.find({i, j+1}) == uniqueCombi.end())) {
            pq.push({A[i]+B[j+1], {i,j+1}});
            uniqueCombi.insert({i, j+1});
        }
    }
    return topK;
}

int main()
{
    return 0;
}