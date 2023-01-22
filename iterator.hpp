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
 
#include "avl.hpp"
  
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;

// crete class iterator and inhert from it here

namespace ft 
{
    template <typename key_type, class T,typename key_compare,typename size_type,typename mapped_type,typename Allocator  >

        class map_iterator 
        {   
            public:
                
                typedef constNode<key_type,mapped_type>                                             value_type;
                typedef ptrdiff_t                                                                   difference_type;
                typedef  T*                                                                         pointer;
                typedef  T&                                                                         reference;
                typedef std::bidirectional_iterator_tag                                             iterator_category;
                
                Node<key_type,mapped_type> * node;             
            
                map_iterator():node(0){}
            
                map_iterator(Node<key_type,mapped_type>* n):node(n)
                {
                }
                        
                map_iterator(const map_iterator& it)
                {
                    node = it.node;
                }
        
                map_iterator& operator=(const map_iterator& it)
                {
                    node = it.node;
                    return *this;
                }

                map_iterator& operator++() 
                { 
                    node = getNext(node);
                    return *this;                    
                }
 
                
                map_iterator& operator--() 
                { 
                    // node = a.getPrev(node);
                     
                    return *this;                    
                }
                
                bool operator == (const map_iterator& obj) const
                {
                    return node == obj.node;
                }
                
                bool operator!=(const map_iterator& it) const
                {
                    return node != it.node;
                }

                pointer operator->() const
                {
                    constNode<key_type,mapped_type> non_const = returnConst();
                    return &non_const->data;// return const node in this case else use normal non const node 
                }
                
                reference operator*() const
                {
                    constNode<key_type,mapped_type> non_const = returnConst();

                    return non_const->data;
                }
            private:

                Node<key_type,mapped_type>* minNode(Node<key_type,mapped_type> *n) 
                {
                    while (n->left) 
                        n = n->left;
                    
                    return n;
                }
                bool is_left_child(Node<key_type,mapped_type> * node)
                {
                    return node == node->parent->left;
                }
                Node<key_type,mapped_type>* getNext(Node<key_type,mapped_type>* node)
                {
                    if(node->right != NULL)
                        return minNode(node->right);
                    
                    cout << node->parent->data.first << endl;
                    if(node == node->parent->left)
                        cout << "equals\n";
                    // while (!is_left_child(node))
                    //     node = node->parent;
                    return node->parent;
                } 

                constNode<key_type,mapped_type>  returnConst()
                {
                    Node<key_type,mapped_type> n = *node;
                    constNode<key_type,mapped_type>  r(n.data.first,n.data.second);
                     
                    return r;
                }

    }; 
     
};

 
#endif