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

#include "vector_iterator.hpp"
#include "../utils/iterator_traits.hpp"
#include "../utils/type_traits.hpp"
#include "../utils/reverse_iterator.hpp"



namespace ft
{
    template < typename T, typename A = std::allocator<T> >
    class vector
    {
        public:

            typedef T                                                   value_type;
            typedef A                                                   allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::size_type                  size_type;
            typedef typename allocator_type::difference_type            difference_type;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            
            typedef ft::vector_iterator<pointer>                        iterator;
            typedef ft::vector_iterator<const_pointer>                  const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
 

        /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : constructors
        /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    

        vector (const allocator_type& alloc = allocator_type()) // deafult constructor
        {
            vector_size = 0;
            vector_capacity = 0;
            _alloc = alloc;// here we create obj and initialize my alloc to can use for allocate and construct and destroy if not do that will cannot use function of alloc...
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

        template<typename InputIterator> //    reange of elements
        vector(InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            
            difference_type n = last - first;
            if (n > 0)
            {
                block = _alloc.allocate(n);
                for (difference_type i = 0; i < n && first != last ; i++)
                {
                    _alloc.construct(block + i, *first);
                    first++;
                }
                vector_size = n;
                vector_capacity = n;
            }
            else
            {
                vector_size = 0;
                vector_capacity = 0;
            }
            // (void)alloc;
            _alloc = alloc;
        }
        
        // copy constructor
        vector (const vector& x)
        {
            vector_capacity = x.vector_capacity;
            vector_size = x.vector_size;
            block = _alloc.allocate(x.vector_size);
            for(size_t i = 0;i < x.vector_size;i++)
            {
                _alloc.construct(block+i,x.block[i]);
            }
        }
        
        // copy assignement overloading
        vector& operator= (const vector& x)
        {
            if (this != &x) 
            {
                clear();
                _alloc.deallocate(block,vector_capacity);
                vector_capacity = x.vector_capacity;
                vector_size = x.vector_size;
                block = _alloc.allocate(x.vector_size);
                for(size_t i = 0;i < x.vector_size;i++)
                    _alloc.construct(block+i,x.block[i]);
            }
            return *this;
        }

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //  vecor : Iterators
        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
            return _alloc.max_size();//returns the maximum number of elements that can be allocated by the allocator
        }

        void resize (size_type n, value_type val = value_type())
        {
            if (n < size())
            {
                for (size_t i = n; i < vector_size; i++)
                    _alloc.destroy(block + i);
            }
            else if (n > size())
            {
                if (n > vector_capacity)
                {
                    vector_capacity *= 2;
                    reallocate(vector_capacity);
                }
                for (size_type i = vector_size; i < n; i++)
                    _alloc.construct(block + i, val);
            }
            vector_size = n;
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
        
        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : Element access
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
            return *(end() - 1);
        }
        const_reference back() const
        {
            return *(end() - 1);
        }

        /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            vector : Modifiers
        *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        void push_back (const value_type& val)
        {
            if (vector_capacity == vector_size)
            {
                pointer tmp = _alloc.allocate(vector_capacity);
                for (size_t i = 0; i < vector_capacity; i++)
                    _alloc.construct(tmp+i,block[i]);
                _alloc.deallocate(block,vector_capacity);
                
                vector_capacity *= 2;
                if(vector_capacity == 0)// if empty
                    vector_capacity++;
                block = _alloc.allocate(vector_capacity);
                for (size_t i = 0; i < vector_size; i++)
                    _alloc.construct(block+i,tmp[i]);
                _alloc.construct(block+vector_size,val);
                _alloc.deallocate(tmp,vector_capacity);// 
            }
            else // if capacty is greter then size()
                block[vector_size] = val;
            vector_size++;
        }

        void pop_back()
        {
            --vector_size;
            _alloc.destroy(&block[size() - 1]);
        }

        template <class InputIterator>  
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            difference_type	n = last - first;
            if(block)// if not empty
                _alloc.deallocate(block,capacity());
            block = _alloc.allocate(n);// block here is NULL
            for (difference_type i = 0; i < n; i++)
            {
                this->_alloc.construct(this->block + i, *first);
                first++;
            }
            vector_size = n;
            if(n > vector_capacity) // like std
                vector_capacity = n;
             
        }
        // replaces the contents of the vector with a new set of elements.
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
            if(n > vector_capacity)// because when  first.assign(6,10); first.assign(5,10); in first capacity 6 
                vector_capacity = n;
        }


        iterator insert (iterator position, const value_type& val)
        {
            difference_type pos = position - begin();
            if (pos >= (difference_type)size() || pos < 0)// protection
                return end();	// return garbage
            if(size() + 1 > capacity())
            {
                vector_capacity *= 2;// because std when rellocate capacityi is extanded
                reallocate(vector_capacity);
            }
            for (difference_type i = vector_size - 1; i >= pos; i--) // swap indexes
            {
                block[i + 1] = block[i];
                if (i == 0)
                    break;
            }
            block[pos] = val; // insert 
            vector_size++;
            return (begin() + pos); // An iterator that points to the first of the newly inserted elements.
        }

        void insert (iterator position, size_type n, const value_type& val)
        {
            difference_type newN = static_cast<int>(n);
            if( newN < 0)
                return;
             
            difference_type pos = position - begin();
            if(size() + n > capacity())
            {
                vector_capacity += n;
                reallocate(vector_capacity);
            }
            for (size_type i = vector_size - 1; i >= (size_type)pos; i--)
            {
                block[i + n] = block[i];
                if (i == 0)
                    break;
            }
            for (size_type i = pos; i < (size_type)pos + n; i++)
                block[i] = val;
            vector_size += n;
            
        }
        
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            vector<T> tm; //  range
            InputIterator f = first;
            while (f != last)
            {
                tm.push_back(*f);
                f++;
            }
            
            difference_type len = tm.size();

            difference_type pos = position -  begin();
            
            if(vector_size + len >= capacity())
            {
                vector_capacity *= 2;
                reallocate(vector_capacity);
            }
            for (int i = vector_size - 1; i >= pos; i--)
                _alloc.construct(block + i + len, block[i]);
            for (int i = pos; i < pos + len && first != last; i++)
            {
                _alloc.construct(block + i, *first);
                vector_size++;
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

        void clear() 
        {
            vector_size = 0;
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
            _alloc.deallocate(block,capacity());
        }

        private:
            allocator_type _alloc;
            size_type vector_size;
            size_type vector_capacity;
            pointer block; 
            pointer temp;
             
            class throw_out_of_range : public std::exception
            {
                const char *what() const throw()
                {
                    return "error";
                }
            };

        void reallocate(size_type new_cap)
        {
            pointer block_copy = _alloc.allocate(new_cap);
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
    };

   

    template <class T>  void swap (vector<T>& x, vector<T>& y) // exchange vector by vector in deference type
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


 