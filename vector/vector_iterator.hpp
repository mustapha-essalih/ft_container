#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

 
namespace ft
{ 
    template < typename T, typename A = std::allocator<T> >// if const_iterator will replace T by const T (const int , const double...)

        class vector_iterator  
        {
            
            public:
                typedef T                                                                       iterator_type;
                typedef typename iterator_traits<iterator_type>::iterator_category              iterator_category;
                typedef typename iterator_traits<iterator_type>::value_type                     value_type;
                typedef typename iterator_traits<iterator_type>::difference_type                difference_type;
                typedef typename iterator_traits<iterator_type>::pointer                        pointer;
                typedef typename iterator_traits<iterator_type>::reference                      reference;
                 
            //default constructor
            vector_iterator() : ptr(0) {}

            // copy constructor
            vector_iterator(const vector_iterator & __x): ptr(__x.ptr){}

            // copy assignement overloding
            vector_iterator& operator=(const vector_iterator& __x)
            {
                if (this != &__x)
                    ptr = __x.ptr;
                return *this;
            }   
 
            vector_iterator(iterator_type p) : ptr(p) {}
              
             bool operator!=(const vector_iterator& other) const {
                return this->ptr != other.ptr;
            }
            // operators
            // iterator_type base() const  {return ptr;}

            reference operator*() const {   return *ptr;    }
            pointer  operator->() const {   return *ptr;    } // ?
            vector_iterator & operator++(){  ++ptr;  return *this; }
            vector_iterator  operator++(int) {vector_iterator __tmp(*this); ++(*this); return __tmp;}
            vector_iterator& operator--()  {  --ptr; return *this; }
            vector_iterator  operator--(int)  {vector_iterator __tmp(*this); --(*this); return __tmp;}
            
            // The difference_type operator-(const vector_iterator& other) const function calculates the difference between two iterators, 
            // and returns the result as a difference_type value. The vector_iterator operator- (difference_type n) 
            // const function returns a new vector_iterator that points to n elements before the current iterator.

            vector_iterator& operator+=(difference_type __n) 
            { 
                ptr += __n;
                return *this;
            }

            vector_iterator& operator-=(difference_type __n) 
            {*this += -__n; return *this;}

            vector_iterator  operator- (difference_type __n) const // search operator- (difference_type __n) vs operator-(const vector_iterator& other)
            {return *this + (-__n);}
           
            difference_type operator-(const vector_iterator& other) const // position - begin
            {
                return this->ptr - other.ptr;
            }
            vector_iterator  operator+ (difference_type __n) const  {vector_iterator __w(*this); __w += __n; return __w;}            
 
            reference    operator[](difference_type __n) const  { return ptr[__n]; }
            
            ~vector_iterator()
            {
            }
        private:
            iterator_type  ptr;

            template <class Iter1, class Iter2> // for compar if(begin() == end())
            friend bool operator==(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            { 
                cout << "EEEE\n";
                return (lhs.ptr == rhs.ptr);
            }
            template <class Iter1, class Iter2>
            friend bool operator!=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            {
                return (lhs.ptr != rhs.ptr);
            }
            template <class Iter1, class Iter2>
            friend bool operator<(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            {
                return (lhs.ptr < rhs.ptr);
            }
            template <class Iter1, class Iter2>
            friend bool operator>(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            {
                return (lhs.ptr > rhs.ptr);
            }
            template <class Iter1, class Iter2>
            friend bool operator<=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            {
                return (lhs.ptr <= rhs.ptr);
            }
            template <class Iter1, class Iter2>
            friend bool operator>=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
            {
                return (lhs.ptr >= rhs.ptr);
            }

             
    };
         
         
        
}

 
#endif





