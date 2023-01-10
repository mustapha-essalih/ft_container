#ifndef ITERATOR_HPP
#define ITERATOR_HPP

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

#include <utility>

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class it 
    {
        public:
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };


}



#endif