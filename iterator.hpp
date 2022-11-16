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
        typedef const T*         const_iterator;
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
        iterator operator--()
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
      
        ~iterator()
        {

        }

        private:
            pointer blcok_;
};


    template < typename T>

class reverse_iterator  
{
    
    public:
        typedef T value_type;
        typedef 	std::ptrdiff_t difference_type;
        typedef  T*         pointer;
        typedef T& reference;
        typedef size_t size_type;

        reverse_iterator()
        {
            
        }
        reverse_iterator(pointer p):blcok_(p)
        {
        }
        reverse_iterator &operator++()
        {
            --blcok_;
            return *this;
        }
        bool operator!=(  reverse_iterator &  obj)
        {
            return blcok_ != obj.blcok_;
        }
        bool operator!=(  reverse_iterator  obj)
        {
            return blcok_ != obj.blcok_;
        }
        reference operator*() const 
        {
            return *blcok_; 
        }
        pointer operator->()
        {
            return blcok_; // print the address of reverse_iterator
        }
        reverse_iterator & operator--()
        {
            ++blcok_;
            return  *this;
        }
        reverse_iterator operator++(int)
        {
            
            reverse_iterator temp = *this;
            // ++*this;
            blcok_--;
            return temp;

        }
        reverse_iterator  operator--(int)
        {
            reverse_iterator temp = *this;
            blcok_++;

            // --*this;
            return temp;
            
        }
        bool operator==(  reverse_iterator  obj)
        {
            return blcok_ == obj.blcok_;
        }
       
        ~reverse_iterator()
        {

        }

        private:
            pointer blcok_;
};


}








#endif