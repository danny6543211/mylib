#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
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

#endif