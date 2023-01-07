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

#include "reverse_iterator.hpp"
// #include "type_traits.hpp"
#include "avl.hpp"
#include "iterator.hpp"
 

namespace ft
{
    template< typename Key, typename T, typename Compare = std::less<Key> , typename Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
        public:

            ////////////////////
            // map member types //   
            ///////////////////

            typedef Key                                                                                         key_type;
            typedef T										                                                    mapped_type;
            typedef ft::pair<const Key, T>                                                                      value_type;
            typedef Compare                                                                                     key_compare;
            typedef Allocator                                                                                   allocator_type;
            typedef typename allocator_type::pointer                                                            pointer;
            typedef typename allocator_type::const_pointer                                                      const_pointer;
            typedef typename allocator_type::reference                                                          reference;
            typedef typename allocator_type::const_reference                                                    const_reference;
            typedef size_t                                                                                      size_type;
            typedef typename ft::iterator<key_type,value_type,key_compare,size_type,allocator_type>             iterator;
            typedef typename ft::const_iterator<key_type,value_type,key_compare,size_type,allocator_type>       const_iterator;
            typedef typename ft::reverse_iterator<iterator>                                                     reverse_iterator;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                private:
                    key_compare  comp;
                    value_compare (key_compare c) : comp(c) {}  // constructed with tree's comparison object
                public:
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };

            //////////////////////
            // map: constructors  
            /////////////////////

            // default constructor 
            map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):avl()
            {
                size_ = 0;
            }
            template <class InputIterator>  //  range constructor
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            {
                insert(first, last);
            }
            map (const map& x)// copy constructor
            {
                *this = x;
            }
            // operator=
            map& operator= (const map& x) // ?
            {
                if(this != &x)
                {
                    this->avl = x.avl;
                    this->size_ = x.size_;
                }
                return *this;
            }

            /////////////////
            // map: Capacity
            /////////////////
            size_type size() const
            {
                return size_;
            }
            bool empty() const
            {
                return size() == 0;
            }
            size_type max_size() const
            {
                std::allocator<map<key_compare,T> > A; // ?
                return A.max_size();
            }

            //////////////////
            // map: Modifiers
            /////////////////
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

            //////////////////
            // map: Iterators
            /////////////////

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                for(; first != last; ++first)
                    insert(*first);
            }
            iterator insert(iterator _where, const value_type& val)
            {
                std::pair<iterator, bool> res = insert(val);
                if (res.second) 
                    return res.first;
                else 
                    return end();
            }
            iterator begin()
            {
                return iterator(avl.minValue(avl.root));
            }
            const_iterator begin() const
            {
                return const_iterator(avl.minValue(avl.root));
            }
            iterator end()
            {
                return iterator(avl.end_node);
            }
            const_iterator end() const
            {
                return const_iterator(avl.end_node);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(avl.getNext(avl.findMX(avl.root)));// this is the last element in avl
            }
            reverse_iterator rend()// before firt element
            {
                return reverse_iterator(avl.minValue(avl.root));// ? 
            }

            // const_reverse_iterator rend()// before firt element
            // {
            //     return const_reverse_iterator(avl.minValue(avl.root));// ? 
            // }


            ////////////////////
            // map: Operations:
            ////////////////////

            iterator find (const key_type& k)
            {
                if(size() == 0)
                    return iterator(avl.end_node);
                avl.tmp = avl.find(avl.root,k);
                if(avl.tmp)
                    return iterator(avl.tmp);
                return iterator(avl.end_node);
            }

            const_iterator find (const key_type& k) const
            {
                if(size() == 0)
                    return const_iterator(avl.end_node);
                avl.tmp = avl.find(avl.root,k);
                if(avl.tmp)
                    return const_iterator(avl.tmp);
                return const_iterator(avl.end_node);
            }


            ~map()
            {

            }
            private:
                typedef avl<key_type,value_type,key_compare,size_type,allocator_type> avl_data_strcut;
                avl_data_strcut avl;
                size_type size_;
                allocator_type alloc;
    };

} 










#endif
       
 