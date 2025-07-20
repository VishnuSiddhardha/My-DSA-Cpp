#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traversal(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *convertArr2LL(vector<int> arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* front;

    while (cur != NULL) {
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    
    ListNode *temp = head;
    int count;
    ListNode *next, *prev = NULL;
    while (temp != NULL)
    {
        count = k - 1;
        ListNode *nextKthNode = temp;
        while (nextKthNode != NULL) {
            if (count == 0) break;
            count--;
            nextKthNode = nextKthNode->next;
        }
        if (nextKthNode == NULL) {
            if (prev) prev->next = temp;
            break;
        }
        next = nextKthNode->next;
        nextKthNode->next = NULL;
        ListNode *newHead = reverseList(temp);
        if (head == temp) {
            head = newHead;
        }
        else {
            prev->next = newHead;
        }
        prev = temp;
        temp = next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1};
    ListNode *head = convertArr2LL(arr);
    cout << "Before\n";
    traversal(head);

    head = reverseKGroup(head,3);

    cout << "After\n";
    traversal(head);
    return 0;
}