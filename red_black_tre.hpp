#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
enum Color {RED, BLACK};

template <typename K>
struct Node_struct  {
    K data;
    bool color;
    Node_struct<K>* left;
    Node_struct<K>* right;
    Node_struct<K>* parent;

    Node_struct<K>(const K & d,Node_struct<K> * tNULL)   : data(d)  
    {
        parent = NULL;
        left = right = tNULL;
        color = RED;
    }
    Node_struct<K>(const K & d)   : data(d)  
    {
        left = right = NULL;
        color = BLACK;
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

bool is_left_child(Node_struct<K> * node )
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
    if(node->left != NULL)
        return maxNode(node->left);
    while (is_left_child(node))
        node = node->parent;
    return node->parent;
}


template<typename key_type,typename T,typename key_compare,typename size_type,typename mapped_type,typename Allocator >

class RBTree {
     
 
    public:
         typedef Allocator allocator_type;
            typedef T value_type;
            key_compare key_compare_; // key_compare_(); lambda object convet to function will call operator() (const value_type& x, const value_type& y) const
            typedef typename allocator_type::template rebind<Node_struct<value_type> >::other node_allocator;
            typedef Node_struct<value_type> Node;
            node_allocator alloc;
            Node * root;
            Node * TNULL;
            Node * tmp;
            Node * end_node;
        
        RBTree() 
        { 
            end_node = alloc.allocate(1);
            TNULL = alloc.allocate(1);
            Node tmp((value_type()));
            alloc.construct(TNULL,tmp);
            alloc.construct(end_node,tmp);
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
  void deleteFix(Node * x) {
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

        size_type deleteNodeHelper(Node * node,const key_type & key) {
            Node * z = TNULL;
            Node * x;
            Node * y;
            while (node != TNULL) {
            if (node->data.first == key) {
                z = node;
            }

            if (node->data.first <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
            }

            if (z == TNULL) {
             return 0;
            }

            y = z;
            int y_original_color = y->color;
            if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
            } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
            } else {
            y = minNode(z->right);
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
            alloc.deallocate(z,sizeof(z));
            if (y_original_color == 0) {
            deleteFix(x);
            }
            return 1;
        }


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

        void insert(const value_type & key) 
        {
            Node * node = alloc.allocate(1);
            Node tmp(key,TNULL);
            alloc.construct(node,tmp);
            

            Node * y = NULL;
            Node * x = this->root;

            while (x != TNULL) 
            {
                y = x;
                if (node->data < x->data) {
                    x = x->left;
                } else {
                    x = x->right;
                }
            }

            node->parent = y;
            if (y == NULL) {
            root = node;
            } else if (node->data < y->data) {
            y->left = node;
            } else {
            y->right = node;
            }

            if (node->parent == NULL) {
            node->color = 0;
            return;
            }

            if (node->parent->parent == NULL) {
            return;
            }

            insertFix(node);
        }
size_type deleteNode(const key_type & data) {
    return deleteNodeHelper(this->root, data);
  }
         Node* findNode(const key_type & key) const 
        {
            Node* current = root;
            while (current != TNULL) 
            {
                if (key == current->data.first) 
                    return current;
                else if (key < current->data.first) 
                    current = current->left;
                else 
                    current = current->right;
            }
            return NULL;
        }  
        Node * minValue(Node * node) const
        {
            Node * current = node;
            if(!root->left)// if one node in tree
                return NULL;
            while (current->left->left != NULL) {
                current = current->left;
            }
            return (current);
        }
        Node * maxValue(Node * node) const
        {
            Node * current = node;
            if(!root->right)
                return NULL;
            while (current->right->right != NULL) {
                current = current->right;
            }
            return (current);
        }
        // Node* findNode(Node * node, const key_type & key)const
        // {
        //     if (node == TNULL || key == node->data.first) {
        //     return node;
        //     }

        //     if (key < node->data.first) {
        //     return findNode(node->left, key);
        //     }
        //     return findNode(node->right, key);
        // }
};




#endif


 
        // bool is_left_child(Node  * node)
        // {
        //     return node == node->parent->left;
        // }

        // Node* getNext(Node* node)
        // {
        //     if(node->right != NULL)
        //         return minValue(node->right);
        //     while (!is_left_child(node))
        //         node = node->parent;
        //     return node->parent;
        // } 

        