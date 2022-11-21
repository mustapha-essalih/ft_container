#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator.hpp"

#include "iterator_traits.hpp"
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

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

namespace ft 
{

    template <class T> 

    class reverse_iterator
    {
        public:
            typedef   ft::iterator<T> iterator_type;

            typedef typename ft::iterator_traits<iterator_type>::reference reference;

            reverse_iterator()
            {
            }
            reverse_iterator (iterator_type it)
            {   
                ptr = it ;
            }
            reverse_iterator (const reverse_iterator<T>& rev_it)
            {
                ptr = rev_it.ptr;
            }
            reverse_iterator base() const                        {iterator_type ptr = ptr; return --ptr;}

            reverse_iterator& operator++() 
            {
                --ptr; 
                return *this;
            }
            reverse_iterator& operator--() {++ptr; return *this;}// here ptr is object and call iterator increment object (iterator& operator--())
            reverse_iterator operator++(int)  {reverse_iterator tmp(*this); --ptr; return tmp;}
            bool operator!=(const reverse_iterator & obj) const {return ptr != obj.ptr;}
            // reverse_iterator operator -- ()              {return reverse_iterator(++_it);}
            // reverse_iterator operator -- (int val)       {_it += val; return reverse_iterator(_it);}
            // reverse_iterator operator += (int val)       {_it -= val; return reverse_iterator(_it);}
            // reverse_iterator operator -= (int val)       {_it += val; return reverse_iterator(_it);}

            // reverse_iterator operator + (int val) const  {iterator it = _it - val; return reverse_iterator(it);}
            // reverse_iterator operator - (int val) const  {iterator it = _it + val; return reverse_iterator(it);}

            // bool operator == (const iterator & other) const     {return other == base();}
            // bool operator != (const iterator & other) const     {return other != base();}

            reference operator*() const {return *ptr;}
            // iterator operator->() const {return base();}

            ~reverse_iterator()
            {

            }
        private:
            iterator_type ptr;

    };

}








#endif