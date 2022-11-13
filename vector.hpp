#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>     


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
        private:
            T * block;
            T * block_copy;
            size_t vector_size;
            size_t vector_capacity;
            A _alloc;
            T tmp;
            
            
        public:
        
        typedef  A allocator_type;
        typedef typename allocator_type::value_type      value_type;// the data entred by user

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;

        typedef typename allocator_type::pointer         iterator;
        typedef typename allocator_type::const_pointer   const_iterator;

        
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
            _alloc.construct(block,val);
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
                vector_capacity = vector_capacity * 2;//2
                block_copy = _alloc.allocate(size());
                for (size_type i = 0; i < size(); i++)
                {
                    block_copy[i] = std::move(block[i]);
                }
                _alloc.deallocate(block,size());
                block = _alloc.allocate(capacity());
                for (size_type i = 0; i < size(); i++)
                {
                    block[i] = std::move(block_copy[i]);
                }
                _alloc.deallocate(block_copy,size());
                block[vector_size] = val;
                vector_size++; 
            }
        }
        ~vector()
        {

        }
    };
}

    
 


#endif