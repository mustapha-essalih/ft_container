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
    template < typename T>// if const_iterator will replace T by const T (const int , const double...)

        class iterator  : public std::iterator<std::random_access_iterator_tag,T>
        {
            
            public:

            typedef typename std::iterator<std::random_access_iterator_tag,T>::value_type value_type;
            iterator() : ptr(0) 
            {
            }
            iterator(T * obj) : ptr(obj) {}
            iterator(const iterator & obj) : ptr(obj.ptr) 
            {
            }
            // iterator& operator=(const iterator &obj)// std::iterator dont have 
            // {
            //     if(this != &obj)
            //     {
            //         this = obj;
            //     }
            //     return *this;
            // }
            iterator& operator+=(value_type obj) {ptr += obj; return *this;}
            iterator& operator-=(value_type obj) {ptr -= obj; return *this;}
            T& operator*() const {return *ptr;}
            T* operator->() const {return ptr;}
            T& operator[](value_type obj) const {return ptr[obj];}
            
            iterator& operator++() {
                ++ptr; return *this;
                
                }
            iterator& operator--() {
                
                --ptr; return *this;}
            iterator operator++(int)  {
                
                iterator tmp(*this); ++ptr; return tmp;}
            iterator operator--(int)  {
                
                iterator tmp(*this); --ptr; return tmp;}
            value_type operator-(const iterator& obj) const {return ptr-obj.ptr;}
            iterator operator+(value_type obj) const {return iterator(ptr+obj);}
            iterator operator-(value_type obj) const {return iterator(ptr-obj);} 

            bool operator==(const iterator& obj) const {return ptr == obj.ptr;}
            bool operator!=(const iterator& obj) const {return ptr != obj.ptr;}
            bool operator>(const iterator& obj) const {return ptr > obj.ptr;}
            bool operator<(const iterator& obj) const {return ptr < obj.ptr;}
            bool operator>=(const iterator& obj) const {return ptr >= obj.ptr;}
            bool operator<=(const iterator& obj) const {return ptr <= obj.ptr;}
            ~iterator()
            {
            }
        private:
            T * ptr;
};

}



#endif