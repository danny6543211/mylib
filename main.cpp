#include <iostream>

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

    BSTNode(const T& value)
        : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    BSTNode<T>* root;

    void insertNode(BSTNode<T>*& node, const T& value) {
        if (node == nullptr) {
            node = new BSTNode<T>(value);
        } else if (value < node->data) {
            insertNode(node->left, value);
        } else {
            insertNode(node->right, value);
        }
    }

    bool searchNode(BSTNode<T>* node, const T& value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    void inorderTraversal(BSTNode<T>* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& value) {
        insertNode(root, value);
    }

    bool search(const T& value) const {
        return searchNode(root, value);
    }

    void inorder() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inorder();  // 输出：20 30 40 50 60 70 80

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;  // 输出：Search 40: Found
    std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;  // 输出：Search 90: Not Found

    
    return 0;
}
