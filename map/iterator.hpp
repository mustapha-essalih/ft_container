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
                    node = a.getNext(node);
                      
                    return *this;                    
                }

                map_iterator operator++(int) 
                { 
                    map_iterator temp = *this;

                    node = a.getNext(node);
                     
                    return temp;                    
                }
                
                map_iterator& operator--() 
                { 
                    node = a.getPrev(node);
                     
                    return *this;                    
                }
                map_iterator operator--(int) 
                {
                    map_iterator temp = *this;
                    
                    node = a.getPrev(node);
                     
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
                friend class avl;
                avl<key_type,value_type,key_compare,size_type,Allocator> a;

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
                          
                const_map_iterator(const map_iterator<key_type,value_type,key_compare,size_type,Allocator> & it)
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
                    node = a.getNext(node);
                      
                    return *this;                    
                }

                const_map_iterator operator++(int) 
                { 
                    const_map_iterator temp = *this;

                    node = a.getNext(node);
                     
                    return temp;                    
                }
                
                const_map_iterator& operator--() 
                { 
                    node = a.getPrev(node);
                     
                    return *this;                    
                }
                const_map_iterator operator--(int) 
                {
                    const_map_iterator temp = *this;
                    
                    node = a.getPrev(node);
                     
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
                friend class avl;
                avl<key_type,value_type,key_compare,size_type,Allocator> a;
                Node<value_type,size_type> * node;             
    }; 
};

 
#endif
 