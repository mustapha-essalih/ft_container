#ifndef VECTOR_HPP
#define VECTOR_HPP


#include "iterator.hpp"
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
    template < typename T, typename A = std::allocator<T>>
    class vector
    {
        
        public:
        typedef  A allocator_type;
        typedef typename allocator_type::value_type      value_type;// the data entred by user

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;

        // we use typename with member types


// const_iterators don't allow you to change the values that they point to, regular iterators do.



        typedef  ft::iterator<value_type>iterator;
        typedef  ft::iterator<const T>const_iterator;

        
        // if pass alloactor call the allocator if not passed an allocetor will enter to default constructor is optonal
        vector(const allocator_type& alloc = allocator_type())// by this syntax we call a default constructor of another class 
        {
            vector_size = 0;
            vector_capacity = 0;
            _alloc = alloc;
        }
        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        {
            // if no value entered wil return 0 val = 0
            vector_size = n;
            vector_capacity = n;
            _alloc = alloc;
            block = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(block + i,val);
        }
    // template <class InputIterator>         vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());
        vector (const vector& x)
        {
            vector_size = x.vector_size;
            vector_capacity = x.vector_capacity;
            _alloc = x._alloc;
            for (size_type i = 0; i < vector_size; i++)
                this->block[i] = x.block[i];
        }
        vector& operator= (const vector& x)
        {
            if(this != &x)
            {
                vector_size = x.vector_size;
                vector_capacity = x.vector_capacity;
                _alloc = x._alloc;
                for (size_type i = 0; i < vector_size; i++)
                    this->block[i] = x.block[i];
            }
            return *this;

        }
        size_type size() const
        {
            return vector_size;
        }
        size_type capacity() const
        {
            return vector_capacity;
        }
        bool empty()const
        {
            return (vector_size == 0) ? true : false; 
        }
        void push_back (const value_type& val)
        {
            if(empty())
            {
                block = _alloc.allocate(1);
                block[vector_size] = val;
                vector_size++; 
                vector_capacity++; 
            }
            else if(vector_size < vector_capacity)
            {
                block[vector_size] = val;
                vector_size++;
            }
            else if (vector_size == capacity())
            {
                vector_capacity = (vector_capacity * 2) ;//2
                realloc_(capacity());
                block[vector_size] = val;
                vector_size++; 
            }
        }
        void pop_back()
        {
            _alloc.destroy(&block[size() - 1]);
            --vector_size;
        }
        reference operator[] (size_type n)
        {
           return block[n];
        }
        const_reference operator[] (size_type n) const
        {
            return block[n];
        }
        size_type max_size() const
        {
            return _alloc.max_size();
        }
        void resize (size_type n, value_type val = value_type())
        {
            if(n < size())
            {
                realloc_(n);
                vector_size = n;
            }
            if (n > capacity())
            {
                realloc_(n);
                for (size_type i = size(); i < n; i++)
                    _alloc.construct(block + i,val);
                vector_capacity = n;
                vector_size = n;
            }
            else if (n > size())
            {
                realloc_(n);
                for (size_type i = size(); i < n; i++)
                    _alloc.construct(block + i,val);
                vector_size = n;
            }
        }
        void reserve (size_type n)
        {
            try {
                if(n > capacity())
                {
                   
                   realloc_(n); 
                    
                    if(empty())
                        vector_capacity = n - 1;
                    else
                        vector_capacity = n ;
                    // because if vector is empty capacity incremanet by 1 and if call reserve method will print capacity +1
                }
                
            }   
            catch (const std::length_error& le) {
                std::cerr << "Length error: " << le.what() << '\n';
            }
        }
        iterator begin()
        {
            iterator it(&block[0]);
            return it;
         }
        iterator end()
        {
            iterator it(&block[size()]);
            return it;
        }
        const_iterator begin()const
        {
            const_iterator it(&block[0]);
            return it;
        }
        const_iterator end() const 
        {
            const_iterator it(&block[size()]);
            return it;
        }
        private:
            T * block;
            size_t vector_size;
            size_t vector_capacity;
            A _alloc;
            T tmp;
            
            void realloc_(typename A::size_type s)
            {
                T * block_copy;
                if(!empty())
                {
                    block_copy = _alloc.allocate(capacity());//here in past error of munmap_chunk(): invalid pointer
                    for (size_type i = 0; i < capacity() && i < size(); i++)
                    {
                        _alloc.construct(block_copy + i,block[i]);
                        _alloc.destroy(block + i);
                    }
                    _alloc.deallocate(block,capacity());
                    block = _alloc.allocate(s);
                    for (size_type i = 0; i < size(); i++)
                    {
                        _alloc.construct(block + i,block_copy[i]);
                        _alloc.destroy(block_copy + i);
                    }
                    _alloc.deallocate(block_copy,capacity());
                    // vector_capacity = s;
                }
            }
    };
}

    
 


#endif