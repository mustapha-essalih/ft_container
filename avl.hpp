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

  

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

template<typename K, typename V>

struct constNode
{

    std::pair<const K,V> data;
    const K key;
    V val; 
    int height; 
    constNode():key(K()){}
    constNode(const K k,V v):key(k),val(v),data(std::make_pair<const K,V>(k,v)) {}
  
};


template<typename K,typename V>

struct NodeData 
{
    K first;
    V second;
    NodeData(const K &f, const V &s) : first(f), second(s) {}
    NodeData(const NodeData<K,V> &other) : first(other.first), second(other.second) {}
    NodeData& operator=(const NodeData<K,V> &other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }
};

 
template<typename K,typename V>

struct Node {
    
    NodeData<K,V> data;  
    Node *left;
    Node *right;
    Node *parent;
    int height;                 
    Node(const std::pair<const K, V> &data) : data(data.first, data.second), left(NULL), right(NULL),parent(NULL), height(1) {}
};

template<typename key_type,typename T,typename key_compare,typename size_type,typename mapped_type,typename Allocator >

class avl
{
    public:
        
        typedef Allocator allocator_type;
        typedef T value_type;
        typedef std::pair< key_type, mapped_type>    value_type_;
        key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        
        typedef typename allocator_type::template rebind<Node<key_type,mapped_type> >::other node_allocator;
        
        
        typedef Node<key_type,mapped_type> Node;

        node_allocator alloc;

        Node * root;
        Node * tmp;
        Node * end_node;
        Node * parentOfNode;
 
        avl()
        {
            Node tmp((value_type()));
            end_node  = alloc.allocate(1);      // free?
            parentOfNode  = alloc.allocate(1);      // free?
            alloc.construct(end_node,tmp); 
            alloc.construct(parentOfNode,tmp); 
        }   

        int height(Node* node) 
        {
            if (!node) 
                return 0;
            return node->height;
        }

        int balancing(Node* node) 
        {
            if (!node) 
                return 0;
            return height(node->left) - height(node->right);
        }

    Node* leftRotate(Node* node) 
    {
        Node* right = node->right;
        node->right = right->left;
        right->left = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        right->height = std::max(height(right->left), height(right->right)) + 1;
        return right;
    }

    Node* rightRotate(Node* node) 
    {
        Node* left = node->left;
        node->left = left->right;
        left->right = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        left->height = std::max(height(left->left), height(left->right)) + 1;
        return left;
    }

    Node* insert(Node* node, const value_type &key)
    {
        if (!node) 
        {
            Node tmp(key);
            node  = alloc.allocate(1);      // free?
            alloc.construct(node,tmp); 
            return node;
        }

        if (key.first < node->data.first) // use keycompar
        {
            node->left = insert(node->left, key);
            node->left->parent = node;
        } 
        else if (key.first > node->data.first) 
        {
            node->right = insert(node->right, key);
            node->right->parent = node;
        } 
        else 
            return node;

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = balancing(node);

        if (balance > 1 && key.first < node->left->data.first) 
            return rightRotate(node);
 
        if (balance < -1 && key.first > node->right->data.first) 
            return leftRotate(node);

        if (balance > 1 && key.first > node->left->data.first) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key.first < node->right->data.first) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* findMin(Node* node) 
    {
        if (node == NULL) 
            return NULL;
        while (node->left != NULL) 
            node = node->left;
        return node;
    }
    Node* maxNode(Node* node) 
    {
        if (node == NULL) 
            return NULL;
        while (node->right != NULL) 
            node = node->right;
        return node;
    }

    Node* deleteNode(Node* node, const value_type &key) 
    {
        if (node == NULL) 
            return NULL;
        
        if (key.first < node->data.first) 
            node->left = deleteNode(node->left, key);
        else if (key.first > node->data.first) 
            node->right = deleteNode(node->right, key);
        else 
        {
            if ((node->left == NULL) || (node->right == NULL)) 
            {
                Node* temp = node->left ? node->left : node->right;

                if (temp == NULL) 
                {
                    temp = node;
                    node = NULL;
                } 
                else 
                    *node = *temp;
                alloc.destroy(temp);
                alloc.deallocate(temp,1);
            } 
            else 
            {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == NULL) 
            return node;

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int balance = balancing(node);

        if (balance > 1 && balancing(node->left) >= 0) 
            return rightRotate(node);

        if (balance > 1 && balancing(node->left) < 0) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && balancing(node->right) <= 0) 
            return leftRotate(node);

        if (balance < -1 && balancing(node->right) > 0) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
            
        
    void insert(const value_type &data)
    {
        root = insert(root, data);

        parentOfNode->left = root;
        root->parent = parentOfNode;
        end_node->parent = maxNode(root);
        
        // cout << root->parent->data.first << endl;
    } 
         
    void deleteNode(const value_type &key) 
    {
        root = deleteNode(root, key);
    }
  
    ~avl(){}
    private:
            
};
 



#endif