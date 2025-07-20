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

Node* deleteNode(Node *root, int k)
{
    if (root == NULL) return NULL;
    if (k == 1 && root->next == NULL) {
        free(root);
        return NULL;
    }
    if (k == 1){
        Node* temp = root;
        root = root->next;
        free(temp);
        return root;
    }

    Node* temp = root;
    Node* prev = NULL;
    int count = 0;
    while (temp != NULL) {
        count++;
        if (count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return root;
}

Node* insertNode(Node* root,int data, int pos) {
    if (root==NULL) {
        return new Node(data);
    }

    if (pos == 1) {
        Node *newNode = new Node(data);
        newNode->next = root;
        return newNode;
    }

    Node *newNode = new Node(data);
    Node* temp = root;
    int count = 0;
    while (temp->next != NULL) {
        count++;
        if (count==pos-1) {
            newNode->next = temp->next;
            temp->next = newNode;
            return root;
        }
        temp = temp->next;
    }

    // for Last position insertion
    newNode->next = temp->next;
    temp->next = newNode;
    return root;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* root = convertArr2LL(arr);
    // For checking delete function
    // cout << "before\n";
    // traversal(root);

    // root = deleteNode(root, 5);

    // cout << "After\n";
    // traversal(root);

    // For checking insert function
    cout << "before\n";
    traversal(root);

    root = insertNode(root, 55, 5);

    cout << "After\n";
    traversal(root);
    return 0;
}
