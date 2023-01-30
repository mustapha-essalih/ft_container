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
 
#include "red_black_tre.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{ 

    template< typename Key, typename T, typename Compare = std::less<Key> , typename Allocator = std::allocator<ft::pair<const Key, T> > >
 
    class map
    {
        public:
            ////////////////////
            // map member types //   
            ///////////////////

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

            typedef typename ft::map_iterator<key_type,value_type,key_compare,size_type,mapped_type,allocator_type>                                 iterator;
            typedef typename ft::const_map_iterator<key_type,value_type,key_compare,size_type,mapped_type,allocator_type>                           const_iterator;
            typedef typename ft::reverse_iterator<iterator>                                                                                         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                                                                                         const_reverse_iterator;
            
            ///////////////////////////
            // map: constructor
            //////////////////////////

            map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
            {
                size_ = 0;
            }
            
            template <class InputIterator>  
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                size_ = 0;
            }
            map (const map& x)
            {
                size_ = 0;
            }

            ////////////////////////
            // map::operator=
            ///////////////////////
            
            map& operator= (const map& x)
            {
                return *this;
            }

            ////////////////////
            // map: Modifiers
            //////////////////
             
             
            ft::pair<iterator, bool> 
            insert(const value_type & val)
            {
                typedef ft::pair<iterator, bool> pr;
                Node_struct<value_type> * node;

                if(size_ == 0)
                {
                    tree.insert(val);        
                    size_++;
                    iterator it(tree.findNode(val.first),tree.end_node,tree.root);
                    return pr(it,true);
                }
                node = tree.findNode(val.first);// if not found return null if not du[licate]
                if(node)
                {
                    iterator it(tree.findNode(val.first),tree.end_node,tree.root);

                    return pr(it,false); 
                }
                
                tree.insert(val);
                size_++;
                iterator it(tree.findNode(val.first),tree.end_node,tree.root);
                return pr(it,true);
            }
 
             
            template <class InputIterator>  
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
                tree.insert(tree.end_node->data);    
            }
             
            iterator insert (iterator hint, const value_type& val)
            {
                if(hint.node == tree.end_node)
                    return iterator(tree.end_node,tree.end_node,tree.root);
                
                if(hint.node->data.first == val.first)
                    return iterator(hint.node,tree.end_node,tree.root);
                if(hint.node->data.first < val.first && getNext(hint.node)->data.first > val.first)
                {
                    if(hint.node->right == tree.TNULL)// if has leaks free hint.node->right and reaclloc
                    {
                        hint.node->right = tree.returnNewNode(val);
                        hint.node->right->parent = hint.node;
                        tree.insertFix(hint.node->right);         
                        return iterator(hint.node->right,tree.end_node,tree.root);
                    }
                    else
                    {
                        Node_struct<value_type> * node = tree.maxValue(hint.node->right);
                        node->left = tree.returnNewNode(val);
                        node->left->parent = node;
                        tree.insertFix(node);
                        return iterator(tree.findNode(val.first),tree.end_node,tree.root);
                    }
                }
                tree.insert(val);
                return iterator(tree.findNode(val.first),tree.end_node,tree.root);
            }

            // size_type erase (const key_type& k)
            // {
            //     tree.deleteNode(k);
            //     return  1;
            // }
            // void erase (iterator position)
            // {
            //     tree.deleteNode(position.node->data.first);
            // }
            // void erase (iterator first, iterator last)
            // {
            //     iterator it = first;

            //     while (it != last)
            //     {
            //         erase(it++);
            //         first = it;
            //     }
                
            // }

            ///////////////////////////////
            // map: Iterators
            ////////////////////////////////
             
            iterator begin()
            {
                tree.tmp = tree.minValue(tree.root);
                if(tree.tmp)
                    return iterator (tree.tmp,tree.end_node,tree.root);
                return iterator(tree.end_node,tree.end_node,tree.root);
            }
            const_iterator begin() const
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                tree.tmp = tree.minValue(tree.root);
                if(tree.tmp)
                    return const_iterator (tree.tmp);
                return const_iterator(tree.end_node);
            }
            iterator end()
            {
                return iterator (tree.end_node,tree.end_node,tree.root);
            }
            
            const_iterator end() const
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                return const_iterator (tree.end_node,tree.end_node,tree.root);
            }
            
            reverse_iterator rbegin()
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                return reverse_iterator(tree.end_node,tree.end_node,tree.root);// this is the last element in tree and when print hi decrimrnt one index
            }

            reverse_iterator rend()// before firt element
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                return reverse_iterator(tree.minValue(tree.root));// ? 
            }
            
            const_reverse_iterator rbegin() const
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                return const_reverse_iterator(getNext(tree.maxValue(tree.root)));// this is the last element in tree and when print hi decrimrnt one index
            }
            const_reverse_iterator rend() const // before firt element
            {
                // tree.root->parent = tree.end_node;
                // tree.end_node->left = tree.root;
                return const_reverse_iterator(tree.minValue(tree.root));// ? 
            }

            // /////////////////////
            // map: Element access
            // ///////////////////////
            mapped_type& operator[] (const key_type& k)
            {
                return (this->insert(value_type(k, mapped_type())).first->second);
            }
            // mapped_type& at(const key_type& k) 
            // {
            //     iterator it = find(k);
            //     if (it == end()) 
            //         throw std::out_of_range("key not found in map");
            //     return it->second;
            // }
            // const mapped_type& at(const key_type& k) const 
            // {
            //     const_iterator it = find(k);
            //     if (it == end()) 
            //         throw std::out_of_range("key not found in map");
                
            //     return it->second;
            // }

            ///////////////////
            // map: Operations
            ////////////////////

            iterator find (const key_type& k)
            {
                if(size() == 0)
                    return iterator(tree.end_node,tree.end_node,tree.root);
                tree.tmp = tree.findNode(k);
                if(tree.tmp)
                    return iterator(tree.tmp,tree.end_node,tree.root);
                return iterator(tree.end_node,tree.end_node,tree.root);
            }

            // const_iterator find (const key_type& k) const
            // {
            //     if(size() == 0)
            //         return const_iterator(tree.end_node);
            //     tree.tmp = tree.findNode(k);
            //     if(tree.tmp)
            //         return const_iterator(tree.tmp);
            //     return const_iterator(tree.end_node);
            // }

            // size_type count (const key_type& k) const
            // {
            //     if(size() == 0)
            //         return 0;
            //     if(tree.findNode(k))
            //         return 1;
            //     return 0;
            // }

            // if found the element returns it, if not found returns next greter then k,
            // if k is greter then the max element in map will returns garbage value
            // iterator lower_bound (const key_type& k)
            // {
            //     if(size() == 0)
            //         return iterator(tree.end_node);
            //     tree.tmp = tree.findNode(k);
            //     if(tree.tmp)
            //         return iterator(tree.tmp);
            //     if(key_compare_(k,tree.maxValue(tree.root)->data.first))
            //         return iterator(tree.findNode(k));
            //     else
            //         return iterator(tree.end_node);
            // }

            // const_iterator lower_bound (const key_type& k) const
            // {
            //     if(size() == 0)
            //         return const_iterator(tree.end_node);
            //     tree.tmp = tree.findNode(k);
            //     if(tree.tmp)
            //         return const_iterator(tree.tmp);
            //     if(key_compare_(k,tree.maxValue(tree.root)->data.first))
            //         return const_iterator(tree.findNode(k));
            //     else
            //         return const_iterator(tree.end_node);
            // }

            // iterator upper_bound (const key_type& k)
            // {
            //     if(size() == 0)
            //         return iterator(tree.end_node);
            //     tree.tmp = tree.findNode(k);
            //     if(tree.tmp)
            //         return iterator(tree.getNext(tree.tmp));// if element is exist returns next
            //     if(key_compare_(k,tree.maxValue(tree.root)->data.first))// if smaller then max element return next of this k
            //         return iterator(tree.findNode(k));
            //     else
            //         return iterator(tree.end_node);
            // }
            // const_iterator upper_bound (const key_type& k) const
            // {
            //     if(size() == 0)
            //         return const_iterator(tree.end_node);
            //     tree.tmp = tree.findNode(k);
            //     if(tree.tmp)
            //         return const_iterator(tree.getNext(tree.tmp));// if element is exist returns next
            //     if(key_compare_(k,tree.maxValue(tree.root)->data.first))// if smaller then max element return next of this k
            //         return const_iterator(tree.findNode(k));
            //     else
            //         return const_iterator(tree.end_node);
            // }


        
            //////////////////
            // map: Capacity
            /////////////////

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
           
            ~map()
            {

            }
            private:
                typedef RBTree<key_type,value_type,key_compare,size_type,mapped_type,allocator_type> red_black_tree_;
                red_black_tree_ tree;
                size_type size_;
                
    };
    

} 
 

#endif