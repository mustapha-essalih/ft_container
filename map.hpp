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
#include "avl.hpp"
 

namespace ft
{
    template< class Key, class T, class Compare = std::less<Key> , class Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
        public:


            typedef Key                                             key_type;
            typedef T										        mapped_type;
            typedef ft::pair<const Key, T>                          value_type;
            typedef Compare                                         key_compare;
            typedef Allocator                                       allocator_type;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef size_t                                          size_type;
            typedef typename avl<value_type,size_type,pointer,allocator_type>::iterator iterator;// create typename

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                protected:
                    Compare comp;
                    value_compare (Compare c) : comp(c) {}  // constructed with tree's comparison object
                public:
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };


            map():avl()
            {
                size_ = 0;  
            }   

            size_type size()
            {
                return size_;
            }

/*
return a pair, with its member pair::first set to an iterator pointing to either the 
newly inserted element or to the element with an equivalent key in the map. 
The pair::second element in the pair is set to true if a new element was inserted or 
false if an equivalent key already existed.
*/
            ft::pair<iterator, bool> insert(const value_type & val)
            {
                typedef ft::pair<iterator, bool> pr;

                if(size_ == 0)
                {
                    avl.insert(val);        
                    size_++;
                    return pr(begin(),true);
                }
                else
                { 
                    avl.tmp = avl.find(avl.root,val);
                    if(avl.tmp)
                        return pr(avl.tmp,false); 
                }
                size_++;
                avl.insert(val);
                iterator it(avl.find(avl.root,val));
                return pr(it,true);
            }
            
            iterator insert (iterator position, const value_type& val)
            {
                ft::pair<iterator, bool> res = insert(val);
                
                if (res.second) 
                    return res.first;
                else
                    return end();
            }
             

            template <class InputIterator>  void insert (InputIterator first, InputIterator last)
            {
                for(; first != last; ++first)
                {
                    insert(*first);
                }
            }
            iterator begin()
            {
                return iterator(avl.minValue(avl.root));
            }
            iterator end()
            {
                return iterator(avl.end_node,0);
            }
            ~map()
            {
            }
            
            friend class avl;// A friend class in C++ can access the private and protected members of the class in which it is declared as a friend. 
        private:
            typedef avl<value_type,size_type,value_type,allocator_type>        avl_data_struct;
            avl_data_struct  avl;
            allocator_type alloc;
            size_type size_;
 
    };

} 










#endif
  