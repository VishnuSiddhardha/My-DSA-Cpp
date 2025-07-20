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

ListNode *merge(ListNode *one, ListNode *two)
{
    ListNode *result = new ListNode(-1);
    ListNode *temp = result;
    while (one && two) 
    {
        if (one->val < two->val) {
            temp->next = one;
            one = one->next;
        }
        else {
            temp->next = two;
            two = two->next;
        }
        temp = temp->next;
    }
    if (one) { 
        temp->next = one;
    }
    if (two) {
        temp->next = two;
    }
    return result->next;
}

ListNode* middleNode(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *middle = middleNode(head);
    ListNode *list2 = middle->next;
    middle->next = NULL;
    head = sortList(head);
    list2 = sortList(list2);
    return merge(head,list2);
}

int main()
{
    vector<int> arr = {5,3,2,14,6,7,1};
    ListNode *head = convertArr2LL(arr);
    cout << "Before\n";
    traversal(head);

    head = sortList(head);

    cout << "After\n";
    traversal(head);
    return 0;
}