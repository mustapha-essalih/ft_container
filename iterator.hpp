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

// #include "avl.hpp"
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

                }

                 
                ~iterator()
                { 
                }
        private:
                 
            int i ;
            avl<T>  a;
            Allocator alloc;
            Node<T> * root;
            Node<T> * succ;
            Node<T> * max;
            

};

}
#endif
 
  