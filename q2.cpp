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

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != nullptr)
        return findMin(target->right);
    Node* successor = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != nullptr)
        return findMax(target->left);
    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insert(root, v);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    Node* foundRec = searchRecursive(root, key);
    Node* foundItr = searchIterative(root, key);
    if (foundRec)
        cout << "Element found (Recursive & Iterative)\n";
    else
        cout << "Element not found\n";

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);
    cout << "Minimum element: " << minNode->data << endl;
    cout << "Maximum element: " << maxNode->data << endl;

    if (foundRec) {
        Node* succ = inorderSuccessor(root, foundRec);
        Node* pred = inorderPredecessor(root, foundRec);
        if (succ)
            cout << "Inorder Successor of " << key << ": " << succ->data << endl;
        else
            cout << "No Inorder Successor found\n";
        if (pred)
            cout << "Inorder Predecessor of " << key << ": " << pred->data << endl;
        else
            cout << "No Inorder Predecessor found\n";
    }

    return 0;
}
