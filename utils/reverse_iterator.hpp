#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

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
  
#include "../utils/iterator_traits.hpp"
#include "../map/red_black_tree.hpp"
 
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

namespace ft
{
    template<typename T>// T here is the pair
     
    class reverse_iterator 
    {
        private:
            T _iterator;
            
        public:

            typedef T                                                                       iterator_type;// is the type of container iterator, (i want reverse iterator for map,vector..)
            typedef typename ft::iterator_traits<iterator_type>::iterator_category	        iterator_category;
            typedef typename ft::iterator_traits<iterator_type>::value_type	                value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type	        difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer	                pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference	                reference;


            	 	 		
            reverse_iterator(){} //: _iterator(){}

            reverse_iterator (iterator_type it) : _iterator(it){}// take for examlpe begin()    
             
            reverse_iterator (const reverse_iterator & rev_it) // The copy constructor is normal.
            {
                this->_iterator = rev_it._iterator;
            }
                

            template <class Iter>  
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base()) // ?
            {
            }

            iterator_type base() const
            {
                return _iterator;
            }

            reference operator*() const
            {
                iterator_type tmp = _iterator;
                return *--tmp;
            }
            
            pointer operator->() const
            { return &(operator*()); }
 
       
            reverse_iterator & operator++()
            {
                --_iterator;
                return *this;
            }
            
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --_iterator;
                return tmp;
            }
       
            reverse_iterator & operator--()
            {
                ++_iterator;
                return *this;
            }
            
            reverse_iterator operator--(int)
            {
                reverse_iterator _tmp = *this;
                ++_iterator;
                return _tmp;
            }

            reverse_iterator operator+(difference_type n) const
            { return reverse_iterator(_iterator - n); }

            reverse_iterator& operator+=(difference_type __n)
            {
                _iterator -= __n;
                return *this;
            }
   
            reverse_iterator operator-(difference_type __n) const
            { return reverse_iterator(_iterator + __n); }
          
            reverse_iterator& operator-=(difference_type __n)
            {
                _iterator += __n;
                return *this;
            }
   
            reference  operator[](difference_type __n) const
            { return *(*this + __n); }

            ~reverse_iterator(){}

        };      

        template <class _Iter1, class _Iter2>
        bool operator==(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() == __y.base();
        }

        template <class _Iter1, class _Iter2>
        bool operator<(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() > __y.base();
        }

        template <class _Iter1, class _Iter2>
        bool operator!=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() != __y.base();
        }

        template <class _Iter1, class _Iter2>
        bool operator>(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() < __y.base();
        }

        template <class _Iter1, class _Iter2>
        bool operator>=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() <= __y.base();
        }

        template <class _Iter1, class _Iter2>
        bool operator<=(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __x.base() >= __y.base();
        }
        
        template <class _Iter1, class _Iter2>
        typename reverse_iterator<_Iter1>::difference_type operator-(const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
        {
            return __y.base() - __x.base();
        }
        
        template <class _Iter> reverse_iterator<_Iter>
        operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& __x)
        {
            return reverse_iterator<_Iter>(__x.base() - __n);
        } 

};

 
#endif