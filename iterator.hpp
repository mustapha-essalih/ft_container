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
                Node<T> * node;
                Node<T> * max;
                Node<T> * n;
                

                
                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                iterator()  
                {
                    i = 0;
                }

                // copy constructor
                iterator(const iterator & obj)//:node(obj.node) 
                {
                    
                    this->a = obj.a;
                    this->max = obj.a->findMX(obj.a->root);
                 
                    i = 0;
                }

                // copy constructor for begin()
                iterator(Node<T> * obj,avl<T> * tmp)// initialization list for const value of first
                {
                    if(!obj)// if avl is empty
                    {
                        node = nullptr;
                        return ;
                    }
                    a = alloc.allocate(sizeof(avl<T>));// because if not alloc when want access to member in avl hi segfault
                    node = obj;
                    
                    alloc.construct(a,*tmp);
                    max = a->findMX(a->root);
            
                    i = 0;   
                }

                // aginemnet oveloding
                iterator & operator = (const iterator & obj)
                {
                    i = 0;
                    if(!obj.node)// if avl is empty 
                    {
                        node = nullptr; // when print it->first will seqfault because assign nullptr
                        return *this;
                    }
                    this->a = alloc.allocate(sizeof(avl<T>));
                    if(this != &obj)
                    {
                        *this->a = *obj.a;
                        node = obj.node;
                    }   
                    return *this;
                }
                 
                // copy constructor for end()
                iterator(Node<T> * obj):node(obj)// we pass pointer for end()
                {
                }
                
                iterator& operator++() // handle this
                {
                    if(i == 0)
                        node = a->findSuccessor(a->root,node->data);// because ignor recal findSuccessor and print duplicate values
                    if(node == this->max && i == 0)
                        i++;
                    else
                        node = nullptr;
                    
                    return *this;                    
                } 

                T& operator*() const // (*it).first
                {
                    return node->data;
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
                    return  !(node == obj.node);
                }
                
                ~iterator()
                {
                    // alloc.deallocate(a,sizeof(a));
                }
        private:

            int i ;
            avl<T> * a;
            Allocator alloc;

};

}
#endif
 