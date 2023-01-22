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
 
#include "avl.hpp"
#include "iterator.hpp"

namespace ft
{
    template< typename Key, typename T, typename Compare = std::less<Key> , typename Allocator = std::allocator<std::pair<const Key, T> > >
 
    class map
    {
        public:

            ////////////////////
            // map member types //   
            ///////////////////

            typedef Key                                                                                                 key_type;
            typedef T										                                                            mapped_type;
            typedef std::pair<const Key, T>                                                                              value_type;
            typedef Compare                                                                                             key_compare;
            typedef Allocator                                                                                           allocator_type;
            typedef typename allocator_type::pointer                                                                    pointer;
            typedef typename allocator_type::const_pointer                                                              const_pointer;
            typedef typename allocator_type::reference                                                                  reference;
            typedef typename allocator_type::const_reference                                                            const_reference;
            typedef size_t                                                                                              size_type;
        
            typedef typename ft::map_iterator<key_type,value_type,key_compare,size_type,mapped_type,allocator_type>                 iterator;
            // typedef typename ft::const_map_iterator<key_type,value_type,key_compare,size_type,allocator_type>           const_iterator;
            // typedef typename ft::reverse_iterator<iterator>                                                             reverse_iterator;

            
            map(){}

            void insert(const value_type& val)
            {
                avl.insert(val);
            }
            
            void erase(key_type k)
            {
                avl.deleteNode(k);
            }
            
            iterator begin()
            {
                constNode<key_type,mapped_type> non_const = avl.returnConst();
                return iterator(&non_const);
            }
            ~map()
            {

            }
            private:
                typedef avl<key_type,value_type,key_compare,size_type,mapped_type,allocator_type> avl_data_strcut;
                avl_data_strcut avl;
                size_type size_;
                allocator_type alloc;
                
    };
    

} 










#endif