#include <iostream>
#include <vector>

using std::cout; using std::vector;
using std::endl; using std::string;

struct TreeNode {
    int key;
    struct TreeNode *left{};
    struct TreeNode *right{};
};

void insertNode(TreeNode *&root, const int k) {
    if (root == nullptr) {
        root = new TreeNode;
        root->key = k;
        root->left = nullptr;
        root->right = nullptr;
    } else {
        if (k < root->key)
            insertNode(root->left, k);
        else
            insertNode(root->right, k);
    }
}

TreeNode *findNode(TreeNode *root, const int k) {
    if (root == nullptr)
        return nullptr;

    if (k == root->key)
        return root;

    if (k < root->key)
        return findNode(root->left, k);
    else
        return findNode(root->right, k);
}

void printTree(TreeNode *n) {
    if (n != nullptr) {
        printTree(n->left);
        cout << n->key << "; ";
        printTree(n->right);
    }
}

int main() {
    std::vector<int> v1 {11, 23, 3, 5, 9, 15, 2, 20};

    TreeNode *root = nullptr;

    for (const auto &item : v1) {
        insertNode(root, item);
    }
    printTree(root);
    cout << endl;

    std::vector<int> v2 {1, 22, 4, 16};
    for (const auto &item : v2) {
        insertNode(root, item);
    }
    printTree(root);
    cout << endl;

    return EXIT_SUCCESS;
}