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

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(ListNode* head) {
    // find out the middle node
    ListNode* middle = head, *fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        middle = middle->next;
        fast = fast->next->next;
    }
    // change the links
    ListNode *temp = middle->next, *prev = middle;
    while (temp != NULL) {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    // check palindrome or not
    bool check = true;
    temp = head;
    ListNode* back = prev;
    while (temp != middle) {
        if (temp->val != back->val) {
            check = false;
            break;
        }
        temp = temp->next;
        back = back->next;
    }
    // change the links back to the original position
    back = prev;
    ListNode *next = NULL;
    while (back != middle) {
        temp = back->next;
        back->next = next;
        next = back;
        back = temp;
    }
    return check;
}

int main()
{
    vector<int> arr = {1,2,3,3,2,1,2};
    ListNode *head = convertArr2LL(arr);
    bool value = isPalindrome(head);
    if (value) 
        cout << "yessssssssss";
    else 
        cout << "noooooooo";
    
    return 0;
}