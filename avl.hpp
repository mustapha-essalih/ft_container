#ifndef AVL_HPP
#define AVL_HPP





 
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

template <typename A>

class Node{

    public:

        A data; 
        Node<A> * left;
        Node<A> * right;
        Node<A> * parent;
        
        Node<A>()
        {
        }
        Node<A>(A d):data(d)
        {
            left = right = parent = nullptr;
        }
        ~Node<A>()
        {
        }
};

// to check if balanced tree or not

// int isBalanced(Node* root)
// {
//     if (root == NULL)
//         return 0;
//     int lh = isBalanced(root->left);
//     if (lh == -1)
//         return -1;
//     int rh = isBalanced(root->right);
//     if (rh == -1)
//         return -1;
 
//     if (abs(lh - rh) > 1)
//         return -1;
//     else
//         return max(lh, rh) + 1;
// }

template<typename T  , typename Allocator = std::allocator<Node<T> > >

class avl
{
    private:
        Allocator alloc;

    public:

        Node<T> * root;
        Node<T> * succ;
        Node<T> * parent;
        Node<T> * node;
 
        int i;
    
        avl()
        {
            i = 1;
            root = nullptr;        
            succ = nullptr;        
            parent = nullptr;        
        }
        bool empty()
        {
            return root == nullptr;
        }
         void inOrder(Node<T>* node)
        {
            if (node == nullptr)
                return;
        
            /* first recur on left child */
            inOrder(node->left);
        
            /* then print the data of node */
            cout << "node: " << node->data.first << endl;
            /* now recur on right child */
            inOrder(node->right);
        }
 
        int height(Node<T> * r) 
        {
            if (r == nullptr)
                return -1;
            else 
            {
            /* compute the height of each subtree */

                int lheight = height(r -> left);
                int rheight = height(r -> right);

            /* use the larger one */
                if (lheight > rheight)
                    return (lheight + 1);
                else return (rheight + 1);
            }
        }
         
        // Get Balance factor of node N  
        int getBalanceFactor(Node<T> * n) 
        {
            if (n == nullptr)//  if tree is empty
                return -1;
            return height(n -> left) - height(n -> right);
        }
     
        Node<T> * rightRotate(Node<T> * y) 
        {
            Node<T> * x = y -> left;
            Node<T> * T2 = x -> right;

            // Perform rotation  
            x -> right = y;
            y -> left = T2;

            return x;
        }

        Node<T> * leftRotate(Node<T> * x)
        {
            Node<T> * y = x -> right;
            Node<T> * T2 = y -> left;

            // Perform rotation  
            y -> left = x;
            x -> right = T2;
        
            return y;
        }
        
        Node<T> * insert(Node<T> * root, T data)
        {
            Node<T> * tmp;
            if(!root)
            {
                Node<T>tmp(data);
                 
                Node<T> * newNode = alloc.allocate(sizeof(Node<T>));
                alloc.construct(newNode,tmp);
                return newNode;  
            }

            else if(data < root->data)
                root->left = insert(root->left,data);
            else //if(data > root->data)
                root->right = insert(root->right,data);

            int bf = getBalanceFactor(root);

            if (bf > 1 && root->left->data > data)
                return rightRotate(root);

            if (bf < -1 && root->right->data < data)
              return leftRotate(root);

            if (bf > 1 && root->left->data < data) 
            {
                root-> left = leftRotate(root -> left);
                return rightRotate(root);
            }

            if (bf < -1 && root->right->data > data) 
            {
                root->right = rightRotate(root -> right);
                return leftRotate(root);
            }
            return root;
        }    
     
        void insert(T data)
        {    
            root = insert(root,data);
        }

        Node<T> * minValue(Node<T>* node)
        {
            if(node == nullptr)
                return nullptr;
            Node<T>* tmp = node;
        
            /* loop down to find the leftmost leaf */
            while (tmp->left != nullptr) 
                tmp = tmp->left;
            return (tmp);
        }
        
        Node<T>* findMX(Node<T>* r)
        {
            Node<T>* tmp = r;
        
            while (tmp->right != nullptr) 
                tmp = tmp->right;
            return (tmp);
        }

        Node<T>* findSuccessor(Node<T>* root, T key)
        {
            if (root == nullptr)
                return succ;
            
            if (root->data == key )
            {
                if (root->right != nullptr)
                    return minValue(root->right);
               
            }
            else if (key < root->data)
            {
                succ = root;
                return findSuccessor(root->left, key);
            }
            else 
                return findSuccessor(root->right, key);

            return succ;
        }
        
          
        ~avl()
        {

        }
};
 



#endif