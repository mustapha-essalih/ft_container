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
 

template<class T,typename s, typename pointer,typename Allocator = std::allocator<Node<T,s> > >

class avl
{
    private:
        Allocator alloc;
         
    public:
        
     
        Node<T,s> * root;
        
        class iterator : public std::iterator<std::bidirectional_iterator_tag, Node<T,s> >
        {   

            public:
                    
                iterator():node(0){}

                iterator(Node<T,s> * n):node(n)
                {
                }
                
                iterator(const iterator& it)
                {
                    node = it.node;

                }
        
                iterator& operator=(const iterator& it)
                {
                    node = it.node;
                    
                    return *this;
                }

                iterator& operator++() // handle this
                { 
                    if(node->right != nullptr)
                    {
                        node = node->right;
                        while(node->left != nullptr)
                            node = node->left;
                    }
                    else
                    {
                        Node<T,s>* temp;
                        do{
                            temp = node;
                            node = node->parent;
                            if (node!=nullptr && node->left == temp) 
                                break;
                        }while(node->parent != nullptr);
                    }

                    return *this;                    
                } 

                bool operator == (const iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const iterator& it) const{
                    return node != it.node;
                }

                pointer operator->() const
                {
                    return &node->data;
                }
            private:
                Node<T,s> * node;
        };

        avl()
        {
           root  = nullptr;       
        }   
         
        bool empty()
        {
            return root == nullptr;
        }

        int height(Node<T,s>  *N){
    if (N == nullptr)
        return 0;
    return N->height;
}

 
        void update_height(Node<T,s> * root){

            if (root != nullptr) {
                s val = 1;
                if (root->left != nullptr)
                    val = root->left->height + 1;
                if (root->right != nullptr)
                    val = std::max( val, root->right->height + 1);
                root->height = val;
            }
        }

 
        Node<T,s>  *rightRotate(Node<T,s>  *y){
            Node<T,s>  *x = y->left;
            Node<T,s>  *T2 = x->right;

            if (x->right != nullptr)
                x->right->parent = y;

            y->left = T2;
            x->right = y;

            x->parent = y->parent;
            y->parent = x;

            if (x->parent != nullptr && y->data < x->parent->data) {
                x->parent->left = x;
            }
            else{
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

        
        Node<T,s>  *leftRotate(Node<T,s>  *x){

            Node<T,s>  *y = x->right;
            Node<T,s>  *T2 = y->left;

            x->right = T2;

            if (y->left != nullptr)
                y->left->parent = x;
            y->left = x;

            y->parent = x->parent;
            x->parent = y;

            if (y->parent != nullptr && x->data < y->parent->data) {
                y->parent->left = y;
            }
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


        int getBalance(Node<T,s>  *N){

            if (N == nullptr)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node<T,s>* insert(Node<T,s> *par, Node<T,s>* root, T data){

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
        
      Node<T,s>* findMX(Node<T,s>* r)
        {
            Node<T,s>* tmp = r;
        
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp->right);
        }
         
        
        ~avl()
        {

        }
};
 



#endif



