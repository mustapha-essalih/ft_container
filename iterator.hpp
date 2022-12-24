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

                
                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                iterator()  
                {
                }
                iterator(const iterator & obj):node(obj.node) 
                {
                    this->a = obj.a;
                }
                iterator & operator = (const iterator & obj)
                {
                    cout << obj.a->root->data.first << endl;
                    if(this != &obj)
                    {
                        this->a = obj.a;
                        node = obj.node;
                    }   
                    return *this;
                }
                 
                iterator(Node<T> * obj,avl<T> * tmp)// initialization list for const value of first
                {
                    node = obj;
                    
                    a = alloc.allocate(sizeof(avl<T>));// because if not alloc when want access to member in avl hi segfault
                    
                    alloc.construct(a,*tmp);

                    max = a->findMX(a->root); 
                    i = 0;   
                }
                iterator(Node<T> * obj)// we pass pointer for end()
                {
                }
                
                iterator& operator++() 
                {
                    if(node->data == max->data)// here enter two time
                        i++;
                    node = a->findSuccessor(a->root,node->data);
                    
                 
                    return *this;                    
                } 

                T * operator->() 
                {
                    return &node->data;
                }
                
                bool operator!=(const iterator& obj) const//
                {
                    if(i == 0)
                        return true;
                    else
                        return false;
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
 