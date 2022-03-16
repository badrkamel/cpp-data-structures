#include <iostream>

using namespace std;

// Tree Node
struct Node {
    int value;
    Node *left = nullptr;
    Node *right = nullptr;
    
    Node ();
    Node (int v) : value(v) {}
};

class BST
{
    size_t size{};
    size_t depth{};
    
public:
    Node *root = nullptr;

    Node *insertRec(Node *p, int value, size_t &d) {
        if (p == NULL) {
            Node *node = new Node(value);
            p = node;
        } else {
            if (value < p->value) {
                p->left = insertRec(p->left, value, d);
            } else {
                p->right = insertRec(p->right, value, d);
            }
        }
        d++;
        return p;
    }

    void insertRec(int value) {
        size_t d{};
        root = insertRec(root, value, d);

        if (depth<d)
            depth=d;

        size++;
    }

    void insertIter(int value) {
        Node *node = new Node(value);
        size_t depth = 1;
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

    bool search(Node *p, int key) {

        while(p) {
            if (key == p->value){
                printf(" - (%d) found\n", key);
                return true;
            }
            else if (key < p->value)
                p = p->left;
            else 
                p = p->right;
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
            size_t i{};
            Node *stk[depth];
            cout << " - IN_Order using stack  :: [ ";
            do
            {
                while (temp)
                {
                    stk[i] = temp;
                    i++;
                    temp = temp->left;
                }
                i--;
                if (i==-1) break;
                temp = (*stk[i]).right;
                cout << (*stk[i]).value << " ";

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
        Search
        MIN_Node
        MAX_Node
        TreeDepthRec
        get_depth
        get_size
        Remove)"
    );

    BST tree;
    cout << "\n\n - BST Created\n";

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
    tree.invert(root);
    cout << " - Tree inverted\n";
    tree.asc_inOrderIter();
    tree.invert(root);
    cout << " - Tree inverted\n";



    // tree.desc_inOrderIter();

    Node *min = tree.MIN_Node(root);
    if (min != NULL) {
        cout << " - The Minimum Value Is: " << min->value << endl;
    }

    Node *max = tree.MAX_Node(root);
    if (max != NULL) {
        cout << " - The Maximun Value Is: " << max->value << endl;
    }

    tree.search(root, 4);
    tree.search(root, 6);

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
