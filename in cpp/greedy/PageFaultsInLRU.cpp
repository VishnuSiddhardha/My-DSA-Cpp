#include<bits/stdc++.h>
using namespace std;

struct  myDBNode
{
    int page;
    myDBNode *next, *prev;
    myDBNode(int page) {
        this->page = page;
        next = NULL;
        prev = NULL;
    }
};


class Solution {
  public:
    myDBNode *head, *tail;
    Solution()
    {
        head = new myDBNode(-1);
        tail = new myDBNode(-1);
        head->next = tail;
        tail->prev = head;
    }
    int pageFaults(int N, int C, int pages[]) {
        // code here
        unordered_map<int, myDBNode*> mp;
        int faults = 0;
        for (int i = 0; i < N; i++)
        {
            myDBNode *temp;
            if (mp.find(pages[i]) == mp.end())
            {
                faults++;
                temp = new myDBNode(pages[i]);
                if (mp.size() == C) {
                    mp.erase(tail->prev->page);
                    tail->prev->prev->next = tail;
                    tail->prev = tail->prev->prev;
                }
                mp[pages[i]] = temp;
                setNodeFirst(temp);
            }
            else 
            {
                temp = mp[pages[i]];
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                setNodeFirst(temp);
            }
        }
        return faults;      
    }
    void setNodeFirst(myDBNode *node)
    {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
};

int main()
{
    int arr[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    Solution *obj = new Solution();
    int faults = obj->pageFaults(9, 4, arr);

    cout << faults << endl;
    return 0;
}