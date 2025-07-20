#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    char value;
    bool flag;
    unordered_map<char, TrieNode*> mp;
    TrieNode(char value)
    {
        this->value = value;
        flag = false;
    }
};

class Trie {
    TrieNode *head;
    public:
        Trie() {
            head = new TrieNode(' ');
        }        
        void insert(string word) {
            TrieNode *temp = head;
            for (char ch : word) {
                if (temp->mp.count(ch) == 0)
                    temp->mp[ch] = new TrieNode(ch);

                temp = temp->mp[ch];
            }
            temp->flag = true;
        }
        
        bool search(string word) {
            TrieNode *temp = head;
            for (char ch : word) {
                if (temp->mp.count(ch) == 0)
                    return false;
                temp = temp->mp[ch];
            }
            return temp->flag;
        }
        
        bool startsWith(string prefix) {
            TrieNode *temp = head;
            for (char ch : prefix) {
                if (temp->mp.count(ch) == 0)
                    return false;
                temp = temp->mp[ch];
            }
            return true;
        }
    };

int main()
{
    return 0;
}