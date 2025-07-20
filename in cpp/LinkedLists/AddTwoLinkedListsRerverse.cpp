#include <bits/stdc++.h>
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *left = l1, *right = l2;
    ListNode *result = new ListNode(-1);
    ListNode *dummy = result;
    int carry = 0;
    while (left || right || carry)
    {
        int sum = carry;
        if (left != NULL)
        {
            sum += left->val;
            left = left->next;
        }
        if (right != NULL)
        {
            sum += right->val;
            right = right->next;
        }
        carry = sum / 10;
        ListNode *newNode = new ListNode(sum % 10);
        dummy->next = newNode;
        dummy = dummy->next;
    }
    return result->next;
}

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

int main()
{
    vector<int> one = {0};
    vector<int> two = {0};

    ListNode *one1 = convertArr2LL(one);
    ListNode *two1 = convertArr2LL(two);

    cout << "1st number:\n";
    traversal(one1);
    cout << "2nd number:\n";
    traversal(two1);

    ListNode *result = addTwoNumbers(one1, two1);
    cout << "Result:\n";
    traversal(result);
    return 0;
}