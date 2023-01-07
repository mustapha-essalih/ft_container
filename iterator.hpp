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
 
#include "type_traits.hpp"
#include "map.hpp"
#include "avl.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

namespace ft
{
    template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class iterator  : public std::iterator<std::bidirectional_iterator_tag,T>// ?
        {
            
            public:
                 
                typedef T                                   value_type;
                typedef ptrdiff_t                           difference_type;
                typedef T*                                  pointer;
                typedef T&                                  reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
                 
                iterator():node(0){}
            
                iterator(Node<T,size_type> * n):node(n){}
                        
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

                iterator operator++(int) 
                { 
                    iterator temp = *this;

                    node = a.getNext(node);
                     
                    return temp;                    
                }
                
                iterator& operator--() 
                { 
                    node = a.getPrev(node);
                     
                    return *this;                    
                }
                iterator operator--(int) 
                {
                    iterator temp = *this;
                    
                    node = a.getPrev(node);
                     
                    return temp;
                }
                
                bool operator == (const iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const iterator& it) const
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
                Node<value_type,size_type> * node;             
    };
    
        template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class const_iterator  : public std::iterator<std::bidirectional_iterator_tag,T>
        {
            
            public:
                 
                typedef T                                         value_type;
                typedef ptrdiff_t                                 difference_type;
                typedef const T*                                  const_pointer;
                typedef const T&                                  const_reference;
                typedef std::bidirectional_iterator_tag     iterator_category;
                 
                const_iterator():node(0){}
            
                const_iterator(Node<T,size_type> * n):node(n){}
                        
                const_iterator(const const_iterator& it)
                {
                    node = it.node;
                }
        
                const_iterator& operator=(const const_iterator& it)
                {
                    node = it.node;
                    return *this;
                }

                const_iterator& operator++() 
                { 
                    node = a.getNext(node);
                     
                    return *this;                    
                }

                const_iterator operator++(int) 
                { 
                    const_iterator temp = *this;

                    node = a.getNext(node);
                     
                    return temp;                    
                }
                
                const_iterator& operator--() 
                { 
                    node = a.getPrev(node);
                     
                    return *this;                    
                }
                const_iterator operator--(int) 
                {
                    const_iterator temp = *this;
                    
                    node = a.getPrev(node);
                     
                    return temp;
                }

                bool operator == (const const_iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const const_iterator& it) const
                {
                    return node != it.node;
                }

                const_pointer * operator->() const
                {
                    return &node->data;
                }
                const_reference operator*() const
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
 
  