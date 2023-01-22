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
    constNode(){}
    constNode(const K k,V v):key(k),val(v),   data(std::make_pair<const K,V>(k,v)) {}
         
    
    constNode(std::pair<const K,V> d):key(d.first),val(d.second){}
    
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


// Node* getNode() const {
// return n;
// }
template<typename K,typename V>

struct Node {

    NodeData<K,V> data;  
    Node *left;
    Node *right;
    Node *parent;
    int height;                 
    Node(const std::pair<const K, V> &data,Node<K,V> * p) : data(data.first, data.second), left(NULL), right(NULL), parent(p), height(1) {}
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
 
        avl()
        {
            
        }   

        int height(Node *n) 
        {
            return n ? n->height : 0;
        }

        int balance(Node *n) 
        {
            return height(n->left) - height(n->right);
        }

        Node* rotateLeft(Node *n) 
        {
            Node *temp = n->right;
            n->right = temp->left;
            temp->left = n;
            n->height = std::max(height(n->left), height(n->right)) + 1;
            temp->height = std::max(height(temp->left), height(temp->right)) + 1;
            return temp;
        }

        Node* rotateRight(Node *n) 
        {
            Node *temp = n->left;
            n->left = temp->right;
            temp->right = n;
            n->height = std::max(height(n->left), height(n->right)) + 1;
            temp->height = std::max(height(temp->left), height(temp->right)) + 1;
            return temp;
        }

        Node* insert(Node *n, const value_type &data, Node *parent) 
        {
            if (n == NULL) 
            {
                Node tmp(data,parent);
                n  = alloc.allocate(1);      // free?
                alloc.construct(n,tmp);            
            } 
            else if (data.first < n->data.first) 
                n->left = insert(n->left, data, n);
            else if (data.first > n->data.first) 
                n->right = insert(n->right, data, n);
            else 
                n->data.second = data.second;

            n->height = std::max(height(n->left), height(n->right)) + 1;

            if (balance(n) > 1) 
            {
                if (balance(n->left) >= 0) 
                    n = rotateRight(n);
                else 
                {
                    n->left = rotateLeft(n->left);
                    n = rotateRight(n);
                }
            } 
            else if (balance(n) < -1) 
            {
                if (balance(n->right) <= 0) 
                    n = rotateLeft(n);
                else 
                {
                    n->right = rotateRight(n->right);
                    n = rotateLeft(n);
                }
            }
                return n;
        }

        void insert(const value_type &data)
        {
            root = insert(root, data, NULL);
        }     

        Node* minNode(Node *n) 
        {
            while (n->left) 
                n = n->left;
            
            return n;
        }

        Node* remove(Node *n, const mapped_type &key) 
        {
            if (n == NULL) 
                return n;

            if (key < n->data.first) 
                n->left = remove(n->left, key);
            else if (key > n->data.first) 
                n->right = remove(n->right, key);
            else 
            {
                if (n->left == NULL || n->right == NULL) 
                {
                    Node *temp = n->left ? n->left : n->right;
                    if (temp == NULL) 
                    {
                        temp = n;
                        n = NULL;
                    } 
                    else 
                    {
                        n->data = temp->data; 
                        n->left = temp->left;
                        n->right = temp->right;
                    }
                    alloc.deallocate(temp,1);
                } 
                else 
                {
                    Node *temp = minNode(n->right);
                    n->data = temp->data; 
                    n->right = remove(n->right, temp->data.first);
                }
            }

            if (n== NULL) 
                return n;

            n->height = std::max(height(n->left), height(n->right)) + 1;

            if (balance(n) > 1) 
            {
                if (balance(n->left) >= 0) 
                    n = rotateRight(n);
                else 
                {
                    n->left = rotateLeft(n->left);
                    n = rotateRight(n);
                }
            } 
            else if (balance(n) < -1) 
            {
                if (balance(n->right) <= 0) 
                    n = rotateLeft(n);
                else 
                {
                    n->right = rotateRight(n->right);
                    n = rotateLeft(n);
                }
            }
            return n;
        }

        void deleteNode(const mapped_type &key)
        {
            root = remove(root,key);
        }

        constNode<key_type,mapped_type>  returnConst()
        {
            Node n = *minNode(root);
            constNode<key_type,mapped_type>  r(n.data.first,n.data.second);
            return r;
        }

        // void printPreorder( Node* node)
        // {
        //     if (node == NULL)
        //         return;
        
        //     /* first print data of node */
        
        //     /* then recur on left subtree */
        //     printPreorder(node->left);
        
        //     cout << node->data.first << " ";
        //     /* now recur on right subtree */
        //     printPreorder(node->right);
        // }
    ~avl(){}
    private:
            
};
 



#endif