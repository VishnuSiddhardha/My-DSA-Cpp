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

ListNode* deleteMiddle(ListNode* head) {
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow->next == NULL) {
        head->next = NULL;
        free(slow);
    }
    else {
        slow->val = slow->next->val;
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        free(temp);
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2};
    ListNode *head = convertArr2LL(arr);
    head = deleteMiddle(head);
    traversal(head);
    return 0;
}