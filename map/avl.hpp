#ifndef AVL_HPP
#define AVL_HPP


#include <iomanip>
#include <cstddef>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm> 

#include "../utils/type_traits.hpp"
 

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

template <typename A,typename size,typename V>

struct Node {
    ft::pair<A, V> data;
    int height;
    Node* left;
    Node* right;

    Node(ft::pair<A, V> data) : data(data), height(1), left(nullptr), right(nullptr) {}
};
 

template<typename key_type,class T,typename key_compare,typename size_type,typename mapped_type,typename Allocator >

class avl
{
    public:
        
        typedef Allocator allocator_type;
        typedef T value_type;
        typedef ft::pair< key_type, mapped_type>    value_type_;
        key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        
        typedef typename allocator_type::template rebind<Node<key_type,size_type,mapped_type> >::other node_allocator;
        
        
        typedef Node<key_type,size_type,mapped_type> Node;
        node_allocator alloc;

        Node * root;
        Node * tmp;
        Node * end_node;
 
        avl()
        {
            // Node tmp((value_type_()));
            // end_node  = alloc.allocate(sizeof(Node));      // free?
            // alloc.construct(end_node,tmp);
        }   
         int getBalance(Node* node) {
			if (!node) return 0;
			return getHeight(node->left) - getHeight(node->right);
		}

		int getHeight(Node* node) {
			if (!node) return 0;
			return node->height;
		}

		Node* rightRotate(Node* node) {
			Node* leftChild = node->left;
			Node* leftRightChild = leftChild->right;

			leftChild->right = node;
			node->left = leftRightChild;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			leftChild->height = std::max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

			return leftChild;
		}
    Node* balance(Node* node) {
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

		Node* leftRotate(Node* node) {
			Node* rightChild = node->right;
			Node* rightLeftChild = rightChild->left;

			rightChild->left = node;
			node->right = rightLeftChild;

			node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
			rightChild->height = std::max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;
			return rightChild;
		}

    	Node* insert(Node* node, value_type &key) {
        if (!node) {
            Node* newNode = alloc.allocate(1);
            alloc.construct(newNode, key);
            return newNode;
        }

        if (key.first < node->data.first) {
            node->left = insert(node->left, key);
        } else if (key.first > node->data.first) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }

        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && key.first < node->left->data.first) {
            return rightRotate(node);
        }

        if (balance < -1 && key.first > node->right->data.first) {
            return leftRotate(node);
        }

        if (balance > 1 && key.first > node->left->data.first) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key.first < node->right->data.first) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* deleteNode(Node* node, key_type key) {
        
        if (!node) 
        {
            cout << "NULLL\n";
            return nullptr;
        }

        if (key < node->data.first) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data.first) {
            node->right = deleteNode(node->right, key);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                alloc.destroy(temp);
                alloc.deallocate(temp, 1);
            } else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data.first);
            }
        }

        if (!node) return node;
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        return balance(node);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left) {
            current = current->left;
        }
        return current;
    }
    void insert( value_type key)
    {
        root = insert(root, key);
    }

    void deleteNode(key_type key) 
    {
        root = deleteNode(root, key);
    }
        void printPreorder( Node* node)
{
    if (node == nullptr)
        return;
 
    /* first print data of node */
 
    /* then recur on left subtree */
    printPreorder(node->left);
 
    cout << node->data.first << " ";
    /* now recur on right subtree */
    printPreorder(node->right);
}
    ~avl()
    {

    }
        private:
            
};
 



#endif