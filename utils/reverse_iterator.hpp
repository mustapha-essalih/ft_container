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


            	 	 		
            reverse_iterator() : _iterator(){}

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

        template <class Iterator>  
        bool operator== (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
        {
            return lhs.base() == rhs.base();
        }

        template <class Iterator>  
        bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
        {
            return !(lhs == rhs);
        }
        
        template <class Iterator>  
        bool operator<  (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
        {
            return rhs.base() < lhs.base();
        }
 	
        template <class Iterator>  
        bool operator<= (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
        {
            return !(rhs < lhs);
        }
 	
        template <class Iterator> 
        bool operator>  (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
        {
            return rhs > lhs;
        }

        template <class Iterator>  
        bool operator>= (const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
        {
            return !(lhs < rhs);
        }

        // template<typename T>// T here is the pair
        // class const_reverse_iterator 
        // {
        //     private:
        //         T _iterator;
                
        //     public:

        //         typedef T                                                                       iterator_type;// is the type of container iterator, (i want reverse iterator for map,vector..)
        //         typedef typename ft::iterator_traits<iterator_type>::iterator_category	        iterator_category;
        //         typedef typename ft::iterator_traits<iterator_type>::value_type	                value_type;
        //         typedef typename ft::iterator_traits<iterator_type>::difference_type	        difference_type;
        //         typedef typename ft::iterator_traits<iterator_type>::pointer	                pointer;
        //         typedef typename ft::iterator_traits<iterator_type>::reference	                reference;


                                
        //         const_reverse_iterator() : _iterator(){}

        //         const_reverse_iterator (iterator_type it) : _iterator(it){}// take for examlpe begin()    
                
        //         const_reverse_iterator (const const_reverse_iterator & rev_it) // The copy constructor is normal.
        //         {
        //             this->_iterator = rev_it._iterator;
        //         }

        //         template <class Iter>  
        //         const_reverse_iterator (const const_reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base()) // ?
        //         {
        //         }

        //         iterator_type base() const
        //         {
        //             return _iterator;
        //         }

        //         reference operator*() const
        //         {
        //             iterator_type tmp = _iterator;
        //             return *--tmp;
        //         }
                
        //         pointer operator->() const
        //         { return &(operator*()); }
    
        
        //         const_reverse_iterator & operator++()
        //         {
        //             --_iterator;
        //             return *this;
        //         }
                
        //         const_reverse_iterator operator++(int)
        //         {
        //             const_reverse_iterator tmp = *this;
        //             --_iterator;
        //             return tmp;
        //         }
        
        //         const_reverse_iterator & operator--()
        //         {
        //             ++_iterator;
        //             return *this;
        //         }
                
        //         const_reverse_iterator operator--(int)
        //         {
        //             const_reverse_iterator _tmp = *this;
        //             ++_iterator;
        //             return _tmp;
        //         }

        //         const_reverse_iterator operator+(difference_type n) const
        //         { return const_reverse_iterator(_iterator - n); }

        //         const_reverse_iterator& operator+=(difference_type __n)
        //         {
        //             _iterator -= __n;
        //             return *this;
        //         }
    
        //         const_reverse_iterator operator-(difference_type __n) const
        //         { return const_reverse_iterator(_iterator + __n); }
            
        //         const_reverse_iterator& operator-=(difference_type __n)
        //         {
        //             _iterator += __n;
        //             return *this;
        //         }
    
        //         const reference  operator[](difference_type __n) const
        //         { return *(*this + __n); }

        //         ~const_reverse_iterator(){}

        //     };     

};

 
#endif