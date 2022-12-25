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

                /// handle if have one element
                // a.insert(ft::make_pair<key_type,mapped_type>(60,800));
                // a.insert(ft::make_pair<key_type,mapped_type>(20,14));
                // a.insert(ft::make_pair<key_type,mapped_type>(80,20));
                // a.insert(ft::make_pair<key_type,mapped_type>(90,926));
                // a.insert(ft::make_pair<key_type,mapped_type>(19,87));
                // a.insert(ft::make_pair<key_type,mapped_type>(90,12));
                // a.insert(ft::make_pair<key_type,mapped_type>(100,84));




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
            pair<iterator,bool> insert (const value_type& val)
            {
                // first iteret to tree nd check if element is insted or not 
                if(a.empty())
                {
                    iterator it;
                    a.insert(val);
                    it = begin();
                    return ft::make_pair<iterator,bool>(it,true);
                }
                else
                {
                    iterator it = begin();
 
                    for(;it != end(); ++it)
                    {
                       
                        if(it.node->data.first == val.first)
                        {
                            cout << (*it).first<< endl;
                            return ft::make_pair<iterator,bool>(it,false);
                        }
                    }
                    a.insert(val);
                    
                }
                iterator it = begin();
               return ft::make_pair<iterator,bool>(it.node,true);

            }
            iterator begin()
            {
                iterator i(a.minValue(a.root),&a);
                return i;
            }
            iterator end()
            {    
                iterator i(nullptr);
                return i;
            }
            ~map()
            {
                
            }
        private: 
            int the_size;
            avl<value_type> a;

    };
    
    
 
    
} 










#endif
 
