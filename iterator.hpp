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
#include "bst.hpp"
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
    template < typename T>// if const_iterator will replace T by const T (const int , const double...)

        class iterator  : public std::iterator<std::bidirectional_iterator_tag,T>
        {
            
            public:
                T * ptr;

                typedef typename std::iterator<std::bidirectional_iterator_tag,T>::value_type value_type;

                iterator() : ptr(0) 
                {
                }
                iterator(T obj) : ptr(obj)
                {
                     
                }
                iterator(const iterator & obj) : ptr(obj.ptr) 
                {
                    cout << "GGGGG\n";
                }
                T& operator*() const {return ptr;}
                T* operator->() const {return ptr;}
                iterator& operator++() 
                {
                    ++ptr; 
                    return *this;
                    
                } 
                iterator operator++(int)  
                {
                    iterator tmp(*this); 
                    ++ptr; 
                    
                    return tmp;
                }
                bool operator!=(const iterator& obj) const {return ptr != obj.ptr;}
                
                ~iterator()
                {
                }
        private:
};

}



#endif