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

    Node_struct<K>(const K & d,bool c )   : data(d)  
    {
        left = right = parent = NULL;
        color = c;
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
    return node == node->parent->left;
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
    if(node->left != nullptr)
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
            Node * tmp;
            Node * end_node;
        
        RBTree() 
        { 
            root = NULL; 
             end_node = alloc.allocate(1);
            Node tmp(value_type(),RED);
            alloc.construct(end_node,tmp);
        }
        
        Node* BSTInsert(Node* root, Node *pt)
        {
            if(!root)
                return pt;    
            if (pt->data < root->data)
            {
                root->left = BSTInsert(root->left, pt);
                root->left->parent = root;
            }
            else if (pt->data > root->data)
            {
                root->right = BSTInsert(root->right, pt);
                root->right->parent = root;
            } 
            return root;
        }
        

        void rotateLeft(Node *&root, Node *&pt)
        {
            Node *pt_right = pt->right;

            pt->right = pt_right->left;

            if (pt->right != NULL)
                pt->right->parent = pt;

            pt_right->parent = pt->parent;

            if (pt->parent == NULL)
                root = pt_right;

            else if (pt == pt->parent->left)
                pt->parent->left = pt_right;

            else
                pt->parent->right = pt_right;

            pt_right->left = pt;
            pt->parent = pt_right;
        }

        void rotateRight(Node *&root, Node *&pt)
        {
            Node *pt_left = pt->left;

            pt->left = pt_left->right;

            if (pt->left != NULL)
                pt->left->parent = pt;

            pt_left->parent = pt->parent;

            if (pt->parent == NULL)
                root = pt_left;

            else if (pt == pt->parent->left)
                pt->parent->left = pt_left;

            else
                pt->parent->right = pt_left;

            pt_left->right = pt;
            pt->parent = pt_left;
        }
        
        void fixViolation(Node *&root, Node *&pt)
        {
            Node *parent_pt = NULL;
            Node *grand_parent_pt = NULL;

            while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
            {

                parent_pt = pt->parent;
                grand_parent_pt = pt->parent->parent;
        
                if (parent_pt == grand_parent_pt->left)
                {
                    Node *uncle_pt = grand_parent_pt->right;
                    if (uncle_pt != NULL && uncle_pt->color == RED)
                    {
                        grand_parent_pt->color = RED;
                        parent_pt->color = BLACK;
                        uncle_pt->color = BLACK;
                        pt = grand_parent_pt;
                    }

                    else
                    { 
                        if (pt == parent_pt->right)
                        {
                            rotateLeft(root, parent_pt);
                            pt = parent_pt;
                            parent_pt = pt->parent;
                        }
                        rotateRight(root, grand_parent_pt);
                        std::swap(parent_pt->color,
                                grand_parent_pt->color);
                        pt = parent_pt;
                    }
                }
                else
                {
                    Node *uncle_pt = grand_parent_pt->left;

                    if ((uncle_pt != NULL) && (uncle_pt->color == RED))
                    {
                        grand_parent_pt->color = RED;
                        parent_pt->color = BLACK;
                        uncle_pt->color = BLACK;
                        pt = grand_parent_pt;
                    }
                    else
                    {
                        if (pt == parent_pt->left)
                        {
                            rotateRight(root, parent_pt);
                            pt = parent_pt;
                            parent_pt = pt->parent;
                        }

                        rotateLeft(root, grand_parent_pt);
                        std::swap(parent_pt->color,
                                grand_parent_pt->color);
                        pt = parent_pt;
                    }
                }
            }

            root->color = BLACK;
        }
  
        void insert(const value_type &data)
        {
            Node *pt = alloc.allocate(1);
            if(!root)
            {
                Node tmp(data,BLACK);
                 
                alloc.construct(pt,tmp);
                root = pt;
                return ;
            }
    
            Node tmp(data,RED);
            alloc.construct(pt,tmp);
            root = BSTInsert(root, pt);
            fixViolation(root, pt);
        }
        
        Node * minValue(Node * node)
        {
            Node * current = node;
        
            /* loop down to find the leftmost leaf */
            while (current->left != NULL) {
                current = current->left;
            }
            return (current);
        }
        Node * maxValue(Node * node)
        {
            Node * current = node;
        
            /* loop down to find the leftmost leaf */
            while (current->right != NULL) {
                current = current->right;
            }
            return (current);
        }
 

};




#endif









//  Node * searchTreeHelper(Node * node, int key) {
//     if (node == TNULL || key == node->data) {
//       return node;
//     }

//     if (key < node->data) {
//       return searchTreeHelper(node->left, key);
//     }
//     return searchTreeHelper(node->right, key);
//   }