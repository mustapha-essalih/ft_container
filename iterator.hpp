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
                    a = alloc.allocate(sizeof(avl<T>));
                }
                iterator(const iterator & obj):node(obj.node) 
                {
                    this->a = obj.a;
                    this->max = obj.a->findMX(obj.a->root);
                 
                    i = 0;
                }

                 
                iterator & operator = (const iterator & obj)
                {
                    if(!obj.node)
                        return *this;
                    this->a = alloc.allocate(sizeof(avl<T>));
                    if(this != &obj)
                    {
                        // *this->a = *obj.a;

                        *this->a = *obj.a;
                        node = obj.node;
                    }   
                    return *this;
                }
                 
                iterator(Node<T> * obj,avl<T> * tmp)// initialization list for const value of first
                {
                    if(!obj)
                        return ;
                    // if(obj == nullptr)
                    node = obj;
                    
                    a = alloc.allocate(sizeof(avl<T>));// because if not alloc when want access to member in avl hi segfault
                    
                    alloc.construct(a,*tmp);

                    max = a->findMX(a->root);
              
                    i = 0;   
                }
                iterator(Node<T> * obj):node(obj)// we pass pointer for end()
                {
                    // a->tmp  = alloc.allocate(sizeof(Node<T>));

                }
                
                bool operator== (const iterator& obj) const
                {
                    return node == obj.node;
                }
                iterator& operator++() 
                {
                    if(i == 0)
                        node = a->findSuccessor(a->root,node->data);// because ignor recal findSuccessor and print duplicate values
                    if(node == this->max && i == 0)
                        i++;
                    else
                        node = nullptr;
                    // cout << node->data.first << endl;
                    
                    
                    
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
                
                bool operator!=(const iterator& obj) const//
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


                // T& operator*() const {return ptr;}

#endif
 