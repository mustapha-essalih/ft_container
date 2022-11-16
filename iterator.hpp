#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>


#include "vector.hpp"

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
    template < typename T>

class iterator  
{
    
    public:
        typedef T value_type;
        typedef 	std::ptrdiff_t difference_type;
        typedef  T*         pointer;
        typedef T& reference;
        // typedef typename allocator_type::pointer         pointer;
        typedef size_t size_type;

        iterator()
        {
            
        }
        iterator(pointer p):blcok_(p)
        {
        }
        iterator &operator++()
        {
            ++blcok_;
            return *this;
        }
        bool operator!=(  iterator &  obj)
        {
            return blcok_ != obj.blcok_;
        }
        bool operator!=(  iterator  obj)
        {
            return blcok_ != obj.blcok_;
        }
        reference operator*() const 
        {
            return *blcok_; 
        }
        pointer operator->()
        {
            return blcok_; // print the address of iterator
        }
        reference operator--()
        {
            --blcok_;
            return  *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++*this;
            return temp;

        }
        iterator  operator--(int)
        {
            iterator temp = *this;
            --*this;
            return temp;
            
        }
        bool operator==(  iterator  obj)
        {
            return blcok_ == obj.blcok_;
        }
        // std::ostream & operator << (std::ostream & COUT, const iterator<value_type> & it)
        // {
        //     COUT << it.blcok_;
        //     return COUT;
        // }
        ~iterator()
        {

        }

        private:
            pointer blcok_;
};


}








#endif