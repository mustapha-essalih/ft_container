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

        Node * returnNewNode(const value_type & data)
        {
             
            Node * node = alloc.allocate(1);
            Node tmp(data,TNULL);
            alloc.construct(node,tmp);
            return node;
        }
        void printHelper(Node *root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color  ? "RED" : "BLACK";
      cout << root->data.first << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }