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
    

        vector (const allocator_type& alloc = allocator_type()) // deafult constructor
        {
            vector_size = 0;
            vector_capacity = 0;
            _alloc = alloc;
            block = NULL;
            temp = NULL;
             
        }
    
                                                // default value
        vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) // fill constructor
        {
            temp = NULL;
            vector_size = n;
            vector_capacity = n;
            _alloc = alloc;
            block = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(block + i,val);
        }

        template<typename InputIterator>
        vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) // ?
        {
            difference_type n = last - first;
            if (n > 0)
            {
                block = _alloc.allocate(n);
                for (size_type i = 0; i < n && first != last ; i++)
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
            size_t other_size = x.size();
            if (other_size == 0) {
                // other vector is empty, so create an empty vector
                block = NULL;
                vector_size = 0;
                vector_capacity = 0;
            } 
            else {
                // allocate new memory using the allocator of the original vector
                block = _alloc.allocate(other_size);
                vector_size = other_size;
                vector_capacity = x.capacity();
                for (size_type i = 0; i < vector_capacity; i++) 
                    _alloc.construct(block + i,x.block[i]);
            }
            
        }
        

        vector& operator= (const vector& x)
        {
            if (this != &x) // check for self-assignment
            {
                size_t other_size = x.size();
                
                pointer new_data = _alloc.allocate(other_size);
                for (size_type i = 0; i < other_size; i++) 
                    _alloc.construct(block + i,x.block[i]);
                _alloc.deallocate(block, capacity());

                // update the size, capacity, and data pointers
                block = new_data;
                vector_size = other_size;
                vector_capacity = other_size;   
            }
            return *this;
        }



        void push_back(const value_type& val) 
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
            else if (vector_size == vector_capacity)
            {
                vector_capacity = (vector_capacity * 2) ;//2
                reallocate(vector_capacity);
                block[vector_size] = val;
                vector_size++; 
            }
        }
    
        void reserve(size_type n)
        {
            difference_type newN = static_cast<int>(n);
            if(newN < 0)
                throw throw_out_of_range(); 
             
            if(n > capacity())
            {
                reallocate(n);
                vector_capacity = n;
            }
        }

        void reallocate(size_type new_cap)
        {
            pointer block_copy = _alloc.allocate(new_cap);//here in past error of munmap_chunk(): invalid pointer
            if(block != NULL)// if block is empty cannot copy to block_copy it segfault
            {
                for (size_type i = 0; i < size(); i++) 
                    _alloc.construct(block_copy + i,block[i]);
                
                _alloc.deallocate(block,new_cap);

            }  
            block = _alloc.allocate(new_cap);
            
            for (size_type i = 0; i < new_cap; i++)
                _alloc.construct(block + i,block_copy[i]);            
            _alloc.deallocate(block_copy,new_cap);
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


        template <class InputIterator>  
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            difference_type	n = last - first;
            clear();// if deallocate will double free
            reserve(n);
            for (size_t i = 0; i < n; i++)
            {
                this->_alloc.construct(this->block + i, *first);
                first++;
            }
            this->vector_size = n;
        }
        
        void assign (size_type n, const value_type& val)
        {
            difference_type newN = static_cast<int>(n);
            
            if(newN < 0)
            {
                throw throw_out_of_range();
            }
            if(block)// if not empty
                _alloc.deallocate(block,capacity());
            block = _alloc.allocate(n);// block here is NULL

            for (size_type i = 0; i < n; i++)
                _alloc.construct(block + i, val);
            vector_size = n;
            vector_capacity = n;
        }
        
        void pop_back()
        {
            --vector_size;
            _alloc.destroy(&block[size() - 1]);
        }

        void resize(size_type count, value_type value = value_type())
        {
            if (count < size())
            {
                for (size_t i = count; i < vector_size; i++)
                {
                    _alloc.destroy(block + i);
                }
            }
            else if (count > size())
            {
                if (count > vector_capacity)
                    (count < (capacity() * 2) ? reserve(capacity() * 2) : reserve(count));
                for (size_type i = vector_size; i < count; i++)
                    _alloc.construct(block + i, value);
            }
            vector_size = count;
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

        void clear() 
        {
            for (size_t i = 0; i < this->vector_size; i++)
				this->_alloc.destroy(this->block + i);
            vector_size = 0;
        }


        iterator insert (iterator position, const value_type& val)
        {
            difference_type n = position - begin();
            if (n >= size() || n < 0)// protection
                return end();	// return garbage
            if(size() + 1 > capacity())
            {
                reallocate(vector_size + 1);
                vector_capacity *= 2;// because std when rellocate capacityi is extanded
            }
            for (size_t i = vector_size - 1; i >= n; i--) // swap indexes
            {
                block[i + 1] = block[i];
                if (i == 0)
                    break;
            }
            block[n] = val;
            vector_size++;
            return (begin() + n);
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
             
            difference_type ip = position - begin();
             if(n > capacity())
                return;
            if(vector_size + n >= capacity())
            {
                vector_capacity *= 2;
                reallocate(vector_capacity);
            }
            for (size_type i = vector_size - 1; i >= ip; i--)
            {
                block[i + n] = block[i];
                if (i == 0)
                    break;
            }
            for (size_type i = ip; i < ip + n; i++)
                block[i] = val;
            vector_size += n;
        }
        
         template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            vector<T> tm(first,last);
            
            difference_type len = tm.size();

            difference_type n = position -  begin();

             
            if(this->vector_size + len >= capacity())
            {
                vector_capacity *= 2;
                reallocate(vector_capacity);
            }
            for (int i = this->vector_size - 1; i >= n; i--)
                this->_alloc.construct(this->block + i + len, this->block[i]);
            for (int i = n; i < n + len && first != last; i++)
            {
                this->_alloc.construct(this->block + i, *first);
                this->vector_size++;
                first++;
            }
             

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
       void swap (vector& x)
        {
            std::swap(vector_size,x.vector_size);
            std::swap(vector_capacity,x.vector_capacity);
            std::swap(block,x.block);
        }

        allocator_type  get_allocator() const 
        { 
            return (_alloc); 
        }


        ~vector()
        { 
            if(capacity())
                _alloc.deallocate(block,capacity());
        }

        private:
            allocator_type _alloc;
            size_type vector_size;
            size_type vector_capacity;
            pointer block; // ?
            pointer temp;
             
            class throw_out_of_range : public std::exception
            {
                const char *what() const throw()
                {
                    return "error";
                }
            };

    };

    // enter heare https://cplusplus.com/reference/vector/vector/operators/

    template <class T>  void swap (vector<T>& x, vector<T>& y)
    {
        x.swap(y);
    }
    template <class T>  bool operator== ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }
    template <class T>  bool operator!= ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
       return !(lhs == rhs);
    }
    template <class T>  bool operator<  ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
         return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    template <class T>  bool operator<= ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
        return !(lhs > rhs);
    }
    template <class T>  bool operator>  ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
        return (rhs < lhs);
    }
    template <class T>  bool operator>= ( const vector<T>& lhs,                    const vector<T>& rhs )
    {
        return !(rhs > lhs);
    }
}

     

#endif