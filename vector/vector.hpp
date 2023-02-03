#ifndef VECTOR_HPP
#define VECTOR_HPP


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

#include "../vector/vector_iterator.hpp"
#include "../utils/reverse_iterator.hpp"

namespace ft
{
    template < typename T, typename A = std::allocator<T> >
    class vector
    {
        // search for allocator member types
        public:

            typedef T                                                   value_type;
            typedef A                                                   allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::size_type                  size_type;
            typedef typename allocator_type::difference_type            difference_type;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            
            typedef ft::vector_iterator<pointer>                        iterator;// whay using pointer here
            typedef ft::const_vector_iterator<const_pointer>            const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;


        /*
            vector : constructors
        */

        vector (const allocator_type& alloc = allocator_type())
        {
            vector_size = 0;
            vector_capacity = 0;
            _alloc = alloc;
            block = NULL;

        }
        
                                                // template initialize value
        vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
        {
            vector_size = n;
            vector_capacity = n;
            _alloc = alloc;
            this->block = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(block + i,val);
        }

        template <class InputIterator>         
        vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())// ?
        {

        }

        vector (const vector& x)
        {
            vector_size = x.vector_size;
            vector_capacity = x.vector_capacity;
            _alloc = x._alloc;
            this->block = _alloc.allocate(vector_size);
            for (size_type i = 0; i < vector_size; i++) // deep copy
                _alloc.construct(this->block+i,x.block[i]);
        }
        
        /*
            vector : copy assignement ovelrloading
        */

        vector& operator= (const vector& x)
        {
            if(this != &x) // if pass the same obj
            {
                vector_size = x.vector_size;
                vector_capacity = x.vector_capacity;
                _alloc = x._alloc;
                this->block = _alloc.allocate(vector_size);
                for (size_type i = 0; i < vector_size; i++) // deep copy
                    _alloc.construct(this->block+i,x.block[i]);
                 
            }
            return *this;
        }

        /*
            vector: Iterators
        */

        iterator begin()
        {
            return iterator (&block[0]);
        }
        iterator end()
        {
            return iterator (&block[size()]);
        }
        const_iterator begin() const
        {
            return const_iterator (&block[0]);
        }
        const_iterator end() const
        {
            return const_iterator (&block[size()]);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());// pointing to the last element 
        }
        reverse_iterator rend()
        {
            return reverse_iterator (begin());// pointing to the before first elemnt
        }
        const_reverse_iterator rbegin() const
        {
            return reverse_iterator (end());// pointing to the last element 
        }
        const_reverse_iterator rend() const
        {
            return reverse_iterator (begin());// pointing to the before first elemnt
        }
        /*
            vactor : Modifiers
        */


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

        /*
            vector : Capacity
        */

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
        size_type max_size() const
        {
            return _alloc.max_size();
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
        /*
            vector: Element access
        */

        reference operator[] (size_type n)
        {
           return block[n];
        }
        const_reference operator[] (size_type n) const
        {
            return block[n];
        }
        reference at (size_type n)
        {
            if(n >= size())
                throw throw_out_of_range();
            return block[n];
        }
        const_reference at (size_type n) const
        {
            if(n >= size())
                throw throw_out_of_range();
            return block[n];
        }
        // front	Access first element (public member function)
        // back	Access last element (public member function)
 
        ~vector()
        {
            _alloc.deallocate(block,vector_capacity);
            vector_size = 0;
            vector_capacity = 0;
        }

        private:
            allocator_type _alloc;
            size_type vector_size;
            size_type vector_capacity;
            value_type * block;

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
            class throw_out_of_range : public std::exception
            {
                const char *what() const throw()
                {
                    return "vector";
                }
            };
    
    };
}

     

#endif


    