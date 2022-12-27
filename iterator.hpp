#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
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

#include "avl.hpp"
#include "type_traits.hpp"
#include "map.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

namespace ft
{
    template < typename T, typename Allocator = std::allocator<avl<T> > >// if const_iterator will replace T by const T (const int , const double...)

        class iterator  : public std::iterator<std::bidirectional_iterator_tag,T>
        {
            
            public:
                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                Node<T> * node;
                
                iterator()  
                {
                    succ = nullptr;
                    i = 0;
                }

                // copy constructor for begin()
                iterator(Node<T> * begin, Node<T> * root)
                {
                    node = begin;
                    this->root = root;
                    succ = node;
                    i = 0;
                    max = findMX(root);
             
                }

                // assignement overloading for begin()
                iterator & operator = (Node<T> * begin)
                {
                    return *this;
                }
                
                // copy constructor for end()
                iterator(Node<T> * end)  
                {
                    node = nullptr;
                }

                iterator& operator++() // handle this
                { 
                     
                    if(i == 0)
                        node = findSuccessor(this->root,node->data);

                    if(node == this->max && i == 0)
                        i++;
                    else if(i)
                        node = nullptr;

                    return *this;                    
                } 



                T * operator->() 
                {    
                    return &node->data;
                }
                bool operator == (const iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator != (const iterator& obj) const//
                {
                    return  node != nullptr;
                }
                ~iterator()
                { 
                    // alloc.deallocate(a,sizeof(a));
                }
        private:
                Node<T> * minValue(Node<T>* node)
                {
                    if(node == nullptr)
                        return nullptr;
                    Node<T>* tmp = node;
                
                    /* loop down to find the leftmost leaf */
                    while (tmp->left != nullptr) 
                        tmp = tmp->left;
                    return (tmp);
                }
                Node<T>* findMX(Node<T>* r)
                {
                    Node<T>* tmp = r;
                
                    while (tmp->right != nullptr) 
                        tmp = tmp->right;
                    return (tmp);
                }
                Node<T>* findSuccessor(Node<T>* root, T key)
                {
                    if (root == nullptr)
                        return succ;
                    
                    if (root->data == key )
                    {
                        if (root->right != nullptr)
                            return minValue(root->right);
                    
                    }
                    else if (key < root->data)
                    {
                        succ = root;
                        return findSuccessor(root->left, key);
                    }
                    else 
                        return findSuccessor(root->right, key);

                    return succ;
                }

            int i ;
            avl<T>  a;
            Allocator alloc;
            Node<T> * root;
            Node<T> * succ;
            Node<T> * max;
            

};

}
#endif
 
 




            // ft::map<int,int>::iterator it = m.begin();



                // T& operator*() const // (*it).first
                // {
                //     return node->data;
                // }
                
                
                // bool operator == (const iterator& obj) const
                // {
                //     return node == obj.node;
                // }
                
                // bool operator != (const iterator& obj) const//
                // {
                //     return  !(node == obj.node);
                // }