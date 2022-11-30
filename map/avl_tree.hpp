#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

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

#include <utility>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::map;
using std::pair;





class avl_tree
{
    private:

    typedef struct Node
    {
        int data;
        Node *right;
        Node * left;
        int height;
        int left_n;
        int right_n;
       
    } Node;

    public:
        

        Node * root;
        avl_tree()
        {
            root = nullptr;
        }
        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
                return 0;
            return height(N->left) -
                height(N->right);
        }

        Node * creteNewNode(Node * root, int item)
        {
            if(!root)
            {
                Node * newNode = new Node();
                newNode->data = item;
                newNode->left = newNode->right = nullptr; 
                // second time root here is  root->right or root->left
                newNode->height = 1;
                return newNode;
            }
            else if(item > root->data)
                root->right = creteNewNode(root->right,item);
            else
                root->left = creteNewNode(root->left,item);
            
            root->height = 1 + max(height(root->left), height(root->right));
            int balanceFactor = getBalanceFactor(root);

            cout << balanceFactor << endl;
            
            return root;// root here is fixed , always data of this root will print fixed value of first node entered
            // we return root al so beacuse function need return
        }
        int height(Node *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        int max(int a, int b)
        {
            return (a > b)? a : b;
        }


        void insert(int data)
        {
            // here always we assing return value to root because in recursion always 
            root = creteNewNode(root,data);
            
            
            
        }
        void inOrder(Node* root)// to print sorted data
        {
            if (!root)
                return;
            inOrder(root->left);
            cout << root->data << endl;
            inOrder(root->right);
        }
        void preOrder(Node *root)
        {
            if(root != NULL)
            {
                cout << root->data << " ";
                preOrder(root->left);
                preOrder(root->right);
            }
        }
        ~avl_tree()
        {

        }
};
 










#endif