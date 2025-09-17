#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate
{
    vector<int> resArr, times;
    public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        unordered_map<int, int> mp;
        int curMax = 0, maxEle = 0;
        this->times = times;
        for (int x : persons)
        {
            mp[x]++;
            if (mp[x] >= curMax)
            {
                maxEle = x;
                curMax = mp[x];
            }
            resArr.push_back(maxEle);
        }
        for (int x : resArr)
            cout << x << " ";
        cout << endl;
    }

    int q(int t)
    {
        int idx = lower_bound(times.begin(), times.end(), t) - times.begin();
        if (idx == times.size() || times[idx] > t) idx--;
        cout << "idx: " << idx << endl;
        return resArr[idx];
    }
};

int main()
{
    vector<int> persons = {0,1,1,0,0,1,0}, times = {0,5,10,15,20,25,30};
    TopVotedCandidate obj(persons, times);
    obj.q(40);
    return 0;
}