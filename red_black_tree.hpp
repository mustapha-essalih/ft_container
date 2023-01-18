// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

template <typename value_type,typename size>

struct Node_struct {

	value_type data;
	Node_struct<value_type,size> *parent;
	Node_struct<value_type,size> *left;
	Node_struct<value_type,size> *right;
	int color;
	
	Node_struct(value_type d):data(d)
	{
		left = right  = nullptr;
		color = 0;
	}
	Node_struct(value_type d,Node_struct<value_type,size> *N):data(d)
	{
		left = right  = N;
		parent = nullptr;
		color = 1;	
	}
	
};
// function return TNULL
template<typename key_type,class T,typename key_compare,typename size_type,typename Allocator >

class RedBlackTree {
    
    public:
        typedef Allocator allocator_type;
		typedef T value_type;
		key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
		typedef Node_struct<T,size_type> Node;
		typedef typename allocator_type::template rebind<Node >::other node_allocator; 
		node_allocator alloc;

		Node * root;
		Node * TNULL;
		Node * tmp;
		Node * end_node;
        
	RedBlackTree() 
	{
		Node tmp1((T()));
		TNULL = alloc.allocate(sizeof(Node));
		alloc.construct(TNULL,tmp1);

		root = TNULL;
	}
	 
  // For balancing the tree after insertion
    void insertFix(Node * k) {
        Node * u;
        while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
            u->color = 0;
            k->parent->color = 0;
            k->parent->parent->color = 1;
            k = k->parent->parent;
            } else {
            if (k == k->parent->left) {
                k = k->parent;
                rightRotate(k);
            }
            k->parent->color = 0;
            k->parent->parent->color = 1;
            leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 1) {
            u->color = 0;
            k->parent->color = 0;
            k->parent->parent->color = 1;
            k = k->parent->parent;
            } else {
            if (k == k->parent->right) {
                k = k->parent;
                leftRotate(k);
            }
            k->parent->color = 0;
            k->parent->parent->color = 1;
            rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
        }
        root->color = 0;
    }


 
  void leftRotate(Node * x) {
    Node * y = x->right;
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(Node * x) {
    Node * y = x->left;
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(value_type data)
	{
		Node tmp(data,TNULL);
		Node * node = alloc.allocate(sizeof(Node));
		alloc.construct(node,tmp);
		
		Node * y = nullptr;
		Node * x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		node->parent = y;
		if (y == nullptr) 
			root = node;
		else if (node->data < y->data) 
			y->left = node;
		else 
			y->right = node;
		

		if (node->parent == nullptr) 
		{
			node->color = 0;
			return;
		}

		if (node->parent->parent == nullptr) 
			return;

		insertFix(node);
	}

    Node * minValue(Node * node)
	{
		Node * current = node;

		while (current->left->left != nullptr) 
				current = current->left;
		
		return current;
	}

    Node * maxValue(Node * node)
	{
		Node * current = node;
		
		while (current->right->right != nullptr) 
				current = current->right;
		
		return current;
	}
		bool is_left_child(Node * node)
		{
			return node == node->parent->left;
		}
		Node* getNext(Node* node)
		{
				if(node->right->right != nullptr)
					return minValue(node->right);
				while (!is_left_child(node))
					node = node->parent;
				return node->parent;
		} 
		Node* getPrev(Node* node)
		{
			if(node->left->left != nullptr)
				return maxValue(node->left);
			// while (is_left_child(node))
			// 		node = node->parent;
			return node->parent;

		}

		Node *search(Node* node, const key_type & key) const // search() const because key_type is const
        {
			 
			if(node == TNULL)
			{
				return node;
			}
            if (!key_compare_(node->data.first, key) && !key_compare_(key,node->data.first))// because key_compare_ return < and convert it to ==
                return node;
             
            if (key_compare_(node->data.first, key))
                return search(node->right, key);        
            return search(node->left, key);
        }

		 
};

