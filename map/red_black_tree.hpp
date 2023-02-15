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

		Node_struct<K>(const K & d, Node_struct<K> * tNULL) : data(d)
		{
			parent = NULL;
			left = right = tNULL;
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
 
 
template<typename key_type,typename T,typename Compare,typename size_type,typename mapped_type,typename Allocator >

class RedBlackTree {
	
	public:
        typedef Allocator allocator_type;
        typedef T value_type;
        typedef Compare    value_compare;  // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        typedef typename allocator_type::template rebind<Node_struct<value_type> >::other node_allocator;
        typedef Node_struct<value_type> Node;
        node_allocator alloc;
        Node * root;
        Node * tmp;
        Node * end_node;
        Node * TNULL;

        allocator_type      alloc_;
        value_compare       compare;

     
      RedBlackTree(const value_compare& comp, const allocator_type& _alloc) : compare(comp), alloc_(_alloc) 
      {
        end_node = alloc.allocate(1);
        tmp = NULL;
        TNULL = alloc.allocate(1);
        Node tmpNode;
        alloc.construct(end_node,tmpNode);
        alloc.construct(TNULL,tmpNode);// free 
            root = TNULL;
      }

      void leftRotate(Node * x) 
      {
          Node * y = x->right;
          x->right = y->left;
          if (y->left != TNULL) {
          y->left->parent = x;
          }
          y->parent = x->parent;
          if (x->parent == NULL) {
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
        if (x->parent == NULL) {
        this->root = y;
        } else if (x == x->parent->right) {
        x->parent->right = y;
        } else {
        x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }


    void deleteFix(Node * x) 
    {
    Node * s;
    while (x != root && x->color == 0) {
      if (x == x->parent->left) {
        s = x->parent->right;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->right->color == 0) {
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
      } else {
        s = x->parent->left;
        if (s->color == 1) {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0) {
          s->color = 1;
          x = x->parent;
        } else {
          if (s->left->color == 0) {
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

  void rbTransplant(Node * u, Node * v) {
    if (u->parent == NULL) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  size_type deleteNodeHelper(Node * node, const key_type & key) 
  {
    root->parent = NULL;
    Node * z = TNULL;
    Node * x;
    Node * y;
    while (node != TNULL) {
      if (node->data.first == key) {
        z = node;
      }

      if  (compare(node->data , key))
      {
        node = node->right;
      } else {
        node = node->left;
      }
    }

    if (z == TNULL)
        return 0;
    
    

    y = z;
    size_type y_original_color = y->color;
    if (z->left == TNULL) {
      x = z->right;
      rbTransplant(z, z->right);
    } else if (z->right == TNULL) {
      x = z->left;
      rbTransplant(z, z->left);
    } else {
      y = minValue(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z) {
        x->parent = y;
      } else {
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



  size_type deleteNode(const key_type & data) 
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

        Node * insert(const value_type& val) 
        {
            Node * newNode = alloc.allocate(1);
            Node tempNode(val,TNULL);
            alloc.construct(newNode,tempNode);

            Node * y = NULL;
            Node * x = this->root;

            while (x != TNULL) 
            {
                y = x;
                if (compare(newNode->data , x->data)) 
                {
                    x = x->left;
                } 
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
            {
                root = newNode;
            } 
            else if (compare(newNode->data , y->data)) 
            {
                y->left = newNode;
            } 
            else 
            {
                y->right = newNode;
            }

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
        
            while (current->right != TNULL) 
                current = current->right;
            
            return (current);
        }

    Node* findNode(const key_type & key)    const 
    {
      Node* current = root;
      while (current != TNULL) 
      {
        if (!(compare(key , current->data)) && (!(compare( current->data,key))))
        {
          // setNode(current);
          return current;
        } 
        else if (compare(key , current->data.first))
          current = current->left;
        else 
          current = current->right;
      }
      return NULL;
    } 

	Node * returnNewNode(const value_type & data)
	{
		Node * node = alloc.allocate(1);
		Node tmp(data,TNULL);
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
 
    void postOrderHelper(Node * node) 
    {
      if (node != NULL) 
      {
      	postOrderHelper(node->left);
      	deleteNode(node->data.first);
      	postOrderHelper(node->right);
      }
      
    }


    void	swap(RedBlackTree &other)
			{
				Node * thisRoot = this->root;
				Node * thisNIL = this->TNULL;
				// int thisSize =	this->_size;
				
				this->root = other.root;
				this->TNULL = other.TNULL;
				// this->_size = other._size;
				other.root = thisRoot;
				other.TNULL = thisNIL;
				// other._size = thisSize;
			}

    Node * successor(Node * x) {
    if (x->right != TNULL) {
      return minValue(x->right);
    }

    Node * y = x->parent;
    while (y != TNULL && x == y->right) {
      x = y;
      y = y->parent;
    }
    return y;
  }
  Node *	_getSuccessor(Node * node)
  {
    Node *	last;

    last = node;
    if (node->right && node->right->right)
      return minValue(node->right);
    Node *	temp = node->parent;
    while (temp && node == temp->right && node != temp->left) {
      node = temp;
      temp = temp->parent;
    }
    if (!temp)
      return (last->right);
    return temp;
  }

	~RedBlackTree()
	{ 
 		root->parent = NULL;
		postOrderHelper(root);
 		alloc.deallocate(end_node,1);
 		alloc.deallocate(TNULL,1);
 		
	}
};



#endif


 


 