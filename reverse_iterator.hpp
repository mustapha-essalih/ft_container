#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "vector.hpp"

#include "iterator.hpp"

#include "iterator_traits.hpp"


#include "reverse_iterator.hpp"
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
            // T here is typedef ft::vector<int>::iterator iter_type; and we convert it to  iterator_type
            typedef  T iterator_type;

            typedef typename ft::iterator_traits<T>::reference reference;

            reverse_iterator()
            {
            }
            reverse_iterator (iterator_type it):ptr(it)
            {
            }
            // reverse_iterator (const reverse_iterator<iterator_type>& rev_it)
            // {
            //     ptr = rev_it.ptr;
            // }
            // iterator_type base() const // convert from reverse iterator to forwerd iterator (normal iteraor)
            // {
            //     iterator_type p = ptr;
                
            //     return p++;
            // }

            reverse_iterator &operator++()
            {
                --ptr;
                return *this;
            }
            // reverse_iterator& operator--() {++ptr; return *this;}// here ptr is object and call iterator increment object (iterator& operator--())
            reverse_iterator operator++(int)
            {
                --ptr;
                return *this;

            }
            bool operator!=(const reverse_iterator & obj) const {return ptr != obj.ptr;}
            reverse_iterator operator -- ()              {return reverse_iterator(++ptr);}
            reverse_iterator operator -- (int val)       {ptr += val; return reverse_iterator(ptr);}
            reverse_iterator operator += (int val)       {ptr -= val; return reverse_iterator(ptr);}
            reverse_iterator operator -= (int val)       {ptr += val; return reverse_iterator(ptr);}

            reverse_iterator operator + (int val) const  {iterator_type it = ptr - val; return reverse_iterator(it);}
            reverse_iterator operator - (int val) const  {iterator_type it = ptr + val; return reverse_iterator(it);}

            // bool operator == (const reverse_iterator & other) const     {return other == base();}
            // bool operator != (const iterator_type & other) const     {return other != base();}

            reference operator*() const {return *ptr;}
            // reverse_iterator operator->() const {return base();}

            ~reverse_iterator()
            {

            }
        private:
            iterator_type ptr;

    };

}








#endif