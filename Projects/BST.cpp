#include <iostream>

namespace std {}

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool exists(int value) {
        return existsRecursive(root, value);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

private:
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    bool existsRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return existsRecursive(node->left, value);
        } else {
            return existsRecursive(node->right, value);
        }
    }

    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }
};

int main() {
    using namespace std;

    BinarySearchTree bst;
    char continueInserting = 'y';

    cout << "Binary Search Tree Program\n";

    while (continueInserting == 'y' || continueInserting == 'Y') {
        int value;
        cout << "Enter an integer value to insert into the BST: ";
        cin >> value;

        bst.insert(value);

        cout << "Do you want to insert more elements? (y/n): ";
        cin >> continueInserting;
    }

    int searchValue;
    cout << "\nEnter an integer value to search in the BST: ";
    cin >> searchValue;

    if (bst.exists(searchValue)) {
        cout <<  searchValue << " exists in the BST.\n";
    } else {
        cout <<  searchValue << " does not exist in the BST.\n";
    }

    cout << "\nOrder of the BST: ";
    bst.inorderTraversal();
    cout << endl;

    return 0;
}
