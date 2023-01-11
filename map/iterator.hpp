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
 
#include "../utils/iterator_traits.hpp"
#include "../map/avl.hpp"
#include "../utils/type_traits.hpp"
 
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

// crete class iterator and inhert from it here

namespace ft 
{
    template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class map_iterator 
        {   
            public:
                
                typedef T                                           value_type;
                typedef ptrdiff_t                                   difference_type;
                typedef  T*                                         pointer;
                typedef  T&                                         reference;
                typedef ft::bidirectional_iterator_tag              iterator_category;
                
                Node<value_type,size_type> * node;             
            
                
                map_iterator():node(0){}
            
                map_iterator(Node<value_type,size_type> * n):node(n){}
                        
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

                map_iterator operator++(int) 
                { 
                    map_iterator temp = *this;

                    node = getNext(node);
                     
                    return temp;                    
                }
                
                map_iterator& operator--() 
                { 
                    node = getPrev(node);
                     
                    return *this;                    
                }
                map_iterator operator--(int) 
                {
                    map_iterator temp = *this;
                    
                    node =  getPrev(node);
                     
                    return temp;
                }
                
                bool operator == (const map_iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const map_iterator& it) const
                {
                    return node != it.node;
                }

                pointer operator->() const
                {
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                Node<value_type,size_type>* getNext(Node<value_type,size_type>* node)
                {
                    if(node->right != nullptr)
                        return minValue(node->right);
                    while (!is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }
                Node<value_type,size_type>* getPrev(Node<value_type,size_type>* node)
                {
                    if(node->left != nullptr)
                        return findMX(node->left);
                    while (is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }
                // avl<key_type,value_type,key_compare,size_type,Allocator> a;

    }; 
    
    template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class const_map_iterator 
        {   
            public:
                
                typedef T                                           value_type;
                typedef ptrdiff_t                                   difference_type;
                typedef  const T*                                   pointer;
                typedef  const T&                                   reference;
                typedef ft::bidirectional_iterator_tag              iterator_category;

                
                const_map_iterator():node(0){}
            
                const_map_iterator(Node<value_type,size_type> * n):node(n){}
                /*
                    if decalare const_iterator and assign it begin() will enter in this copy constructor;
                    if decalre const map will cal begin() const and enter to const iterator.
                */          
                const_map_iterator(const map_iterator<key_type,value_type,key_compare,size_type,Allocator> & it)
                {
                    node = it.node;
                }    
                const_map_iterator(const const_map_iterator & it)
                {
                    node = it.node;
                }
        
                const_map_iterator& operator=(const const_map_iterator& it)
                {
                    node = it.node;
                    return *this;
                }
                const_map_iterator& operator=(const map_iterator<key_type,value_type,key_compare,size_type,Allocator>& it)
                {
                    node = it.node;
                    return *this;
                }

                const_map_iterator& operator++() 
                { 
                    node = getNext(node);
                      
                    return *this;                    
                }

                const_map_iterator operator++(int) 
                { 
                    const_map_iterator temp = *this;

                    node = getNext(node);
                     
                    return temp;                    
                }
                
                const_map_iterator& operator--() 
                { 
                    node = getPrev(node);
                     
                    return *this;                    
                }
                const_map_iterator operator--(int) 
                {
                    const_map_iterator temp = *this;
                    
                    node = getPrev(node);
                     
                    return temp;
                }
                
                bool operator == (const const_map_iterator& obj) const
                {
                    return node == obj.node;
                }
                bool operator == (const map_iterator<key_type,value_type,key_compare,size_type,Allocator>& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const const_map_iterator& it) const
                {
                    return node != it.node;
                }

                bool operator!=(const  map_iterator<key_type,value_type,key_compare,size_type,Allocator>& it) const
                {
                    return node != it.node;
                }

                pointer operator->() const // here pointer  is const pointer for can't edit return value
                {                          // like it->second= 10 or  ++it->second
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                Node<value_type,size_type> * node;         

                Node<value_type,size_type>* getNext(Node<value_type,size_type>* node)
                {
                    if(node->right != nullptr)
                        return minValue(node->right);
                    while (!is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }
                Node<value_type,size_type>* getPrev(Node<value_type,size_type>* node)
                {
                    if(node->left != nullptr)
                        return findMX(node->left);
                    while (is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }
    }; 
};

 
#endif
 