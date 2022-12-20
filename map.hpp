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


namespace ft
{
    template< class Key, class T, class Compare = std::less<Key> , class Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
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

        
        public:
             
            map()
            {
                 
                
                b.insert(ft::make_pair<int,int>(10,20));
                b.insert(ft::make_pair<int,int>(1560,20));
                b.insert(ft::make_pair<int,int>(160,20));
                b.insert(ft::make_pair<int,int>(150,20));

                b.inOrder(b.root);

            
            }

            ~map()
            {
                
            }
        private:
            bst<value_type> b;
            
    };
    
    
 
    
} 










#endif