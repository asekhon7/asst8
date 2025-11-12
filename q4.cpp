#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if (root == nullptr)
        return true;

    if ((minNode != nullptr && root->data <= minNode->data) ||
        (maxNode != nullptr && root->data >= maxNode->data))
        return false;

    return isBSTUtil(root->left, minNode, root) &&
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node* root) {
    return isBSTUtil(root, nullptr, nullptr);
}

int main() {
    Node* root = createNode(8);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->left->right = createNode(6);
    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    if (isBST(root))
        cout << "The given tree is a Binary Search Tree (BST)." << endl;
    else
        cout << "The given tree is NOT a Binary Search Tree (BST)." << endl;

    return 0;
}
