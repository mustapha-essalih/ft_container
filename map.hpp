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
  
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft
{
    template< typename Key, typename T, typename Compare = std::less<Key> , typename Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
        public:

            ////////////////////
            // map member types //   
            ///////////////////

            typedef Key                                                                                                         key_type;
            typedef T										                                                                    mapped_type;
            typedef ft::pair<const Key, T>                                                                                      value_type;
            typedef Compare                                                                                                     key_compare;
            typedef Allocator                                                                                                   allocator_type;
            typedef typename allocator_type::pointer                                                                            pointer;
            typedef typename allocator_type::const_pointer                                                                      const_pointer;
            typedef typename allocator_type::reference                                                                          reference;
            typedef typename allocator_type::const_reference                                                                    const_reference;
            typedef size_t                                                                                                      size_type;
            typedef ptrdiff_t                                   difference_type;
                
            typedef typename ft::map_iterator<key_type,value_type,key_compare,size_type,allocator_type>                         iterator;
            typedef typename ft::const_map_iterator<key_type,value_type,key_compare,size_type,allocator_type>                   const_iterator;
             
            map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            {
                size_ = 0;
            }

            ft::pair<iterator, bool> insert(const value_type & val)
            {
                typedef ft::pair<iterator, bool> pr;
                
                if(size_ == 0) 
                {
                    tree.insert(val);        
                    size_++;
                    return pr(begin(),true);
                }
                else
                { 
                    tree.tmp = tree.search(tree.root,val.first);
                    if(tree.tmp->data.first == val.first)// if the same val inserted use key comapr
                        return pr(iterator(tree.tmp),false); 
                }
                 
                size_++;
                tree.insert(val);
                iterator it(tree.search(tree.root,val.first));// for search the last element inseted
                return pr(it,true);
            }
            
            
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    ++first;
                }
                insert(*first);
                 
            }

            iterator insert(iterator _where, const value_type& val)// handle this
            {
                ft::pair<iterator, bool> res = insert(val);
                cout << "=================================\n";
                for (iterator it= begin(); it!= end(); ++it)
                    std::cout << it->first << " => " << it->second << '\n';
                cout << "=================================\n";

                // if (res.second) 
                // {
                //     return res.first;
                // }
                // else 
                    return end();
            }
            iterator find (const key_type& k)
            {
                if(size() == 0)
                    return iterator(tree.TNULL,tree.root);
                tree.tmp = tree.search(tree.root,k);
                if(tree.tmp)
                    return iterator(tree.tmp,tree.root);
                return iterator(tree.TNULL,tree.root);
            }
            size_type size() const
            {
                return size_;
            }
            void display()
            {}
            // void insert(const value_type & val)
            // {
            //     tree.insert(val);
            // }
            iterator begin()
            {
                return iterator(tree.minValue(tree.root),tree.root);
            }
            iterator end()
            {
                tree.TNULL->parent = tree.maxValue(tree.root);
                return iterator(tree.maxValue(tree.root)->right,tree.TNULL,tree.minValue(tree.root));
            }
            ~map()
            {
                // clear();
            }
            private:
                typedef RedBlackTree<key_type,value_type,key_compare,size_type,allocator_type> tree_data_struct;
                tree_data_struct tree;
                size_type size_;
                allocator_type alloc;
                key_compare key_compare_;
    };
    

} 










#endif
 