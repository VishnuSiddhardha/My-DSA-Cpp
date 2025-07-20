#include <bits/stdc++.h>
using namespace std;

struct doublyLL
{
    int key, val, count;
    doublyLL *next, *prev;
    doublyLL(int key, int val)
    {
        this->key = key;
        this->val = val;
        count = 1;
        next = prev = NULL;
    }
};

struct myList
{
    doublyLL *head, *tail;
    int size;
    myList()
    {
        head = new doublyLL(-1, -1);
        tail = new doublyLL(-1, -1);

        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addNodeFront(doublyLL *node)
    {
        size++;
        // assign head next node links to current
        node->next = head->next;
        head->next->prev = node;
        // assign head next to current
        head->next = node;
        node->prev = head;
    }
    void removeNode(doublyLL *node)
    {
        size--;
        doublyLL *temp = node;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        // delete temp;
    }
};

class LFUCache
{
    unordered_map<int, myList *> freqListMap;
    unordered_map<int, doublyLL *> keyNodeMap;
    int cur_cap;
    int minFreq, maxCacheSize;

public:
    LFUCache(int capacity)
    {
        maxCacheSize = capacity;
        cur_cap = 0;
        minFreq = 0;
    }
    void updateFreqListMap(doublyLL *node)
    {
        freqListMap[node->count]->removeNode(node);
        // remove node form the list;
        if (minFreq == node->count && freqListMap[node->count]->size == 0)
        {
            minFreq++;
            freqListMap.erase(node->count);
        }
        node->count += 1; // increment the count
        if (freqListMap.count(node->count) == 0)
            freqListMap[node->count] = new myList();
        freqListMap[node->count]->addNodeFront(node); // add the node to the new freq list
    }
    int get(int key)
    {
        if (keyNodeMap.count(key) == 0)
            return -1;
        doublyLL *node = keyNodeMap[key];
        updateFreqListMap(node);
        return node->val;
    }
    void put(int key, int value)
    {
        doublyLL *node;

        if (keyNodeMap.count(key))
        {
            node = keyNodeMap[key];
            node->val = value;
            updateFreqListMap(node);
        }
        else
        {
            if (cur_cap == maxCacheSize)
            {
                myList *curList = freqListMap[minFreq];
                keyNodeMap.erase(curList->tail->prev->key);
                curList->removeNode(curList->tail->prev);
                cur_cap--;
            }

            minFreq = 1;
            cur_cap++;
            doublyLL *node = new doublyLL(key, value);
            keyNodeMap[key] = node;
            // check for the presence of list with freq -> minfreq
            if (freqListMap.count(minFreq) == 0)
            {
                freqListMap[minFreq] = new myList();
            }
            // add to the particular linked list (of count minFreq)
            freqListMap[minFreq]->addNodeFront(node);
        }
    }
};

int main()
{
    LFUCache *obj = new LFUCache(2);
    obj->put(1, 10);
    obj->put(2, 20);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    return 0;
}