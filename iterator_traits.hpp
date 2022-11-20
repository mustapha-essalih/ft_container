#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


// is an interface
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

/*
template <class Iterator>
  struct iterator_traits {
    typedef typename Iterator::value_type        value_type; 
  };

  template <class T>
  struct iterator_traits<T*> {
    // pass to iterator_traits an template class
    typename iterator_traits<std::iterator<std::random_access_iterator_tag,T>>::value_type i = 10;
    iterator_traits()
    {
        cout << i;
    }
  };
*/

namespace ft
{
    
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};


template <class Iterator>
struct iterator_traits
{
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};


template <class T>
struct iterator_traits<T *>
{
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T *>
{
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T *pointer;
    typedef const T &reference;
    typedef random_access_iterator_tag iterator_category;
};



}



#endif