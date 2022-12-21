#ifndef BST_HPP
#define BST_HPP


#include <iomanip>
#include <cstddef>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>     
#include<iterator>
// #include "type_traits.hpp"
// #include "iterator.hpp"

#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::pair;


 
template <typename A>
class Node
{
    public:
        A value;
        A v;
        Node<A> * left;
        Node<A> * right;
        Node<A>()
        {
        }
        Node<A>(A v):value(v)// inistaializaion list for const value 
        {
            left = right = nullptr;
        }
         
};

// ft::pair<int,int> b;
template<typename T  , typename Allocator = std::allocator<Node<T> > >

class bst
{
    private:
        Allocator alloc;
              
    
    public:
        Node<T> * root;
        Node<T>* succ;
        Node<T>* n;

        bst()
        {
            root = nullptr;
            succ = nullptr;
        }
        T inOrder(Node<T> * root)// root left right
        {
            if(!root)// if empty
                return;
            inOrder(root->left);

            
            // cout << root->value.first << endl;
            // cout << root->value.second << endl;
            inOrder(root->right);
        }
        Node<T> * createNewNode(Node<T> * root, T data)// must handle if data entred equal data
        {
            // because i have problem of cpoy eelments
            if(!root)
            {
                Node<T>tmp(data);

                Node<T> * n = alloc.allocate(sizeof(Node<T>));
                alloc.construct(n,tmp);

                return n;
            }
            // her comapre using opearators of pair here two objects data and root->value
            else if(data < root->value)
                root->left = createNewNode(root->left,data);
            else 
                root->right = createNewNode(root->right,data);
            
            return root;
        }
    // return pointer
        Node<T> * minValue(Node<T>* node)
        {
            Node<T>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->left != nullptr) 
                tmp = tmp->left;
            return (tmp);
        }
        Node<T>* maxValue(Node<T>* node)
        {
            Node<T>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp);
        }
        T endOf(Node<T>* node)
        {
            Node<T>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp->value);
        }
        Node<T>* findMinimum(Node<T>* r)
        {
            while (r->left)
                r = r->left;    
            return r;
        }
        Node<T>* findSuccessor(Node<T>* root, T key)
        { 
            if (root == nullptr)
                return succ;
            
            if (root->value == key)
            {
                if (root->right != nullptr)
                    return findMinimum(root->right);
            }
            else if (key < root->value)
            {
                succ = root;
                return findSuccessor(root->left, key);
            }
            else 
                return findSuccessor(root->right, key);

            return succ;
        }
        // T value => obj.first , obj.second
        void insert(T value)// when insert insert key and value in one time
        {
            root = createNewNode(root,value);
        }
         
        ~bst()
        {
            // use iterator
            // if(root)
            //     free_(root); 
        }
};


// bast<ft::pair<int,int>>

#endif