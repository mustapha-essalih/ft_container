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
#include "../utils/type_traits.hpp"



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
            typedef ft::vector_iterator<const_pointer>                  const_iterator;// whay using pointer here
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
 

        /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : constructors
        /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

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

        template<typename InputIterator>
        vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) // ?
        {
            difference_type n = last - first;
            if (n > 0)
            {
                this->block = this->_alloc.allocate(n);
                for (size_t i = 0; i < n && first != last ; i++)
                {
                    this->_alloc.construct(this->block + i, *first);
                    first++;
                }
                this->vector_size = n;
                this->vector_capacity = n;
            }
            else
            {
                this->vector_size = 0;
                this->vector_capacity = 0;
            }
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
        
        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : copy assignement ovelrloading
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector: Iterators
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vactor : Modifiers
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
            --vector_size;
            _alloc.destroy(&block[size() - 1]);
        }

         
        iterator insert(iterator position, const value_type &val)
        {
            if(empty())
            {
                block = _alloc.allocate(1);
                block[vector_size] = val;
                vector_size++; 
                vector_capacity++; 
                return iterator(&block[0]);
            }
            difference_type index = position - begin(); 
            if(index < 0) 
                return iterator(end());
            difference_type j = size(); 
            if (size() < capacity())
            {
                while (j >= 0)
                {   
                    // here replace 
                    if (j == index)
                    {
                        _alloc.construct(&block[j], val);
                        vector_size++;
                        return iterator(begin() + index);
                    }
                    else
                        _alloc.construct(&block[j], block[j - 1]);
                    j--;
                }
            }
            else if (vector_size == capacity())
            {
                vector_capacity = (vector_capacity * 2) ;//2
                realloc_(capacity());
                while (j >= 0)
                {   
                    // here replace 
                    if (j == index)
                    {
                        _alloc.construct(&block[j], val);
                        vector_size++;
                        return iterator(begin() + index);
                    }
                    else
                        _alloc.construct(&block[j], block[j - 1]);
                    j--;
                }
            }
            vector_size++;
            return iterator(begin() + index);
        }  
        
        void insert (iterator position, size_type n, const value_type& val)
        {
            difference_type d = static_cast<difference_type>(n); // because n is unsigned int and whrn pass - will overflow
            if (d < 0)
                throw std::out_of_range("out_of_range\n");
            
            while (n > 0)
            {
                insert(position, val);
                n--;
            }
        }
    
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            difference_type len = last - first;
            if (len <= 0)
                return ;
            difference_type n = position - this->begin();
            vector tmp(this->begin(), this->end());
            try
            {
                reserve(this->vector_size + len);
                for (int i = this->vector_size - 1; i >= n; i--)
                    this->_alloc.construct(this->block + i + len, this->block[i]);
                for (int i = n; i < n + len && first != last; i++)
                {
                    this->_alloc.construct(this->block + i, *first);
                    this->vector_size++;
                    first++;
                }
            }
            catch (...)
            {
                *this = tmp;
                throw ;
            }
        }

        template <class InputIterator>  
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            difference_type	n = last - first;
            block = _alloc.allocate(n);// block here is NULL
            
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(block + i, *first);
                first++;
            }
            this->vector_size = n;
        }

        void assign (size_type n, const value_type& val)
        {
            block = _alloc.allocate(n);// block here is NULL

            for (size_type i = 0; i < n; i++)
                _alloc.construct(block + i, val);
            this->vector_size = n;

        }

        iterator erase (iterator position)
        {
            difference_type n = position - begin();
            for (size_t i = n; i < vector_size; i++)
                block[i] = block[i + 1];
            _alloc.destroy(block + (vector_size - 1));
            vector_size--;
            return (position);
        }

        iterator erase (iterator first, iterator last)
        {
            difference_type n = first - begin();
            difference_type diff = last - first;
            for (size_t i = n; i + diff < vector_size; i++)
            {
                _alloc.destroy(block + i);
                _alloc.construct(block + i, block[i + diff]);
            }
            for (size_t i = vector_size - 1; i >= vector_size - diff; i--)
            {
                _alloc.destroy(block + i);
                if (i == 0)
                    break;
            }
            vector_size -= diff;
            return (first);
        }

        void clear()
        {
            _alloc.deallocate(block,vector_capacity);
            vector_size = 0;
            vector_capacity = 0;
            
        }

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : Capacity
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
                for (size_type i = n; i < size(); ++i)
                    _alloc.destroy(&block[i]);
            }
            if (n > capacity())
            {
                vector_capacity = n;
                vector_size = n;
                realloc_(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(block + i,val);
            }
            else if (n > size())
            {
                vector_capacity = n;
                vector_size = n;
                realloc_(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(block + i,val);
             }
        }

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector: Element access
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        reference front()
        {
            if(empty())
                return *(begin());
            return *(begin());
        }
        const_reference front() const
        {
            if(empty())
                return *(begin());
            return *(begin());
        }
        reference back()
        {
            return *(this->end() - 1);
        }
        const_reference back() const
        {
            return *(this->end() - 1);
        }
        // front	Access first element (public member function)
        // back	Access last element (public member function)


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void swap (vector& x)
        {
            // pointer	tmp = x.block;
            size_t xSize = x.vector_size;
            size_t xCapacity = x.vector_capacity;

            std::swap(x.block,this->block);
            x.vector_capacity = this->vector_capacity;
            x.vector_size = this->vector_size;
            // block = tmp;
            vector_capacity = xCapacity;
            vector_size = xSize;
        }

        allocator_type  get_allocator() const 
        { 
            return (_alloc); 
        }
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
            pointer block; // ?

            void realloc_(typename A::size_type s)
            {
                pointer block_copy;
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

    // enter heare https://cplusplus.com/reference/vector/vector/operators/

    template<typename T, typename Allocator>
    bool operator == (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;

        ft::vector<T> it1 = lhs.begin();
        ft::vector<T> it2 = rhs.begin();

        while (it1 != lhs.end())
        {
            if (*it1 != *it2)
                return false;

            ++it1;
            ++it2;
        }

        return true;
    }

    template<typename T, typename Allocator>
    bool operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(lhs == rhs);
    }

    template<typename T, typename Allocator>
    bool operator < (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        ft::vector<T> it1 = lhs.begin();
        ft::vector<T> it2 = rhs.begin();

        while (it1 != lhs.end() && it2 != rhs.end())
        {
            if (*it1 < *it2)
                return true;

            if (*it2 < *it1)
                return false;

            ++it1;
            ++it2;
        }

        return lhs.size() < rhs.size();
    }

    template<typename T, typename Allocator>
    bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return rhs < lhs;
    }

    template<typename T, typename Allocator>
    bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(lhs > rhs);
    }

    template<typename T, typename Allocator>
    bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}

     

#endif


    