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

int helperFunc(Node* head) {
    if (head == NULL) return 1;

    int carry = helperFunc(head->next);

    if (carry + head->data > 9) {
        head->data = 0;
        return 1;
    }
    head->data = carry + head->data;
    return 0;
}

Node* addOne(Node* head) {
    // Your Code here
    // return head of list after adding one
    int carry = helperFunc(head);
    if (carry == 1) {
        Node *temp = new Node(1);
        temp->next = head;
        return temp;
    }
    else {
        return head;
    }


}



int main()
{
    vector<int> arr = {9,9,9};
    Node *head = convertArr2LL(arr);

    head = addOne(head);
    traversal(head);
    return 0;
}