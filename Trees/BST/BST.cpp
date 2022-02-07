#include <iostream>

using namespace std;

// Tree Node
struct Node {
    int value;
    Node *left, *right;

    Node (int v) {
        value = v;
        left = right = NULL;
    }
};

struct STACK_Node {
    Node *nodePtr;
    STACK_Node *next;
    STACK_Node(Node *node) {
        nodePtr = node;
        next = NULL;
    }
};
// Stack ADT to traverse iteratively
struct Stack {

    STACK_Node *top = NULL;

    void push(Node *node) {
        STACK_Node *stack_node = new STACK_Node(node);
        stack_node->next = top;
        top = stack_node;
    }

    int pop() {
        if (top) {    
            STACK_Node *temp = top;
            int value = temp->nodePtr->value;

            top = top->next;

            delete temp;
            cout << value << " ";
            return value;
        }
        return -1;
    }

    int peek() {
        if (top)
            return top->nodePtr->value;
        return -1;
    }

    void display() {
        STACK_Node *temp = top;
        cout << "Stack nodes :: [ ";
        while (temp) {
            cout << temp->nodePtr->value << " ";
            temp = temp->next;
        }
        cout << "]\n";
    }
};


struct BST
{
    int size;
    int depth;
    Node *root;

    BST () {
        size = 0;
        depth = 0;
        root = NULL;
    }

    Node *insertRec(Node *pNode, int value, int &d) {
        if (pNode==NULL) {
            Node *node = new Node(value);
            pNode = node;
        } else {
            if (value < pNode->value) {
                pNode->left = insertRec(pNode->left, value, d);
            } else {
                pNode->right = insertRec(pNode->right, value, d);
            }
        }
        d++;
        return pNode;
    }

    void insertRec(int value) {
        int d = 0;
        root = insertRec(root, value, d);

        if (depth<d)
            depth=d;

        size++;
    }

    void insertIter(int value) {
        Node *node = new Node(value);
        int depth = 1;
        if (!root) {
            root = node;
        } else {
            Node *temp = root;
            while (temp)
            {
                depth++;
                if (value<temp->value)
                    if (temp->left)
                        temp = temp->left;
                    else {
                        temp->left = node;
                        break;
                    }
                else
                    if (temp->right)
                        temp = temp->right;
                    else {
                        temp->right = node;
                        break;
                    }
            }
        }

        if (depth>this->depth)
            this->depth = depth;

        size++;
    }

    bool searchRec(Node *pnode, int key) {
        if (pnode==NULL) {
            printf(" - (%d) Not found\n", key);
            return false;
        } else if (pnode->value==key) {
            printf(" - (%d) found\n", key);
            return true;
        } else {
            if (key < pnode->value)
                return searchRec(pnode->left, key);
            else
                return searchRec(pnode->right, key);
        }
    }

    bool searchIter(int key) {

        Node *temp = root;
        while(temp) {
            if (key==temp->value){
                printf(" - (%d) found\n", key);
                return true;
            }
            else if (key<temp->value)
                temp = temp->left;
            else 
                temp = temp->right;
        }
        printf(" - (%d) Not found\n", key);
        return false;
    }

    void preOrder(Node *pNode) {
        if (pNode==NULL) {
            return;
        }
        cout << pNode->value << " ";
        preOrder(pNode->left);
        preOrder(pNode->right);
    }
    void preOrder() {
        cout << " - PRE_OrderRec :: [ ";
        preOrder(root);
        cout << "]\n";
    }

    /* print InOrder binary tree traversal.*/
    void inOrder(Node *pNode) {
        if (pNode==NULL) {
            return;
        }
        inOrder(pNode->left);
        cout << pNode->value << " ";
        inOrder(pNode->right);
    }
    void inOrder() {
        cout << " - IN_OrderRec :: [ ";
        inOrder(root);
        cout << "]\n";
    }

    /* Invert the tree */
    void invert(Node *pNode) {
        if (!pNode)
            return;
        Node *temp = pNode->left;
        /* swap the pointers in this node */
        pNode->left = pNode->right;
        pNode->right = temp;
        invert(pNode->left);
        invert(pNode->right);
    }

    void asc_inOrderIter() {

        Node *temp = root;
        if (temp) {
            int i = 0;
            Node *s[depth];
            cout << " - IN_Order using stack  :: [ ";
            do
            {
                while (temp)
                {
                    s[i] = temp;
                    i++;
                    temp = temp->left;
                }
                i--;
                if (i==-1) break;
                temp = (*s[i]).right;
                cout << (*s[i]).value << " ";

            } while (true);
            cout << "]\n";
        }
    }

    Node *MIN_Node(Node *pNode) {
        if (pNode==NULL) {
            cout << " - Tree Is Empty\n";
            return NULL;
        }
        if (pNode->left==NULL) {
            return pNode;
        }
        return MIN_Node(pNode->left);
    }

    Node *MAX_Node(Node *pNode) {
        if (pNode==NULL) {
            cout << " - Tree Is Empty\n";
            return NULL;
        }
        if (pNode->right==NULL) {
            return pNode;
        }
        return MAX_Node(pNode->right);
    }

    int TreeDepthRec(Node *root) {
        if (!root)
            return 0;
        int l = TreeDepthRec(root->left);
        int r = TreeDepthRec(root->right);
        
        return (l>r) ? 1+l : 1+r;
    }

    int get_depth() {
        return depth;
    }

    int get_size() {
        return size;
    }

    Node *remove(Node *pNode, int key) {
        if (pNode==NULL) {
            return NULL;
        }
        if (key<pNode->value)
            pNode->left = remove(pNode->left, key);
        else if (key>pNode->value)
            pNode->right = remove(pNode->right, key);

        else {

            // Leaf node to delete
            if (pNode->left == NULL && pNode->right==NULL) {
                pNode = NULL;
                size--;
            }

            // one children
            else if (pNode->left != NULL && pNode->right == NULL) {
                Node *temp = pNode;
                pNode = pNode->left;
                delete temp;
                size--;
            }
            else if (pNode->left == NULL && pNode->right != NULL) {
                Node *temp = pNode;
                pNode = pNode->right;
                delete temp;
                size--;
            }
            else {
                Node* max = MAX_Node(pNode->left);
                pNode->value = max->value;
                pNode->left = remove(pNode->left, max->value);
            }
        }
        return pNode;
    }

};

int main() {
    
    printf(
    R"( :: Binary Search Tree ADT
    Functions :
        Insert  (Recursively & Iteratively)
        preOrder (Recursively)
        inOrder (Recursively)
        inOrderIter (Iteratively)
        MIN_Node
        MAX_Node
        TreeDepthRec
        get_depth
        get_size
        Remove)"
    );

    BST tree;
    cout << " - BST Created\n";

    /*
        Insert values into BST (
            Iteratively : insertIter func
            recursively : insertRec func
            )
    */
    for (int i: {34,23,22,6,16,18,57,38,95,12}) {
        tree.insertIter(i);
    }
    cout << " - 10 items inserted\n";

    Node *root = tree.root;

    tree.inOrder();
    tree.asc_inOrderIter();
    tree.invert(root);
    cout << " - Tree inverted\n";
    tree.asc_inOrderIter();
    tree.inOrder();


    // tree.desc_inOrderIter();

    Node *min = tree.MIN_Node(root);
    if (min != NULL) {
        cout << " - The Minimum Value Is: " << min->value << endl;
    }

    Node *max = tree.MAX_Node(root);
    if (max != NULL) {
        cout << " - The Maximun Value Is: " << max->value << endl;
    }

    tree.searchRec(root, 4);
    tree.searchIter(6);

    // Remove some nodes
    for (int i: {6,95}) {
        tree.remove(root, i);
        printf(" - (%d) removed\n", i);
    }
    
    min = tree.MIN_Node(root);
    if (min != NULL) {
        cout << " - The Minimum Value Is: " << min->value << endl;
    }

    max = tree.MAX_Node(root);
    if (max != NULL) {
        cout << " - The Maximun Value Is: " << max->value << endl;
    }

    printf(" - Depth %d, Size %d\n", tree.TreeDepthRec(root), tree.get_size());

}
