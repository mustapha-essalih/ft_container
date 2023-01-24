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

            
            map(){}

            void insert(const value_type& val)
            {
                tree.insert(val);
            }
             
            iterator begin()
            {
                tree.root->parent = tree.end_node;
                tree.end_node->left = tree.root;
                 
                return iterator (tree.minValue(tree.root));
            
                 
            }
            iterator end()
            {
                return iterator (tree.end_node,tree.end_node,tree.root);
            }
 

            ~map()
            {

            }
            private:
                typedef RBTree<key_type,value_type,key_compare,size_type,mapped_type,allocator_type> red_black_tree_;
                red_black_tree_ tree;
                size_type size_;
                allocator_type alloc;
                
    };
    

} 
 

#endif