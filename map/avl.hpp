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

template <typename A,typename size>

class Node{

    public:

        A  data; 
        Node<A,size> * left;
        Node<A,size> * right;
        Node<A,size> * parent;
        size height;

        Node<A,size>()
        {
        }
        Node<A,size>(A  d, Node<A,size> * p):data(d)
        {
            left = nullptr;
            right = nullptr;
            parent = p;
            height = 1;
        }
        ~Node<A,size>()
        {
        }
};
 

template<typename key_type,class T,typename key_compare,typename size_type,typename Allocator >

class avl
{
    public:
        
        typedef Allocator allocator_type;
        typedef T value_type;
         
        key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        
        typedef typename allocator_type::template rebind<Node<value_type,size_type> >::other node_allocator;
        
        

        node_allocator alloc;

        Node<value_type,size_type> * root;
        Node<value_type,size_type> * tmp;
        Node<value_type,size_type> * end_node;
        // Node<value_type,size_type> * newNode;
 
        avl()
        {
            
            // newNode = nullptr;
            root = nullptr;
            tmp = nullptr;
            Node<value_type,size_type> temp(T(),nullptr);
            end_node  = alloc.allocate(sizeof(Node<value_type,size_type>));      // free?
            alloc.construct(end_node,temp);
        }   
         
        bool empty()
        {
            return root == nullptr;
        }

        size_type height(Node<value_type,size_type>  *N)
        {
            if (N == nullptr)
                return 0;
            return N->height;
        }
        size_type max(size_type a, size_type b)
        {
            return (a > b) ? a : b;
        }
        void update_height(Node<value_type,size_type> * root)
        {

            if (root != nullptr) 
            {
                size_type val = 1;
                if (root->left != nullptr)
                    val = root->left->height + 1;
                if (root->right != nullptr)
                    val = max( val, root->right->height + 1);
                root->height = val;
            }
        }

 
        Node<value_type,size_type>  *rightRotate(Node<value_type,size_type>  *y)
        {
            Node<value_type,size_type>  *x = y->left;
            Node<value_type,size_type>  *T2 = x->right;

            if (x->right != nullptr)
                x->right->parent = y;

            y->left = T2;
            x->right = y;

            x->parent = y->parent;
            y->parent = x;

            if (x->parent != nullptr && y->data < x->parent->data)
                x->parent->left = x;
            else
            {
                if (x->parent != nullptr)
                    x->parent->right = x;
            }

            y = x;

            update_height(y->left);
            update_height(y->right);
            update_height(y);
            update_height(y->parent);

            return y;
        }

        
        Node<value_type,size_type>  *leftRotate(Node<value_type,size_type>  *x)
        {
            Node<value_type,size_type>  *y = x->right;
            Node<value_type,size_type>  *T2 = y->left;

            x->right = T2;

            if (y->left != nullptr)
                y->left->parent = x;
            y->left = x;

            y->parent = x->parent;
            x->parent = y;

            if (y->parent != nullptr && x->data < y->parent->data) 
                y->parent->left = y;
            else{
                if (y->parent != nullptr)
                    y->parent->right = y;
            }

            update_height(x->left);
            update_height(x->right);
            update_height(x);
            update_height(x->parent);

            return y;
        }

        size_type getBalance(Node<value_type,size_type>  *N)
        {

            if (N == nullptr)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node<value_type,size_type>* insert(Node<value_type,size_type> *par, Node<value_type,size_type>* root, T data)
        {
            if(!root)
            {
                Node<value_type,size_type>tmp(data,par);
                Node<value_type,size_type> * newNode = alloc.allocate(sizeof(Node<value_type,size_type>));
                alloc.construct(newNode,tmp);
                return newNode;  
            }
 
            if (data < root->data)
                root->left = insert(root, root->left, data);

            else if (data > root->data)
                root->right = insert(root, root->right, data);

            else 
                return root;
 
            int balance = getBalance(root);
         
            if (balance > 1 && data < root->left->data)
                return rightRotate(root);

       
            if (balance < -1 && data > root->right->data)
                return leftRotate(root);

      
            if (balance > 1 && data > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            if (balance < -1 && data < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            update_height(root);
            return root;
        }

        void insert(T data)
        {
            root = insert(nullptr, root, data);
              
            end_node->left = root;
            root->parent = end_node; 
        }
    
        bool is_left_child(Node<value_type,size_type> * node)
        {
            return node == node->parent->left;
        }
        // after
        Node<value_type,size_type>* getNext(Node<value_type,size_type>* node)
        {
            if(node->right != nullptr)
                return minValue(node->right);
            while (!is_left_child(node))
                node = node->parent;
            return node->parent;
        }

        // before
        Node<value_type,size_type>* getPrev(Node<value_type,size_type>* node)
        {
            if(node->left != nullptr)
                return findMX(node->left);
            while (is_left_child(node))
                node = node->parent;
            return node->parent;
        }
         
        Node<value_type,size_type> *search(Node<value_type,size_type>* root, const key_type & key) const // search() const because key_type is const
        {
            if (root == nullptr || (!key_compare_(root->data.first, key) && !key_compare_(key,root->data.first)))// because key_compare_ return < and convert it to ==
                return root;
             
            if (key_compare_(root->data.first, key))
                return search(root->right, key);        
            return search(root->left, key);
        }
 
       Node<value_type,size_type> * minValue(Node<value_type,size_type>* node) const
        {
            if(node == nullptr)
                return nullptr;
            Node<value_type,size_type>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->left != nullptr) 
                tmp = tmp->left;
            return (tmp);
        }
        
        Node<value_type,size_type>* findMX(Node<value_type,size_type>* r)
        {
            Node<value_type,size_type>* tmp = r;
        
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp);
        }

          
        Node<value_type,size_type> * findNodeByK(Node<value_type,size_type> *root, key_type k) 
        {
            Node<value_type,size_type>* x = root;
            Node<value_type,size_type>* y = end_node;
        
            while (x != 0 && x->left != x && x != x->right)
            {
                if (key_compare_(x->data.first, k))
                    x = x->right;
                else
                    y = x, x = x->left;
            }
            return y;
        }

        
        Node<value_type,size_type> * deleteNodeHelper(Node<value_type,size_type> * root, key_type key) 
        {
            // search the key
            if (root == nullptr)
                return root;
            
            else if (key < root->data.first) 
                root->left = deleteNodeHelper(root->left, key);
            else if (key > root->data.first) 
            {
                 
                root->right = deleteNodeHelper(root->right, key);
            }
            else {
                // the key has been found, now delete it
                // case 1: node is a leaf node
                if (root->left == nullptr && root->right == nullptr) 
                {
                    alloc.deallocate(root,sizeof(root));
                    // alloc.deallocate(end_node,sizeof(end_node));
                    root = nullptr;
                }

                // case 2: node has only one child
                else if (root->left == nullptr) 
                {
                    Node<value_type,size_type> * temp = root;
                    root = root->right;
                    alloc.deallocate(temp,sizeof(temp));
                }

                else if (root->right == nullptr) 
                {
                    Node<value_type,size_type> * temp = root;
                    root = root->left;
                    alloc.deallocate(temp,sizeof(temp));
                }

                // case 3: has both children
                else 
                {
                    Node<value_type,size_type> * temp = minValue(root->right);
                    root->data= temp->data;
                    root->right = deleteNodeHelper(root->right, temp->data.first);
                }
            } 
            
            int bf = getBalance(root);
    // Left Left Imbalance/Case or Right rotation 
            if (bf == 2 && getBalance(root -> left) >= 0)
                return rightRotate(root);
            // Left Right Imbalance/Case or LR rotation 
            else if (bf == 2 && getBalance(root -> left) == -1) {
                root -> left = leftRotate(root -> left);
            return rightRotate(root);
            }
            // Right Right Imbalance/Case or Left rotation	
            else if (bf == -2 && getBalance(root -> right) <= -0)
                return leftRotate(root);
            // Right Left Imbalance/Case or RL rotation 
            else if (bf == -2 && getBalance(root -> right) == 1) {
                root -> right = rightRotate(root -> right);
            return leftRotate(root);
            }

 
            return root;
        }

        void deleteNode(key_type data) 
        {
            root = deleteNodeHelper(root, data);
        }

        void inOrder(Node<value_type,size_type>* node)
        {
            if (node == nullptr)
                return;
        
            inOrder(node->left);
        
            deleteNode(node->data.first);
        
            inOrder(node->right);
        }
        
        ~avl()
        { 
            alloc.deallocate(end_node,sizeof(end_node));
            inOrder(root);// if clear in main root will be null 
        }
        private:
            
};
 



#endif