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
                T  ptr;

                int i;
                int i2;
                
                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                iterator()  
                {
                }
                 
                iterator(T obj,avl<T> * tmp):ptr(obj)// initialization list for const value of first
                {
                    i = 0;
                    

                    a = alloc.allocate(sizeof(avl<T>));// because if not alloc when want access to member in avl hi segfault
                    
                    alloc.construct(a,*tmp);

                    a->succ =  a->findSuccessor(a->root,ptr);
                     

                   
                }
                iterator(Node<T> * obj)// we pass pointer for end()
                {
                }
                 
                iterator& operator++() 
                {
                     
                    a->succ =  a->findSuccessor(a->root,a->succ->data);
                        
                    return *this;                    
                } 

                T * operator->() 
                {
                    return &a->succ->data; 
                }
                
                bool operator!=(const iterator& obj) const//
                {
                    return a->succ != nullptr;
                }
                
                ~iterator()
                {
                }
        private:
            avl<T> * a;
            Allocator alloc;

};

}


                // T& operator*() const {return ptr;}

#endif
 