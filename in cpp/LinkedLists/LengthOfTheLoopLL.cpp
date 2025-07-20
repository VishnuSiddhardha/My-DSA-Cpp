#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    public:
    Node (int data, Node* next) {
        this->data = data;
        this->next = next;
    }
    public:
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

void traversal(Node *head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* convertArr2LL(vector<int> arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node *getIntersectionPoint(Node* head) {
    Node* slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return slow;
    }
    return NULL;
}

int countNodesinLoop(Node *head) {
    // Code here
    Node *point = getIntersectionPoint(head);
    if (point == NULL) return 0;
    int count = 1;
    Node *temp = point->next;
    while (point != temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    return 0;
}