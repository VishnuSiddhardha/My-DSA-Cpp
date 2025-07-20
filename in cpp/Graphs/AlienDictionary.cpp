#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        // code here
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        // build the graph
        for (string s : words) {
            for (char x : s) {
                graph[x];
                indegree[x];
            }
        }
        for (int i = 0; i < words.size()-1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";  // invalid order
            int size = min(word1.size(), word2.size());
            for (int j = 0; j < size; j++) 
            {
                if (word1[j] != word2[j]) {
                    char from = word1[j], to = word2[j];
                    if (!graph[from].count(to)) {
                        graph[from].insert(to);
                        indegree[to]++;
                    }
                    break;
                }
            } 
        }
        queue<char> q;
        // push the nodes having the indegree 0
        for (auto x : graph) {
            if (indegree[x.first] == 0)
                q.push(x.first);
        }
        string ans;
        // start the algorithm
        while (!q.empty())
        {
            char node = q.front();
            q.pop();
            ans.push_back(node);
            for (char x : graph[node]) {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }
        if (ans.size() == graph.size())
            return ans;
        return "";
    }
};

int main()
{

    return 0;
}