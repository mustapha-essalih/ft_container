#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


#include "vector.hpp"

namespace ft
{
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
            ++blcok_;
            return *this;
        }
        bool operator!=(  reverse_iterator &  obj)
        {
            return blcok_ != obj.blcok_;
        }
        bool operator!=(  pointer  obj)
        {
            return blcok_ != obj;
        }
       reference operator*() const 
        {
            return *blcok_; 
        }
        reference operator--()
        {
            --blcok_;
            return  *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator temp = *this;
            ++*this;
            return temp;

        }
        reverse_iterator  operator--(int)
        {
            reverse_iterator temp = *this;
            --*this;
            return temp;
            
        }
        bool operator==(  pointer  obj)
        {
            return blcok_ == obj;
        }
        ~reverse_iterator()
        {

        }

        private:
            pointer blcok_;
        private:

    };

}



#endif