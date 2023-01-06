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
#include "type_traits.hpp"
 

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
 

template<class T,typename key_compare,typename size_type,typename Allocator >

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
 
        avl()
        {
            Node<value_type,size_type> tmp(T(),nullptr);
            end_node  = alloc.allocate(sizeof(Node<value_type,size_type>));      // free?
            alloc.construct(end_node,tmp);
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
        


        Node<value_type,size_type> *find(Node<value_type,size_type>* node, T key) 
        {
            if (node == nullptr)
                return nullptr;

        // if (node->data.first == key.first)
            
            if (!key_compare_(node->data.first, key.first) && !key_compare_(key.first,node->data.first))// because key_compare_ return < and convert it to ==
                return node;
        
            
            Node<value_type,size_type> * res1 = find(node->left, key);
            // node found, no need to look further
            if(res1) return res1;
        
            /* node is not found in left,
            so recur on right subtree */
            Node<value_type,size_type> * res2 = find(node->right, key);
        
            return res2;
        }
        
       Node<value_type,size_type> * minValue(Node<value_type,size_type>* node)
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

        ~avl()
        {

        }
        private:
            
};
 



#endif



