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
#include<__tree>

#include <utility>
 
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::pair;
 
#include "red_black_tree.hpp"
#include "iterator.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/type_traits.hpp"
 

namespace ft
{ 
    template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};
    template< typename Key, typename T, typename Compare = std::less<Key> , typename Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
        public:

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // map member types 
            /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            typedef Key                                                                                                                             key_type;
            typedef T										                                                                                        mapped_type;
            typedef ft::pair<const Key, T>                                                                                                          value_type;
            typedef Compare                                                                                                                         key_compare;
            typedef Allocator                                                                                                                       allocator_type;
            typedef typename allocator_type::pointer                                                                                                pointer;
            typedef typename allocator_type::const_pointer                                                                                          const_pointer;
            typedef typename allocator_type::reference                                                                                              reference;
            typedef typename allocator_type::const_reference                                                                                        const_reference;
            typedef size_t                                                                                                                          size_type;

            
            typedef Node_struct<key_type> Node;

            class value_compare : public ft::binary_function<value_type,value_type,bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
            typedef typename ft::map_iterator<key_type,value_type,size_type,mapped_type,allocator_type>                                 iterator;
            typedef typename ft::const_map_iterator<key_type,value_type,size_type,mapped_type,allocator_type>                           const_iterator;
            typedef typename ft::reverse_iterator<iterator>                                                                                         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                                                                                   const_reverse_iterator;
            key_compare _key_comp; //   std::less<int> operator() will enter here

             map (const key_compare& _comp = key_compare(),const allocator_type& alloc = allocator_type()) : tree(value_compare(_comp), alloc), _key_comp(_comp), _alloc(alloc)
            { 
                size_ = 0;
            }
            
            template <class InputIterator>  
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(value_compare(comp), alloc), _key_comp(comp), _alloc(alloc)  
            {
                insert(first,last);
            }

            map (const map & x) : tree(value_compare(x._key_comp), x._alloc), _alloc(x._alloc) // because x is const const reasigne node in  tree.tmp = tree.minValue(tree.root);
            {
                if(x.size() > 0)
                    insert(x.begin(),x.end());
            }
 
            map& operator= (const map& x)
            {
                if(this != &x)// if not pass the same obj
                {
                    clear();
                    
                    insert(x.begin(),x.end());
                    size_ = x.size_;
                }
                return *this;
            }
 
            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                map: Modifiers
            *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
           
            ft::pair<iterator, bool>
            insert (const value_type & val)
            {
                typedef ft::pair<iterator, bool> pr;
                Node_struct<value_type> * node;
                if(empty())
                {
                    size_++;
                    return pr(iterator(tree.insert(val)),true);
                }
                node = tree.insert(val);
                if(!node)
                    return pr(iterator(tree.getNode()),false);
                size_++;
                return pr(iterator(node),true);
            }

            template <class InputIterator>  
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }

            iterator insert (iterator hint, const value_type& val)
            {
                if(hint.node == tree.end_node)
                    return iterator(tree.end_node);
                
                if(hint.node->data.first == val.first)
                    return iterator(hint.node);
                    
                if(hint.node->data.first < val.first && getNext(hint.node)->data.first > val.first)
                {
                    if(hint.node->right == tree.TNULL)
                    {
                        hint.node->right = tree.returnNewNode(val);
                        hint.node->right->parent = hint.node;
                        tree.insertFix(hint.node->right);         
                        return iterator(hint.node->right);
                    }
                    else
                    {
                        Node_struct<value_type> * node = tree.maxValue(hint.node->right);
                        node->left = tree.returnNewNode(val);
                        node->left->parent = node;
                        tree.insertFix(node->left);
                        return iterator(tree.findNode(val.first));
                    }
                }
                return iterator(tree.insert(val));
            }
            
            size_type erase (const key_type& k)
            {
                if(tree.deleteNode(k))
                {
                    --size_;
                    return  1;
                }
                return 0;
            }

            void erase (iterator position)
            {
                tree.deleteNode(position.node->data.first);
                --size_;
            }

            void erase (iterator first, iterator last)
            {
                iterator it = first;

                while (it != last)
                {
                    erase(it++);
                    first = it; 
                }
            }
            
            void clear()
            {
                // if(tree.root == tree.TNULL)
                    // erase(begin(),end());
                tree.clear();
                size_ = 0;
            }
            
            void swap (map& x)
            {
                if(x.size_)
                {
                    map tmp(x);
                    x = *this;
                    *this = tmp; 
                }
            }

            /*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                map: Iterators:
            */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            iterator begin()
            {
                if(size())
                    return iterator(tree.minValue(tree.root));
                return iterator(tree.end_node);
            }
            
            iterator end()
            {
                return iterator (tree.end_node);
            }

            const_iterator begin() const
            { 
                if(size())
                    return const_iterator(tree.minValue(tree.root));
                return const_iterator(tree.end_node);
            }

            const_iterator end() const
            {
                return const_iterator (tree.end_node);
            }
            
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());// this is the last element in tree and when print hi decrimrnt one index
            }

            reverse_iterator rend()// before firt element
            {
                return reverse_iterator(begin());// ? 
            }
            
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());// this is the last element in tree and when print hi decrimrnt one index
            }
            const_reverse_iterator rend() const // before firt element
            {
                return const_reverse_iterator(begin());
            }

            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                map: Element access:
            */////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

            mapped_type& operator[] (const key_type& k)
            {
                return ((this->insert(ft::make_pair(k,mapped_type())).first->second));
            }
             

            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                map: Operations
            *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            iterator find (const key_type& k)
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return iterator(node);
                return iterator(tree.end_node);
            }

            const_iterator find (const key_type& k) const
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return const_iterator(node);
                return const_iterator(tree.end_node);
            }

            size_type count (const key_type & k) const
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return 1;
                return 0;
            }

            // if found the element returns it, if not found returns next greter then k,
            // if k is greter then the max element in map will returns garbage value
            iterator lower_bound(const key_type & k) 
            {
                return iterator(tree.lower_bound(k));
            }

            const_iterator lower_bound (const key_type& k) const //  crete in red balck tree
            {
                return const_iterator(tree.lower_bound(k));
                
            }

            iterator upper_bound (const key_type& k)
            {
                return iterator(tree.upper_bound(k));
            }

            const_iterator upper_bound (const key_type& k) const
            {
                return const_iterator(tree.upper_bound(k));
            }

            ft::pair<iterator,iterator>  equal_range (const key_type& k)
            { 
                iterator i = lower_bound(k);
                iterator j = i;
                if (i != end() && !(_key_comp(k, (*i).first)))
                    ++j;
                return ft::make_pair(i, j);
            }

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            { 
                const_iterator i = lower_bound(k);
                const_iterator j = i;
                if (i != end() && !(_key_comp(k, (*i).first)))
                    ++j;
                return ft::make_pair(i, j);
            }

            /*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                map: Capacity
            *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            bool empty() const
            {
                return size() == 0;
            }
            size_type size() const
            {
                return size_;
            }

            size_type max_size() const 
            {
                return std::numeric_limits<size_type>::max() / sizeof(value_type);// ?
            }
           
            key_compare key_comp() const
            {
                return _key_comp;
            }   
            
            // value_compare value_comp() const {
            //     return (value_compare(tree.key_comp()));
            // }
            ~map()
            { 
                clear();
            }
            private:
                typedef RedBlackTree<key_type,value_type,value_compare,size_type,mapped_type,allocator_type> red_black_tree_;
                red_black_tree_ tree;
                size_type size_;
                
                allocator_type _alloc;
                
    };
    
    template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator== ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
       return !(lhs == rhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
         return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return !(lhs > rhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }
    template <class Key, class T, class Compare, class Alloc>  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,                    const map<Key,T,Compare,Alloc>& rhs )
    {
        return !(rhs > lhs);
    }
} 
 

#endif

// 'map_iterator<[2 * ...], ft::map<int, int, std::__1::plus<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, [3 * ...]>'
// 'map_iterator<[2 * ...], ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, [3 * ...]>'