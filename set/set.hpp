#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
#include <set>
 

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;



#include "../map/red_black_tree.hpp"
#include "../utils/reverse_iterator.hpp"
#include "../utils/type_traits.hpp"
#include "../map/iterator.hpp"


namespace ft
{


    template < class T, class Compare = std::less<T>,    class Alloc = std::allocator<T> > 
    class set
    {
        public:

            typedef T                                                                           key_type;
            typedef key_type                                                                    value_type;
            typedef Compare                                                                     key_compare;
            typedef key_compare                                                                 value_compare;// it used to init value copmar in tree
            typedef Alloc                                                                       allocator_type;
            typedef typename allocator_type::reference                                          reference;
            typedef typename allocator_type::const_reference                                    const_reference;
            typedef typename allocator_type::size_type                                          size_type;
            typedef typename allocator_type::difference_type                                    difference_type;
            typedef typename allocator_type::pointer                                            pointer;
            typedef typename allocator_type::const_pointer                                      const_pointer;

            typedef typename ft::map_iterator<value_type,allocator_type>                         iterator;
            typedef typename ft::const_map_iterator<value_type,allocator_type>                   const_iterator;
            typedef typename ft::reverse_iterator<iterator>                                      reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                                const_reverse_iterator;

 
            key_compare	_key_comp;
            allocator_type	_alloc;

            set () : tree(value_compare(), allocator_type()) {size_ = 0 ;}
			set( const Compare& comp, const allocator_type& alloc = allocator_type() ) : tree(comp, alloc), _key_comp(comp), _alloc(alloc)
            {
                size_ = 0;
            }
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(_key_comp, alloc), _key_comp(comp), _alloc(alloc) {insert(first, last);} //insert(first, last); };
			set (const set& x) : tree(x._key_comp, x._alloc)  
            { 
                size_ = x.size_;
                insert(x.first, x.last);
            };


            set& operator= (const set& x)
            {
               if(this != &x)// if not pass the same obj
                {
                    clear();
                    
                    insert(x.begin(),x.end());
                    size_ = x.size_;
                }
                return *this;
            }
 


            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///     Set: Iterators
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            iterator begin()
            {
                if(size())
                    return iterator(tree.minValue(tree.root));
                return iterator(tree.end_node);
            }

            const_iterator begin() const
            {
                if(size())
                    return const_iterator(tree.minValue(tree.root));
                return const_iterator(tree.end_node);
            }

            iterator end()  
            {
                return iterator (tree.end_node);
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
                return  iterator(tree.insert_hint(hint.node,val));
            }
            
            size_type erase (const value_type & k)
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
                tree.deleteNode(position.node->data);
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
                tree.clear();
                size_ = 0;
            }
            
            void swap (set& x)
            {
                
                tree.swap(x.tree);
                std::swap(size_, x.size_);
            }

            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                map: Operations
            *///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            iterator find (const value_type & k)
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return iterator(node);
                return iterator(tree.end_node);
            }

            const_iterator find (const value_type & k) const
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return const_iterator(node);
                return const_iterator(tree.end_node);
            }

            size_type count (const value_type  & k) const
            {
                Node_struct<value_type> * node = tree.findNode(k);
                if(node)
                    return 1;
                return 0;
            }

            iterator lower_bound(const value_type & k) 
            {
                return iterator(tree.lower_bound(k));
            }

            const_iterator lower_bound (const value_type& k) const //  crete in red balck tree
            {
                return const_iterator(tree.lower_bound(k));
                
            }

            iterator upper_bound (const value_type& k)
            {
                return iterator(tree.upper_bound(k));
            }

            const_iterator upper_bound (const value_type& k) const
            {
                return const_iterator(tree.upper_bound(k));
            }

            ft::pair<iterator,iterator>  equal_range (const value_type& k)
            { 
                iterator i = lower_bound(k);
                iterator j = upper_bound(k);
                return ft::make_pair(i, j);
            }

            ft::pair<const_iterator,const_iterator> equal_range (const value_type& k) const
            { 
                const_iterator i = lower_bound(k);
                const_iterator j = upper_bound(k);
                
                return ft::make_pair(i, j);
            }
            key_compare key_comp() const
            {
                return _key_comp;
            } 
            /*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
                Set : Capacity
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
           
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            ~set() {clear(); size_ = 0;}


            private:
                typedef RedBlackTree<value_type,key_compare,allocator_type> red_black_tree_;
                red_black_tree_ tree;
                size_type size_;
                 
    };      


    template <class T, class Compare, class Alloc>  
    void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
    template <class T, class Compare, class Alloc>  
    bool operator== ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
    }
    template <class T, class Compare, class Alloc>  
    bool operator!= ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
       return !(lhs == rhs);
    }
    template <class T, class Compare, class Alloc>  
    bool operator<  ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
         return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
    template <class T, class Compare, class Alloc>  
    bool operator<= ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
        return !(lhs > rhs);
    }
    template <class T, class Compare, class Alloc>  
    bool operator>  ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
        return (rhs < lhs);
    }
    template <class T, class Compare, class Alloc>  
    bool operator>= ( const set<T,Compare,Alloc>& lhs,                    const set<T,Compare,Alloc>& rhs )
    {
        return !(rhs > lhs);
    }


};














#endif