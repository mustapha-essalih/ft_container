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

template <typename A, typename size>

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
 

template<class T,typename s, typename pointer, typename value_type ,typename const_pointer, typename Allocator = std::allocator<Node<T,s> > >

class avl
{
    private:
        Allocator alloc;
    public:
        Node<T,s> * root;
        Node<T,s> * tmp;
        Node<T,s> * end_node;
        
        class iterator : public std::iterator<std::bidirectional_iterator_tag, Node<T,s> >
        {   
            public:
                iterator():node(0){}
            
                iterator(Node<T,s> * n):node(n){}
                        
                iterator(const iterator& it)
                {
                    node = it.node;
                }
        
                iterator& operator=(const iterator& it)
                {
                    node = it.node;
                    return *this;
                }

                iterator& operator++() 
                { 
                    node = a.getNext(node);
                     
                    return *this;                    
                }
                
                iterator& operator--() 
                { 
                    node = a.getPrev(node);
                     
                    return *this;                    
                }
                
                bool operator == (const iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const iterator& it) 
                {
                    return node != it.node;
                }

                pointer operator->() const
                {
                    return &node->data;
                }
            private:
                friend class avl;
                avl a;
                Node<T,s> * node;
        };
        
        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, Node<T,s> >
        {   
            public:
                const_iterator():node(0){}
                const_iterator(Node<T,s> * n):node(n){}
                const_iterator(const iterator& it)
                {
                    node = it.node;
                }
                const T * operator->() const
                {
                    return &node->data;
                }
                ~const_iterator(){}
            
                
            private:
                friend class avl;
                avl a;
                Node<T,s> * node;
        };

        avl()
        {
            root  = nullptr;
            Node<T,s>tmp(T(),nullptr);
            end_node  = alloc.allocate(sizeof(Node<T,s>));      // free?
            alloc.construct(end_node,tmp);
        }   
         
        bool empty()
        {
            return root == nullptr;
        }

        s height(Node<T,s>  *N)
        {
            if (N == nullptr)
                return 0;
            return N->height;
        }
        s max(s a, s b)
        {
            return (a > b) ? a : b;
        }
        void update_height(Node<T,s> * root)
        {

            if (root != nullptr) 
            {
                s val = 1;
                if (root->left != nullptr)
                    val = root->left->height + 1;
                if (root->right != nullptr)
                    val = max( val, root->right->height + 1);
                root->height = val;
            }
        }

 
        Node<T,s>  *rightRotate(Node<T,s>  *y)
        {
            Node<T,s>  *x = y->left;
            Node<T,s>  *T2 = x->right;

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

        
        Node<T,s>  *leftRotate(Node<T,s>  *x)
        {
            Node<T,s>  *y = x->right;
            Node<T,s>  *T2 = y->left;

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


        s getBalance(Node<T,s>  *N)
        {

            if (N == nullptr)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node<T,s>* insert(Node<T,s> *par, Node<T,s>* root, T data)
        {

            if(!root)
            {
                Node<T,s>tmp(data,par);
                
                Node<T,s> * newNode = alloc.allocate(sizeof(Node<T,s>));
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
    
        bool is_left_child(Node<T,s> * node)
        {
            return node == node->parent->left;
        }
        // after
        Node<T,s>* getNext(Node<T,s>* node)
        {
            if(node->right != nullptr)
                return minValue(node->right);
            while (!is_left_child(node))
                node = node->parent;
            return node->parent;
        }

        // before
        Node<T,s>* getPrev(Node<T,s>* node)
        {
            if(node->left != nullptr)
                return findMX(node->left);
            while (is_left_child(node))
                node = node->parent;
            return node->parent;
        }
         
        Node<T,s> *find(Node<T,s>* node, T key) 
        {
            if (node == nullptr)
                return nullptr;
        
            if (node->data.first == key.first)// use here key compar
                return node;
        
            /* then recur on left subtree */

            Node<T,s> * res1 = find(node->left, key);
            // node found, no need to look further
            if(res1) return res1;
        
            /* node is not found in left,
            so recur on right subtree */
            Node<T,s> * res2 = find(node->right, key);
        
            return res2;
        }
        
       Node<T,s> * minValue(Node<T,s>* node) 
        {
            if(node == nullptr)
                return nullptr;
            Node<T,s>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->left != nullptr) 
                tmp = tmp->left;
            return (tmp);
        }
        Node<T,s> * minValue(Node<T,s>* node) const
        {
            if(node == nullptr)
                return nullptr;
            Node<T,s>* tmp = node;
            
                while (tmp->left != nullptr) 
                    tmp = tmp->left;
            
            return (tmp);
        }
        
        Node<T,s>* findMX(Node<T,s>* r)
        {
            Node<T,s>* tmp = r;
        
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp);
        }

        ~avl()
        {

        }
};
 



#endif



