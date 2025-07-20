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

ListNode* rotateRight(ListNode* head, int k) {

    int length = 0;
    ListNode *temp = head;
    // find the length of the linked list
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (k%length == 0) return head;
    ListNode *newHead;
    length = length - (k%length);
    temp = head;
    while (temp->next != NULL)
    {
        length--;
        if (length == 0) newHead = temp;
        temp = temp->next;
    }
    temp->next = head;
    head = newHead->next;
    newHead->next = NULL;
    return head;
}

int main()
{
    vector<int> arr = {0,1,2};
    ListNode *head = convertArr2LL(arr);
    cout << "before\n";
    traversal(head);
    head = rotateRight(head,4);
    cout << "after\n";
    traversal(head);
    return 0;
}