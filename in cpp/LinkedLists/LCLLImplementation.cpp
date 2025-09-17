#include <bits/stdc++.h>
using namespace std;

struct MyListNode
{
    int val;
    MyListNode *next;
    MyListNode() : val(0), next(nullptr) {}
    MyListNode(int x) : val(x), next(nullptr) {}
    MyListNode(int x, MyListNode *next) : val(x), next(next) {}
};

struct MyListNode {
    int val;
    MyListNode *next;
    MyListNode(int x) : val(x), next(nullptr) {}
};

class MyLinkedList {
    MyListNode *head, *tail;
    int len;

public:
    MyLinkedList() : head(NULL), tail(NULL), len(0) {}

    int get(int index) {
        if (index < 0 || index >= len) return -1;
        MyListNode *temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        MyListNode* newNode = new MyListNode(val);
        newNode->next = head;
        head = newNode;
        if (len == 0) tail = newNode; // first node
        len++;
    }

    void addAtTail(int val) {
        MyListNode* newNode = new MyListNode(val);
        if (len == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        len++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) return;
        if (index == 0) return addAtHead(val);
        if (index == len) return addAtTail(val);

        MyListNode* prev = head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;
        MyListNode* newNode = new MyListNode(val);
        newNode->next = prev->next;
        prev->next = newNode;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;

        MyListNode* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
            if (len == 1) tail = NULL; // list became empty
        } else {
            MyListNode* prev = head;
            for (int i = 0; i < index - 1; i++) prev = prev->next;
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (toDelete == tail) tail = prev;
        }
        delete toDelete;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    
    return 0;
}