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
                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                iterator()  
                {
                    // cout << a->node->data.first << endl;
                    /*
                        ft::map<int,int>::iterator it;                    
                        it = m.begin();
                        because when deallocate => free pointor not allcoate
                    */
                   
                    i = 0;
                }

                // copy constructor for begin()
                iterator(Node<T> * begin)
                {
                    node = begin;
                }

                // assignement overloading for begin()
                iterator & operator = (Node<T> * begin)
                {
                    return *this;
                }
                
                iterator& operator++() // handle this
                { 

                    return *this;                    
                } 
               
                T * operator->() 
                {    
                    return &node->data;
                }
                
                ~iterator()
                { 
                    // alloc.deallocate(a,sizeof(a));
                }
        private:

            int i ;
            avl<T>  a;
            Allocator alloc;
            Node<T> * node;
            Node<T> * max;
            

};

}
#endif
 
 




            // ft::map<int,int>::iterator it = m.begin();



                // T& operator*() const // (*it).first
                // {
                //     return node->data;
                // }
                
                
                // bool operator == (const iterator& obj) const
                // {
                //     return node == obj.node;
                // }
                
                // bool operator != (const iterator& obj) const//
                // {
                //     return  !(node == obj.node);
                // }