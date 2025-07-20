#include <bits/stdc++.h>
using namespace std;

struct doublyLL
{
    int key, val;
    doublyLL *next, *prev;
    doublyLL(int key, int val)
    {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

class LRUCache
{
    unordered_map<int, doublyLL *> mp;
    int size;
    doublyLL *head, *tail;
public:
    LRUCache(int capacity)
    {
        size = capacity;
        // dummy nodes
        head = new doublyLL(-1, -1);
        tail = new doublyLL(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void placeNodeFirst(int key)
    {
        doublyLL *node = mp[key];
        // asign current node front, back links
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // assign head next node links to current
        node->next = head->next;
        head->next->prev = node;
        // assign head next to current
        head->next = node;
        node->prev = head;
    }
    int get(int key)
    {
        if (mp.count(key) == 0)
            return -1;
        placeNodeFirst(key);
        return mp[key]->val;
    }

    void put(int key, int value)
    {
        doublyLL *node;
        // if the element already present 
        if (mp.count(key))
        {
            node = mp[key];
            node->val = value;
            placeNodeFirst(key);
        }
        else
        {
            // if the capacity is full, delete the last node
            if (mp.size() == size) {
                doublyLL *temp = tail->prev;
                mp.erase(temp->key);
                temp->prev->next = tail;
                tail->prev = temp->prev;
                delete temp;
            }
            node = new doublyLL(key, value);
            mp.insert({key,node});

            node->next = head->next;
            head->next->prev = node;

            head->next = node;
            node->prev = head;
        }
    }
};

int main()
{
    return 0;
}