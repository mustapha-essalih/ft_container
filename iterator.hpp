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
  
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

// crete class iterator and inhert from it here

namespace ft 
{
    template <typename key_type, class T,typename key_compare,typename size_type,typename mapped_type,typename Allocator  >

        class map_iterator 
        {   
            public:
                
                typedef constNode<key_type,mapped_type>                                             value_type;
                typedef ptrdiff_t                                                                   difference_type;
                typedef  T*                                                                         pointer;
                typedef  T&                                                                         reference;
                typedef std::bidirectional_iterator_tag                                             iterator_category;
                
                // crete private const Node struct and assign to it non const struct

                constNode<key_type,mapped_type> * node;             
            
                
                map_iterator():node(0){}
            
                map_iterator(constNode<key_type,mapped_type>* n):node(n)
                {
                    
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
                    // node = a.getNext(node);
                      
                    return *this;                    
                }
 
                
                map_iterator& operator--() 
                { 
                    // node = a.getPrev(node);
                     
                    return *this;                    
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
                 

    }; 
     
};

 
#endif