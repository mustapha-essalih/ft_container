#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iomanip>
#include <cstddef>
#include <map>
#include <__tree>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>     
#include<iterator>
 
#include "red_black_tre.hpp"
   
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

// crete class iterator and inhert from it here

namespace ft 
{
    template <typename key_type, typename T,typename key_compare,typename size_type,typename mapped_type,typename Allocator  >

        class map_iterator 
        {   
            public:
                
                typedef T                                                                           value_type;
                typedef ptrdiff_t                                                                   difference_type;
                typedef  T *                                                                         pointer;
                typedef  T &                                                                         reference;
                typedef std::bidirectional_iterator_tag                                             iterator_category;
                
                typedef Node_struct<T> Node;
                
            
                map_iterator():node(0){}
            
                map_iterator(  Node *  n):node(n){}
                map_iterator(Node * n,Node * e,Node * r):node(n)
                {
                    end = e;
                    root = r;
                }
                
                        
                map_iterator(const map_iterator& it)
                {
                    node = it.node;
                }
        
                map_iterator& operator=(const map_iterator& it)
                {
                    node = it.node;
                    return *this;
                }

                map_iterator& operator++() 
                {
                    node = getNext(node);
                    return *this;                    
                }
 
                
                map_iterator& operator--() 
                { 
                    if(node == end)
                    {
                        node = maxNode(root);
                        return *this;
                    }
                    node = getPrev(node);
                    return *this;                    
                }
                
                // bool operator == (const map_iterator& obj) const
                // {
                //     return this->node == obj.node; // 
                // }
                
                // bool operator!=(const map_iterator& it) const
                // {
                //     return node->data != it.node->data;
                // }

                // simetime compar const iteartor with non const iterator
                friend bool operator==(const map_iterator& __x, const map_iterator& __y)
                {return __x.node == __y.node;}
                friend bool operator!=(const map_iterator& __x, const map_iterator& __y)
                {return !(__x == __y);}

                pointer  operator->() const
                {
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                Node * node;             

                Node * root;
                Node * end;
                Node * minNode(Node * node)
                {
                    Node * current = node;
                
                    /* loop down to find the leftmost leaf */
                    while (current->left != NULL) {
                        current = current->left;
                    }
                    return (current);
                }
                Node * maxNode(Node * node)
                {
                    Node * current = node;
                 
                    while (current->right != NULL) {
                        current = current->right;
                    }
                    return (current);
                }
                bool is_left_child(Node * node)
                {
                    return node == node->parent->left;
                }
                Node* getNext(Node* node)
                {
                    if(node->right != NULL)
                        return minNode(node->right);
                    
                    while (!is_left_child(node))
                        node = node->parent;
                    return node->parent;
                } 
                Node* getPrev(Node* node)
                {
                    if(node->left != nullptr)
                        return maxNode(node->left);
                    while (is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }
                

    }; 
     
};

 
#endif