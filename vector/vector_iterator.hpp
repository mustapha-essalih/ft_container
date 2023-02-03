#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

 
namespace ft
{
    template <typename T >
    class const_vector_iterator;
    template < typename T>// if const_iterator will replace T by const T (const int , const double...)

        class vector_iterator  
        {
            
            public:
                friend class const_vector_iterator<const T>;
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
 
            vector_iterator(pointer p) : ptr(p) {}
 
            // operators
            iterator_type base() const  {return ptr;}
            reference operator*() const {   return *ptr;    }
            pointer  operator->() const {   return *ptr;    } // ?
            vector_iterator & operator++(){  ++ptr;  return *this; }
            vector_iterator  operator++(int) {vector_iterator __tmp(*this); ++(*this); return __tmp;}
            vector_iterator& operator--()  {  --ptr; return *this; }
            vector_iterator  operator--(int)  {vector_iterator __tmp(*this); --(*this); return __tmp;}
            vector_iterator  operator+ (difference_type __n) const  {vector_iterator __w(*this); __w += __n; return __w;}
            vector_iterator& operator+=(difference_type __n) { ptr += __n;return *this;}
            vector_iterator  operator- (difference_type __n) const  {return *this + (-__n);}
            vector_iterator& operator-=(difference_type __n)  {*this += -__n; return *this;}
            reference    operator[](difference_type __n) const  { return ptr[__n]; }
            
            ~vector_iterator()
            {
            }
        private:
            pointer  ptr;
    };

        template < typename T>// if const_iterator will replace T by const T (const int , const double...)

            class const_vector_iterator  
            {
                
                public:
                    typedef T                                                                       iterator_type;
                    typedef typename iterator_traits<iterator_type>::iterator_category              iterator_category;
                    typedef typename iterator_traits<iterator_type>::value_type                     value_type;
                    typedef typename iterator_traits<iterator_type>::difference_type                difference_type;
                    typedef typename iterator_traits<iterator_type>::pointer                        pointer;
                    typedef typename iterator_traits<iterator_type>::reference                      reference;
                    
                //default constructor
                const_vector_iterator() : ptr(0) {}

                // copy constructor
                const_vector_iterator(const const_vector_iterator & __x): ptr(__x.ptr){}

                template<typename U>
                const_vector_iterator(const vector_iterator<U> & __x): ptr(__x.ptr){}

                // copy assignement overloding
                const_vector_iterator& operator=(const const_vector_iterator& __x)
                {
                    if (this != &__x)
                        ptr = __x.ptr;
                    return *this;
                }   
    
                const_vector_iterator(pointer p) : ptr(p) {}
    
                // operators
                iterator_type base() const  {return ptr;}
                reference operator*() const {   return *ptr;    }
                pointer  operator->() const {   return *ptr;    } // ?
                const_vector_iterator & operator++(){  ++ptr;  return *this; }
                const_vector_iterator  operator++(int) {const_vector_iterator __tmp(*this); ++(*this); return __tmp;}
                const_vector_iterator& operator--()  {  --ptr; return *this; }
                const_vector_iterator  operator--(int)  {const_vector_iterator __tmp(*this); --(*this); return __tmp;}
                const_vector_iterator  operator+ (difference_type __n) const  {const_vector_iterator __w(*this); __w += __n; return __w;}
                const_vector_iterator& operator+=(difference_type __n) { ptr += __n;return *this;}
                const_vector_iterator  operator- (difference_type __n) const  {return *this + (-__n);}
                const_vector_iterator& operator-=(difference_type __n)  {*this += -__n; return *this;}
                reference    operator[](difference_type __n) const  { return ptr[__n]; }
                
                ~const_vector_iterator()
                {
                }
            private:
                pointer  ptr;
        };

     
        template <class _Iter1, class _Iter2> // for compar const iterator with iterator

        bool operator==(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        {
            return __x.base() == __y.base();
        }

        template <class _Iter1, class _Iter2>

        bool operator<(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        { 
            return __x.base() < __y.base();
        }

        template <class _Iter1, class _Iter2>

        bool operator!=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        {
            return !(__x == __y);
        }

        template <class _Iter1, class _Iter2>

        bool operator>(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        {
            return __y < __x;
        }

        template <class _Iter1, class _Iter2>

        bool operator>=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        {
            return !(__x < __y);
        }

        template <class _Iter1, class _Iter2>

        bool operator<=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter2>& __y) 
        {
            return !(__y < __x);
        }

        template <class _Iter1>

        bool operator!=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter1>& __y) 
        {
            return !(__x == __y);
        }

        template <class _Iter1>

        bool operator>(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter1>& __y) 
        {
            return __y < __x;
        }

        template <class _Iter1>

        bool operator>=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter1>& __y) 
        {
            return !(__x < __y);
        }

        template <class _Iter1>

        bool operator<=(const vector_iterator<_Iter1>& __x, const vector_iterator<_Iter1>& __y) 
        {
            return !(__y < __x);
        }
}

 
#endif





