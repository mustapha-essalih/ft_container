#ifndef BST_HPP
#define BST_HPP


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





class bst
{
    private:
        typedef struct Node{

            int data;
            Node *left;
            Node *right;

            Node(int item)
            {
                data = item;
                right = left = nullptr;
            }
        }Node;

        
        Node * newNode(Node * root, int data)// must handle if data entred equal data
        {
            if(!root)
            {
                Node * newNode = new Node(data);
                return newNode;
            }
            else if(data < root->data)
                root->left = newNode(root->left,data);
            else 
                root->right = newNode(root->right,data);
 
            return root;
        }
    
    public:
        Node * root;

        bst()
        {
            root = nullptr;
        }

        void free_(Node * root) 
        {
            if(!root)
                return;
            free_(root->left);
            delete root;
            free_(root->right);
        }

        Node * search(Node * root, int data)// always search in one direction left direction or right direction
        {
            if(!root)
                return nullptr;
            else if(root->data == data)
                return root;
            else if(data < root->data)
                return search(root->left,data);
            else
                return search(root->right,data);
             
        }

        bool search(int data)
        {
            if(!search(root,data))
                return false;
            else
                return true;
        }

        void inOrder(Node * root)// root left right
        {
            if(!root)// if empty
                return;
            inOrder(root->left);
            cout << root->data << endl;
            inOrder(root->right);
        }

        void insert(int data)
        {
            root = newNode(root,data);
        }

        

        ~bst()
        {
            if(root)
                free_(root);
        }
};





#endif