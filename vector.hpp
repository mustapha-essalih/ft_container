#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>    // std::copy


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;



namespace ft
{

    template<typename T>
    class vector
    {
        private:
            T * block;
            T * block_copy;
            int vector_size;
            int vector_capacity;
            T tmp;
            std::allocator<T> alloc;
            // std::allocator<T> alloc;
        public:
            vector();
            vector(int n);
            vector(int n, const T & val);
            vector& operator= (const vector& x);
            T & operator[](int index);
            unsigned int size()const;
            unsigned int capacity()const;
            void push_back(const T & val);
            void push_back(const T * val);
            bool empty() const;
            void resize(int n);
            void resize(int n, const T & val);
            void resize(int n, const T * val);
            void reserve (int n);
            ~vector();
    };
    class length_error : public std::exception{
        public:
            const char * what () const throw()
            {
                return "length error";
            }
    };
    class logic_error : public std::exception{
        public:
            const char * what () const throw()
            {
                return "length error";
            }
    };
}

template<typename T>
    
ft::vector<T>::vector()
{
    block = alloc.allocate(0);
    // block_copy = alloc.allocate(0);
    vector_capacity = 0;
    vector_size = 0;
}

template<typename T>
    
ft::vector<T>::vector(int n)
{
    if(n < 0 || n > 2147483647)// check the max size
        throw length_error();
   
    block = alloc.allocate(n );
   
    // block_copy = alloc.allocate(n );
    
    vector_capacity = n;
    vector_size = n;

   
}

template<typename T>
    
ft::vector<T>::vector(int n, const T & val)
{
    if(n < 0 || n > 2147483647)
        throw length_error();
    vector_capacity  = n;
    vector_size = n;
    block = alloc.allocate(n);
    // block_copy = alloc.allocate(n);
    while(n--)
        block[n] = val;
}

template<typename T>
    
ft::vector<T>& ft::vector<T>::operator=(const ft::vector<T>&x)
{
    if(this != &x)
    {
        vector_capacity = x.vector_capacity;
        vector_size = x.vector_size;
        int tmp = vector_capacity;
        while (tmp--)
            block[tmp] = x.block[tmp];
    }
    return *this;
}

template<typename T>

T & ft::vector<T>::operator [] (int index)
{
    if(index < 0 ) // ||  index >=  size of vector
        return tmp;
    return block[index];
}
 
 
template<typename T>

void ft::vector<T>::push_back(const T * val)
{
    if(!val)
        throw logic_error();
}
template<typename T>

void ft::vector<T>::reserve(int n)
{   
    if(n < 0 || n > 2147483647)
        throw length_error();
    if(n > capacity())// 1
    {
        block_copy = alloc.allocate(size());
        
        for (unsigned int i = 0; i < size(); i++)
        {
            block_copy[i] = std::move(block[i]);
        }
        // alloc.deallocate(block,size());
        block = alloc.allocate(n);
        std::swap(block,block_copy);
        alloc.deallocate(block_copy,size());
    }
    vector_size +=1;
    vector_capacity = n;
}

template<typename T>

unsigned int ft::vector<T>::size()const
{
    return vector_size;
}
template<typename T>

unsigned int ft::vector<T>::capacity()const
{
    return vector_capacity;
}
 
template<typename T>

void ft::vector<T>::push_back(const T & val)
{
    if(empty())
    {
        block = alloc.allocate(1);
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
        block_copy = alloc.allocate(size());
        for (unsigned int i = 0; i < size(); i++)
        {
            block_copy[i] = std::move(block[i]);
        }
        alloc.deallocate(block,size());
        block = alloc.allocate(capacity());
        for (unsigned int i = 0; i < size(); i++)
        {
            block[i] = std::move(block_copy[i]);
        }
        alloc.deallocate(block_copy,size());
        block[vector_size] = val;
        vector_size++; 
    }
    
    
}
 
template<typename T>

bool ft::vector<T>::empty()const
{
    return (vector_size == 0) ? true : false; 
}
 

template<typename T>

void ft::vector<T>::resize(int n) 
{
    if(n < 0 || n > 2147483647)
        throw length_error();

    block_copy = alloc.allocate(size());
    for (unsigned int i = 0; i < size(); i++)
    {
        block_copy[i] = std::move(block[i]);
    }
    alloc.deallocate(block,size());
    block = alloc.allocate(n);
    for (unsigned int i = 0; i < n; i++)
    {
        block[i] = std::move(block_copy[i]);
    }
    alloc.deallocate(block_copy,size());
    vector_size = n;
    vector_capacity = n;
}
 

template<typename T>

void ft::vector<T>::resize(int n,const T * val)
{
    if(!val)
        throw logic_error();
} 

// fix erroe in resize
template<typename T>

void ft::vector<T>::resize(int n,const T & val)
{
    int  i;

    if(n < 0 || n > 2147483647)
        throw length_error();
    
    block_copy = alloc.allocate(size());
    
    i = 0;
    while(i < size())
    {
        block_copy[i] = std::move(block[i]);
        i++;
    }
    alloc.deallocate(block,size());
    block = alloc.allocate(n);
    i = 0;
    
    while(i < size())
    {
        block[i] = std::move(block_copy[i]);
        i++;
    }
    while(i < n)
    {
        block[i] = val;
        i++;
    }
    alloc.deallocate(block_copy,size());
    vector_size = n;
    vector_capacity = n;
} 

template<typename T>

ft::vector<T>::~vector()
{
    alloc.deallocate(block,vector_size);
}



#endif