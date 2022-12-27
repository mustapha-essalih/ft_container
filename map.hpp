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
                // /// handle if have one element
                // a.insert(ft::make_pair<key_type,mapped_type>(10,800));
                // a.insert(ft::make_pair<key_type,mapped_type>(20,14));
                // a.insert(ft::make_pair<key_type,mapped_type>(30,20));
                // a.insert(ft::make_pair<key_type,mapped_type>(40,926));
                // a.insert(ft::make_pair<key_type,mapped_type>(50,87));
                // a.insert(ft::make_pair<key_type,mapped_type>(60,12));


                // a.insert(ft::make_pair<key_type,mapped_type>(20,800));
                // a.insert(ft::make_pair<key_type,mapped_type>(30,14));
                // a.insert(ft::make_pair<key_type,mapped_type>(19,20));
                // a.insert(ft::make_pair<key_type,mapped_type>(40,926));
                // a.insert(ft::make_pair<key_type,mapped_type>(22,926));
                // a.insert(ft::make_pair<key_type,mapped_type>(50,87));
                // a.insert(ft::make_pair<key_type,mapped_type>(60,12));
                // a.insert(ft::make_pair<key_type,mapped_type>(70,84));

                // a.inOrder(a.root);
                
            }   
            pair<iterator,bool> insert (const value_type& val)
            {
                iterator it;

                
                if(a.empty())
                {
                    a.insert(val);

                    it = begin();
                    
                    a.node = alloc.allocate(sizeof(a.node));
                    return ft::make_pair<iterator,bool>(it.node,true);
                }
                // else
                // {
                //     for (it = begin(); it!=end(); ++it)
                //     {
                //         if(it.node->data == val)
                //         {
                //             cout << "HERE\n";
                //             return ft::make_pair<iterator,bool>(it,false);
                //         }
                //     }
                //     a.insert(val);

                // }
                return ft::make_pair<iterator,bool>(it.node,true);
            }
            iterator begin()
            {  
                iterator it(a.minValue(a.root),a.root);
                return it;
            }
            iterator end()
            {
                iterator it(nullptr);
                return it;
            }
            ~map()
            {
            }
        private: 
            int the_size;
            avl<value_type>  a;
            Allocator alloc;
    };
    
    
 
    
} 










#endif
 
