#ifndef MAP_HPP
#define MAP_HPP



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

#include <utility>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::pair;


namespace ft{

template <typename Key, typename T, typename Compare = std::less<Key>,typename Allocator = std::allocator<std::pair<const Key,T> > >

class map
{
    typedef typename std::allocator<T>::value_type value_type;
    typedef typename std::allocator<T>::key_typ key_type;
    // map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
    // {
    //     size = 0;
    // }   
    // template <class InputIterator>  
    // map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
    // {

    // }
    // map (const map& x)
    // {

    // }

    map()
    {
        
    }

    private:
        size_t size;
};


};












#endif