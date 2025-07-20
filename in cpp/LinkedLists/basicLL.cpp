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

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    Node *head = convertArr2LL(arr);
    traversal(head);
    return 0;
}