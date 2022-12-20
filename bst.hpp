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
#include "type_traits.hpp"

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
    
        Node<A> * left;
        Node<A> * right;
        Node<A>()
        {
            cout << "DDDD\n";
        }
        Node<A>(A v):value(v)
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

        bst()
        {
            root = nullptr;
        }
        void inOrder(Node<T> * root)// root left right
        {
            if(!root)// if empty
                return;
            inOrder(root->left);
            cout << root->value.first << endl;
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
            else if(data < root->value)
                root->left = createNewNode(root->left,data);
            else 
                root->right = createNewNode(root->right,data);
            return root;
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