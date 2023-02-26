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
 
#include "red_black_tree.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/iterator_traits.hpp"
   
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

 
namespace ft 
{ 

    template <typename T,typename Allocator  >

        class map_iterator 
        {         
            
            public:

                typedef T                                                                               value_type;
                typedef ptrdiff_t                                                                       difference_type;
                typedef  T *                                                                            pointer;
                typedef  T &                                                                            reference;
                typedef     std::bidirectional_iterator_tag                                                 iterator_category;// ft::
                
                typedef Node_struct<T> Node;
                Node * node;
            
                map_iterator():node(0){}

                map_iterator( Node * n):node(n){}
                
                map_iterator(const map_iterator  & it)
                {
                    node = it.node;
                }
        
                map_iterator& operator=(const map_iterator& it)
                {
                    if(this != &it)// if not is the same obj
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
                    map_iterator it(*this);
                    ++(*this);
                    return it;                   
                }
                
                map_iterator& operator--() 
                { 
                    node = getPrev(node);
                    return *this;                    
                }
                
                map_iterator operator--(int) 
                {
                    //  this is a pointer point to this class, and *this is a dereferenced pointer * on this the result is the object to which the pointer this was pointing.
                    map_iterator it(*this);// will call copy constructor
                    --(*this);
                    return it;
                }
                bool	operator==(const map_iterator &y) {return (node == y.node);}
			    bool	operator!=(const map_iterator &y) {return (node != y.node);}
                 

                pointer  operator->() const
                {
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
                  
            private: 

                
    };  
        
        template <typename T,typename Allocator  >

        class const_map_iterator 
        {   
            
            public:
                
                typedef   T                                                                               value_type;
                typedef ptrdiff_t                                                                       difference_type;
                typedef  const T *                                                                            pointer;
                typedef  const T &                                                                            reference;
                typedef std::bidirectional_iterator_tag                                                 iterator_category;// ft::
                
                typedef Node_struct<T> Node;
                Node * node; 
            
                const_map_iterator():node(0){}

                const_map_iterator(Node * n):node(n){}
                
                /*
                    if decalare const_iterator and assign it begin() will enter in this copy constructor;
                    if decalre const map will cal begin() const and enter to const iterator.
                */ 
                const_map_iterator(const map_iterator<value_type,Allocator>  & it)
                {
                    node = it.node;
                }
                const_map_iterator(const const_map_iterator  & it)
                {
                    node = it.node;
                }
        
                const_map_iterator& operator=(const const_map_iterator& it)
                {
                    if(this != &it)// if not is the same obj
                        node = it.node;
                    return *this;
                }

                const_map_iterator& operator=(const map_iterator<value_type,Allocator>& it)
                {
                    if(this != &it)// if not is the same obj
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
                    const_map_iterator it(*this);
                    ++(*this);
                    return it;                   
                }
                
                const_map_iterator& operator--() 
                { 
                    node = getPrev(node);
                    return *this;                    
                }
                
                const_map_iterator operator--(int) 
                {
                    //  this is a pointer point to this class, and *this is a dereferenced pointer * on this the result is the object to which the pointer this was pointing.
                    const_map_iterator it(*this);// will call copy constructor
                    --(*this);
                    return it;
                }

                bool	operator==(const const_map_iterator &y) {return (node == y.node);}
			    bool	operator!=(const const_map_iterator &y) {return (node != y.node);}

                pointer  operator->() const
                {
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                
    };  
 
};

 
#endif
 