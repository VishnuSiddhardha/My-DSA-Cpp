#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int checkChildrenSum(Node *root)
{
    if (!root->left && !root->right)
        return root->data;

    int left = 0, right = 0;
    if (root->left) {
        left = checkChildrenSum(root->left);
    }
    if (root->right) {
        right = checkChildrenSum(root->right);
    }
    if (left == -1 || right == -1) return -1;
    return (left + right == root->data) ? root->data : -1;

}

int isSumProperty(Node *root)
{
    // Add your code here
    return (checkChildrenSum(root) != -1) ? 1 : 0;
}

int main()
{
    return 0;
}