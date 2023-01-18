#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
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
  
 
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
#include "red_black_tree.hpp"
 
namespace ft 
{
    template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class map_iterator 
        {   
            public:
                
                typedef T                                           value_type;
                typedef ptrdiff_t                                   difference_type;
                typedef  T*                                         pointer;
                typedef  T&                                         reference;
                typedef std::bidirectional_iterator_tag              iterator_category;
                
                Node_struct<value_type,size_type> * node;             
            
                map_iterator():node(0){}
            
                map_iterator(Node_struct<value_type,size_type> * n):node(n)
                {
                }
                map_iterator(Node_struct<value_type,size_type> * n,Node_struct<value_type,size_type> * r):node(n)
                {
                    root = r;
                }
                map_iterator(Node_struct<value_type,size_type> * n,Node_struct<value_type,size_type> * end,Node_struct<value_type,size_type> * begin):node(n)
                {
                    max = end;
                    min = begin;
                    // cout << min->data.first << endl;
                    // cout << max->data.first << endl;
                }
                        
                map_iterator(const map_iterator& it)
                {
                    node = it.node;
                }
        
                map_iterator& operator=(const map_iterator& it)
                {
                    if(this != &it)
                        node = it.node;
                    return *this;
                }

                map_iterator& operator++() 
                { 
                    if(node == maxValue(root))
                    {
                        node = node->right;
                        return *this;                    
                    }
                    node = getNext(node);
                    return *this;                    
                }

                map_iterator& operator--() 
                { 
                     node = getPrev(node);
                    return *this;                    
                }
                map_iterator operator++(int) 
                { 
                    map_iterator temp = *this;
                    node = getNext(node);
                    return temp;                    
                }
                
                map_iterator operator--(int) 
                {
                    map_iterator temp = *this;
                    node =  getPrev(node);
                    return temp;
                }
                
                bool operator == (const map_iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const map_iterator& it) const
                {
                    return node != it.node;
                }
                bool operator!=(const map_iterator& it)  
                {
                    return node != it.node;
                }

                pointer operator->() const
                {
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                Node_struct<T,size_type>  * root;
                Node_struct<T,size_type>  * max;
                Node_struct<value_type,size_type> * min;
                Node_struct<value_type,size_type> * garbage;
                typedef typename Allocator::template rebind< Node_struct<T,size_type> >::other node_allocator; 
                node_allocator alloc;
                
                Node_struct<value_type,size_type> * getGarbage()
                {
                    Node_struct<value_type,size_type> tmp((T()));
                    garbage = alloc.allocate(sizeof(Node_struct<value_type,size_type>));
            		alloc.construct(garbage,tmp);
                    return garbage;
                }


                Node_struct<T,size_type> * minValue(Node_struct<T,size_type> * node)
                {
                    Node_struct<T,size_type> * current = node;
                    while (current->left->left != nullptr) 
                            current = current->left;
                    
                    return current;
                }

                Node_struct<T,size_type> * maxValue(Node_struct<T,size_type> * node)
                {
                    Node_struct<T,size_type> * current = node;
                    while (current->right->right != nullptr) 
                            current = current->right;
                    
                    return current;
                }


                bool is_left_child(Node_struct<T,size_type> * node)
                {
                    return node == node->parent->left;
                }

                Node_struct<value_type,size_type>* getPrev(Node_struct<value_type,size_type>* node)
                {
                    if(node == max)// if node == NIL
                    {
                        node = node->parent;
                        return node;
                    }
                    if(node == min)
                    {
                        node = getGarbage();
                        return node;
                    }
                    if(node->left->left != nullptr)
                        return maxValue(node->left);
                     
                    while (is_left_child(node))
                        node = node->parent;
                    return node->parent;

                }

                Node_struct<T,size_type>* getNext(Node_struct<T,size_type>* node)
                {
                    if(node->right->right != nullptr)
                        return minValue(node->right);
                    while (!is_left_child(node))
                        node = node->parent;
                    return node->parent;
                } 
    }; 
    template <typename key_type, class T,typename key_compare,typename size_type,typename Allocator  >

        class const_map_iterator 
        {   
            public:
                
                typedef T                                           value_type;
                typedef ptrdiff_t                                   difference_type;
                typedef  const T*                                   pointer;
                typedef  const T&                                   reference;
                typedef std::bidirectional_iterator_tag              iterator_category;

                
                const_map_iterator():node(0){}
            
                const_map_iterator(Node_struct<T,size_type> * n):node(n){}
                /*
                    if decalare const_iterator and assign it begin() will enter in this copy constructor;
                    if decalre const map will cal begin() const and enter to const iterator.
                */          
                const_map_iterator(const map_iterator<key_type,value_type,key_compare,size_type,Allocator> & it)
                {
                    node = it.node;
                }    
                const_map_iterator(const const_map_iterator & it)
                {
                    node = it.node;
                }
        
                const_map_iterator& operator=(const const_map_iterator& it)
                {
                    node = it.node;
                    return *this;
                }
                const_map_iterator& operator=(const map_iterator<key_type,value_type,key_compare,size_type,Allocator>& it)
                {
                    node = it.node;
                    return *this;
                }

                const_map_iterator& operator++() 
                { 
                    node = getNext(node);
                      
                    return *this;                    
                }

                const_map_iterator operator++(int) 
                { 
                    const_map_iterator temp = *this;

                    node = getNext(node);
                     
                    return temp;                    
                }
                
                const_map_iterator& operator--() 
                { 
                    // node = getPrev(node);
                     
                    return *this;                    
                }
                const_map_iterator operator--(int) 
                {
                    const_map_iterator temp = *this;
                    
                    node = getPrev(node);
                     
                    return temp;
                }
                
                bool operator == (const const_map_iterator& obj) const
                {
                    return node == obj.node;
                }
                bool operator == (const map_iterator<key_type,value_type,key_compare,size_type,Allocator>& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const const_map_iterator& it) const
                {
                    return node != it.node;
                }

                bool operator!=(const  map_iterator<key_type,value_type,key_compare,size_type,Allocator>& it) const
                {
                    return node != it.node;
                }

                pointer operator->() const // here pointer  is const pointer for can't edit return value
                {                          // like it->second= 10 or  ++it->second
                    return &node->data;
                }
                
                reference operator*() const
                {
                    return node->data;
                }
            private:
                Node_struct<value_type,size_type> * node;             

                Node_struct<T,size_type> * minValue(Node_struct<T,size_type> * node) const
                {
                    Node_struct<T,size_type> * current = node;
                    if(!current)
                        return nullptr;// garbage
                    while (current->left != nullptr) 
                        current = current->left;
                    
                    return current;
                }

                Node_struct<T,size_type> * findMX(Node_struct<T,size_type> * node) const
                {
                    Node_struct<T,size_type> * current = node;
                    if(!current)
                        return nullptr;// garbage
                    while (current->right != nullptr) 
                        current = current->right;
                    
                    return current;
                }

                bool is_left_child(Node_struct<T,size_type> * node)
                {
                    return node == node->parent->left;
                }

                Node_struct<T,size_type>* getPrev(Node_struct<T,size_type>* node)
                {
                    if(node->left != nullptr)
                        return findMX(node->left);
                    while (is_left_child(node))
                        node = node->parent;
                    return node->parent;
                }

                Node_struct<T,size_type>* getNext(Node_struct<T,size_type>* node)
                {
                    if(node->right != nullptr)
                        return minValue(node->right);
                    while (!is_left_child(node))
                        node = node->parent;
                    return node->parent;
                } 
        };
};

 
#endif