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
#include "type_traits.hpp"
   
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
                typedef std::bidirectional_iterator_tag                                             iterator_category;// ft::
                
                typedef Node_struct<T> Node;
            
                map_iterator():node(0){}
            
                map_iterator(const Node *  n):node(n){}
                map_iterator(const Node * n,const Node * e,const Node * r):node(n)
                {
                    end = e;
                    root = r;
                }
                
                map_iterator(const map_iterator & it)
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
                    if(node == end)
                    {
                        node = maxNode(root);
                        return *this;
                    }
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

                // sometime compar const iteartor with non const iterator
                // search for friend bool // because in the stantard
                friend bool operator==(const map_iterator& __x, const map_iterator& __y)
                {return __x.node == __y.node;}// compar nodes if have sime addrsess or not

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
                
    }; 
 
};

 
#endif
 