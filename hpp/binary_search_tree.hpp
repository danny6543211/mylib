#ifndef binary_search_tree_HPP
#define binary_search_tree_HPP
#include <vector>

template <class T>
class tree_node
{
public:
    T element;
    tree_node *left;
    tree_node *right;

public:
    tree_node(T element)
    {
        this->element = element;
        this->left = nullptr;
        this->right = nullptr;
    }

    tree_node(T element, tree_node *left, tree_node *right)
    {
        this->element = element;
        this->left = left;
        this->right = right;
    }


};

namespace myDS
{
    // 此二叉树为二叉搜索树
    template <class T>
    class binary_search_tree
    {
    public:
        binary_search_tree()
        {
            __root = nullptr;
        }

        binary_search_tree(std::vector<T> array)
        {
            for (auto val : array)
            {
                insert(__root, val);
            }
        }

        ~binary_search_tree() 
        {

        }

        
        
        tree_node<T> *insert(tree_node<T> *node, T element)
        {
            if (node == nullptr)
                node = new tree_node<T>(element);
            if (element <= node->element)
                insert(node->left, element);
            else 
                insert(node->right, element);
            return node;
        }
        



    public:
        tree_node<T> *__root;
        
    };
}

#endif