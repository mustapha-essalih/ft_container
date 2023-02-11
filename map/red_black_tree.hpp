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

		Node_struct<K>(const K & d = K()) : data(d)
		{
			parent = NULL;
			left = right = NULL;
			color = 1;
		}
};


template <typename K> // for calling in map_iterator 

Node_struct<K> * minNode(Node_struct<K> * node)
{
    Node_struct<K> * current = node;
    while (current->left != NULL) 
        current = current->left;
    return (current);
}

template <typename K>
Node_struct<K> * maxNode(Node_struct<K> * node)
{
    Node_struct<K> * current = node;
	
    while (current->right != NULL) 
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
	if(node->right != NULL)
		return minNode(node->right);
	while (!is_left_child(node))
        node = node->parent;
    
    return node->parent;
}

template <typename K>

Node_struct<K>* getPrev(Node_struct<K>* node)
{
    if(node->left != NULL)
        return maxNode(node->left);
    while (is_left_child(node))
        node = node->parent;
    return node->parent;
}
 
 
template<typename key_type,typename T,typename key_compare,typename size_type,typename mapped_type,typename Allocator >

class RedBlackTree {
	
	public:
        typedef Allocator allocator_type;
        typedef T value_type;
        key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
        typedef typename allocator_type::template rebind<Node_struct<value_type> >::other node_allocator;
        typedef Node_struct<value_type> Node;
        node_allocator alloc;
        Node * root;
        Node * tmp;
        Node * end_node;
 	 

     
	RedBlackTree() 
	{
		root = tmp = NULL;
		end_node = alloc.allocate(1);
		tmp = alloc.allocate(1);
		Node tmpNode;
		alloc.construct(end_node,tmpNode);
		alloc.construct(tmp,tmpNode);// free 

	}

	void leftRotate(Node * x) 
    {
        if(x == root)// remove end_node to evit sigfault and vielent
            x->parent = NULL;
        Node * y = x->right;

        x->right = y->left;
        if (y->left != NULL) 
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
        if(x == root)   
            x->parent = NULL;
        Node * y = x->left;
        x->left = y->right;
        if (y->right != NULL)
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

	void insertFix(Node * k) 
    {
        Node * u;
        while (k->parent->color == 1) // for retchecken
        {
            if (k->parent == k->parent->parent->right) 
            {
                u = k->parent->parent->left;
                if (u && u->color == 1) 
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
                // sometimes u is NULL
                if (u && u->color == 1) 
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
            root->color = 0;// always root color is balck
    }

	Node * insert(const value_type& val) 
    {
		Node * newNode = alloc.allocate(1);
		Node tempNode(val);
		alloc.construct(newNode,tempNode);
		
        Node * y = NULL;
        Node * x = root;
        while (x != NULL) 
        {
            y = x;			
			if( newNode->data.first < x->data.first)
                x = x->left;
            else if( newNode->data.first > x->data.first)
                x = x->right;
			else
            {
                setNode(x);
                return NULL;
            }
        }
		 
        newNode->parent = y;
        if (y == NULL)
            root = newNode;
        else if (newNode->data.first < y->data.first)  // use keycomapr
            y->left = newNode;
        else 
            y->right = newNode;
        

        if (newNode->parent == NULL) // if  newNode is the root
        {
            newNode->color = 0;
            end_node->left = root;
            root->parent = end_node;
            return newNode;
        }

        if (newNode->parent->parent == end_node) 
            return newNode;

        // pass newNode 
        insertFix(newNode);
        end_node->left = root;
        root->parent = end_node;
		return newNode;
    }

	Node * minValue(Node * node)
	{
		Node * current = node;
	
		while (current->left != NULL) 
			current = current->left;
		
		return (current);
	}

	Node * maxValue(Node * node)
	{
		Node * current = node;
	
		while (current->right != NULL) 
			current = current->right;
		
		return (current);
	}

	Node* findNode(const key_type & key)   
	{
		Node* current = root;
		while (current != NULL) 
		{
			if (key == current->data.first)
			{
				setNode(current);
				return current;
			} 
			else if (key < current->data.first) 
				current = current->left;
			else 
				current = current->right;
		}
		return NULL;
	} 

	Node * returnNewNode(const value_type & data)
	{
		Node * node = alloc.allocate(1);
		Node tmp(data);
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
	void printHelper(Node * root, string indent, bool last) {
        if (root != NULL) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }

        string sColor = root->color ? "RED" : "BLACK";
        cout << root->data << "(" << sColor << ")" << endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
        }
    }
	void postOrderHelper(Node * node) 
	{
		if (node != NULL) 
		{
			postOrderHelper(node->left);
			// deleteNode(node->data.first);
			postOrderHelper(node->right);
		}
	}
	void printTree() 
	{
		if (root) {
			printHelper(this->root, "", true);
		}
  	}
	 
	 
  
	~RedBlackTree()
	{ 
 		// alloc.deallocate(end_node,1);
 		// alloc.deallocate(tmp,1);
		// root->parent = NULL;
		// postOrderHelper(root);
		
	}
};



#endif


 


 