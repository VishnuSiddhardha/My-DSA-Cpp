#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> st(candyType.begin(), candyType.end());
        // for (int x : candyType)
        // st.insert(x);

        int avaliable = candyType.size() >> 1;
        int unique = st.size();
        return min(avaliable, unique);
    }
};

int main()
{

    return 0;
}