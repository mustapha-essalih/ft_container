#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <memory>
#include <stack>
#include <vector>
 



using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;


template <typename K>
struct Node_struct  {

		K data;
		int color;
		Node_struct<K>* left;
		Node_struct<K>* right;
		Node_struct<K>* parent;

		Node_struct<K>(const K & d, Node_struct<K> * NIL) : data(d)
		{
			parent = NULL;
			left = right = NIL;
			color = 1;
		}
		Node_struct<K>(const K & d = K()) : data(d)
		{ 
			left = right = NULL;
			color = 0;
		}
};


template <typename K> // for calling in map_iterator 

Node_struct<K> * minNode(Node_struct<K> * node)
{
    Node_struct<K> * current = node;
    while (current->left->left != NULL) 
        current = current->left;
    return (current);
}

template <typename K>
Node_struct<K> * maxNode(Node_struct<K> * node)
{
    Node_struct<K> * current = node;
	
    while (current->right->right != NULL) 
        current = current->right;
    return (current);
}
 
template <typename K>

bool is_left_child(Node_struct<K> * node)
{
  return node ==  node->parent->left;
}

template <typename K>
Node_struct<K>* getNext(Node_struct<K>* node)
{
	if(node->right->right != NULL)
		return minNode(node->right);
	while (!is_left_child(node))
        node = node->parent;
    
    return node->parent;
}
 
template <typename K>

Node_struct<K>* getPrev(Node_struct<K>* node)
{
    if(node->left->left != NULL)
        return maxNode(node->left);
    while (is_left_child(node))
        node = node->parent;
    return node->parent;
}
 
 
template<typename T,typename Compare,typename Allocator >

class RedBlackTree {
	
	public:
        typedef Allocator allocator_type;
        typedef size_t 													  size_type;
		typedef ptrdiff_t 												difference_type;
        typedef T value_type;
        typedef Compare    value_compare;  // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        typedef typename allocator_type::template rebind<Node_struct<value_type> >::other node_allocator;
        typedef Node_struct<value_type> Node;
        node_allocator alloc;
        Node * root;
        Node * tmp;
        Node * end_node;
        Node * NIL;

        allocator_type      alloc_;
        value_compare       compare;// obj call value cpare class and call overloading operator

     
      RedBlackTree(const value_compare& comp, const allocator_type& _alloc) : alloc_(_alloc) , compare(comp)
      {
        end_node = alloc.allocate(1);
        tmp = NULL;
        NIL = alloc.allocate(1);
        Node tmpNode;
        alloc.construct(end_node,tmpNode);
        alloc.construct(NIL,tmpNode);// free 
        root = NIL;
      }

      void leftRotate(Node * x) 
      {
		Node * y = x->right;
		x->right = y->left;
		if (y->left != NIL) 
			y->left->parent = x;
		
		y->parent = x->parent;
		if (x->parent == NULL) 
			this->root = y;
		else if (x == x->parent->left) 
			x->parent->left = y;
		else 
			x->parent->right = y;
		
		y->left = x;
		x->parent = y;
      }

    void rightRotate(Node * x) 
	{
        Node * y = x->left;
        x->left = y->right;
        if (y->right != NIL) 
        	y->right->parent = x;
        
        y->parent = x->parent;
        if (x->parent == NULL) 
        	this->root = y;
        else if (x == x->parent->right) 
        	x->parent->right = y;
        else 
        	x->parent->left = y;
        
        y->right = x;
        x->parent = y;
    }


    void deleteFix(Node * x) 
    {
		Node * s;
		while (x != root && x->color == 0) 
		{
			if (x == x->parent->left) 
			{
				s = x->parent->right;
				if (s->color == 1) 
				{
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == 0 && s->right->color == 0) 
				{
					s->color = 1;
					x = x->parent;
				} 
				else 
				{
					if (s->right->color == 0) 
					{
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			} 
			else 
			{
				s = x->parent->left;
				if (s->color == 1) 
				{
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) 
				{
					s->color = 1;
					x = x->parent;
				} 
				else 
				{
					if (s->left->color == 0) 
					{
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
  	}

	void rbTransplant(Node * u, Node * v) 
	{
		if (u->parent == NULL) 
			root = v;
		else if (u == u->parent->left) 
			u->parent->left = v;
		else 
			u->parent->right = v;
		v->parent = u->parent;
	}

	size_type deleteNodeHelper(Node * node, const value_type & key) 
	{
		root->parent = NULL;
		Node * z = NIL;
		Node * x;
		Node * y;
		while (node != NIL) 
		{
			if (!compare(node->data , key) && !compare(key,node->data)) 
				z = node;
			if  (compare(node->data , key))
				node = node->right;
			else 
				node = node->left;
		}

		if (z == NIL)
			return 0;
		y = z;
		size_type y_original_color = y->color;
		if (z->left == NIL) 
		{
			x = z->right;
			rbTransplant(z, z->right);
		} 
		else if (z->right == NIL) 
		{
			x = z->left;
			rbTransplant(z, z->left);
		} 
		else 
		{
			y = minValue(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) 
				x->parent = y;
			else 
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		alloc.deallocate(z,1);
		if (y_original_color == 0) 
			deleteFix(x);
		end_node->left = root;
		root->parent = end_node;
		return 1;
	}
 
	size_type deleteNode(const value_type & data) 
	{
		return deleteNodeHelper(this->root, data);
	}


	void insertFix(Node *  k) 
    {
        root->parent = NULL;
        Node *  u;
        while (k->parent->color == 1) 
        {
            if (k->parent == k->parent->parent->right) // 
            {
                u = k->parent->parent->left;
                if (u->color == 1) 
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
                } 
				else 
				{
					if (k == k->parent->left) 
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
                }
            } 
			else 
			{
                u = k->parent->parent->right;
                if (u->color == 1) 
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
                } 
				else 
				{
					if (k == k->parent->right) 
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
                }
            }
            if (k == root) 
                break;
        }
        root->color = 0;
    }

	Node * insert(const value_type& val) 
	{
		Node * newNode = alloc.allocate(1);
		Node tempNode(val,NIL);
		alloc.construct(newNode,tempNode);

		Node * y = NULL;
		Node * x = root;

		while (x != NIL) 
		{
			y = x;
			if (compare(newNode->data , x->data)) 
				x = x->left;
			else if(compare(x->data,newNode->data))
				x = x->right;
			else
			{
				setNode(x);
				alloc.deallocate(newNode,1);
				return NULL;
			}
		}
		newNode->parent = y;
		if (y == NULL) 
			root = newNode;
		
		else if (compare(newNode->data , y->data)) 
			y->left = newNode;
		else 
			y->right = newNode;

		if (newNode->parent == NULL) 
		{
			end_node->left = root;
			root->parent = end_node;
			newNode->color = 0;
			return newNode;
		}

		if (newNode->parent->parent == end_node) 
			return newNode;
		
		insertFix(newNode);
		end_node->left = root;
		root->parent = end_node;
		return newNode;
	} 

	Node * minValue(Node * node) const
	{
		Node * current = node;
	
		while (current->left->left != NULL) 
			current = current->left;
		
		return (current);
	}

	Node * maxValue(Node * node)
	{
		Node * current = node;
	
		while (current->right != NIL) 
			current = current->right;
		
		return (current);
	}

    Node* findNode(const value_type & key)    const 
    {
      Node* current = root;
      while (current != NIL) 
      {
        if (!(compare(key , current->data)) && (!(compare( current->data,key))))
          return current;
        
        else if (compare(key , current->data))
          current = current->left;
        else 
          current = current->right;
      }
      return NULL;
    } 

	Node * returnNewNode(const value_type & data)
	{
		Node * node = alloc.allocate(1);
		Node tmp(data,NIL);
		alloc.construct(node,tmp);
		return node;
	}

	void setNode(Node * node)  
	{
    	tmp = node;
	}

	Node * getNode()
	{
		return tmp;
	}
 
    void destroyTree(Node * node)
    {
		if (node->left != NIL )
			destroyTree(node->left);// because is a class i use destroy 
		if (node->right != NIL )
			destroyTree(node->right);
		if (node != NIL)
		{
			if (node != root && node == node->parent->right)
				node->parent->right = NIL;
			if (node != root && node == node->parent->left)
				node->parent->left = NIL;
			if (node == root)
				root = NIL;
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}
    }

	void postOrderHelper(Node * node) 
	{
		if (node != NULL) 
		{
			postOrderHelper(node->left);
			deleteNode(node->data);
			postOrderHelper(node->right);
		}
	}

	Node * insert_hint (Node * hint, const value_type& val)
	{
		if(hint == end_node)
			return  end_node;
		
		if(!compare(hint->data , val) && !compare( val,hint->data) )
			return  hint ;
			
		if(compare(hint->data, val) && compare(val,getNext(hint)->data))
		{
			if(hint->right == NIL)
			{
				hint->right = returnNewNode(val);
				hint->right->parent = hint;
				insertFix(hint->right);         
				return  hint->right;
			}
			else
			{
				Node_struct<value_type> * node = maxValue(hint->right);
				node->left = returnNewNode(val);
				node->left->parent = node;
				insertFix(node->left);
				return findNode(val);
			}
		}
		return insert(val);
	}

    Node *	lower_bound(const value_type & k)
    {
        Node * i;

        i = minValue(root);
      
        while(i != end_node &&   compare(i->data, k))
          i = getNext(i);
        return (i);
    }

    Node * upper_bound(const value_type& key)
    {
        Node * i;

        i = minValue(root);
        while(compare(i->data, key) && i != end_node)
          i = getNext(i); 
        if (!compare(key, i->data) && i != end_node)
          i = getNext(i);
        return (i);
    }

    void	clear()
    {
      if (this->root != this->NIL)
        destroyTree(this->root); // node by node
    }

    void swap(RedBlackTree &other)
    { 
        std::swap(root, other.root);
        std::swap(tmp, other.tmp);
        std::swap(end_node, other.end_node);
        std::swap(NIL, other.NIL);
    }

	~RedBlackTree()
	{ 
 		root->parent = NULL;
	  	postOrderHelper(root);
		alloc.deallocate(NIL,1);
		alloc.deallocate(end_node,1);  
	}
};



#endif


 


 


