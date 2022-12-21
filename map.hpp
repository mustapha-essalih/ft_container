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

#include "type_traits.hpp"
#include "bst.hpp"
#include "iterator.hpp"


namespace ft
{
    template< class Key, class T, class Compare = std::less<Key> , class Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
 
        public:

                typedef  Key key_type; 
                typedef  T mapped_type;
                        //    because key will not duplicate or chande key value
                typedef  ft::pair<const key_type,mapped_type> value_type;

                typedef  std::less<key_type> key_compare;
                typedef     Allocator  allocator_type;
                typedef typename allocator_type::reference	reference;
                typedef typename allocator_type::const_reference		const_reference;
                typedef typename allocator_type::pointer	pointer;
                typedef typename allocator_type::const_pointer	const_pointer;
                typedef typename allocator_type::size_type       size_type;


                typedef   ft::iterator<value_type>  iterator;
             
            map()
            {
                the_size = 0;
                b.insert(ft::make_pair<key_type,mapped_type>(10,254));
                b.insert(ft::make_pair<key_type,mapped_type>(11,24));
                b.insert(ft::make_pair<key_type,mapped_type>(9,2555));
                b.insert(ft::make_pair<key_type,mapped_type>(8,202));
                b.insert(ft::make_pair<key_type,mapped_type>(7,2979));
                b.insert(ft::make_pair<key_type,mapped_type>(12,60));
             	 

            }
            bool empty() const
            {
                if(the_size == 0)
                    return true;
                return false;
            }

            size_type size() const
            {
                the_size++;
                return the_size;
            }
            
            iterator begin()
            {
                
                iterator i(b.minValue(b.root)->value);

                return i;
            }
            
            iterator end()
            {
                b.n = b.findSuccessor(b.maxValue(b.root),b.endOf(b.root));
                
                iterator i(b);
                return i;
            }
            ~map()
            {
                
            }
        private:
            bst<value_type> b;
            size_type the_size;
    };
    
    
 
    
} 










#endif