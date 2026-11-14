#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* create() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* root = new Node(x);

    cout << "Enter left of " << x << ": ";
    root->left = create();

    cout << "Enter right of " << x << ": ";
    root->right = create();

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int totalnode(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + totalnode(root->left) + totalnode(root->right);
}

int leafnode(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafnode(root->left) + leafnode(root->right);
}

int internalnode(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + internalnode(root->left) + internalnode(root->right);
}


// 1. Count Leaf Nodes
int leafcount(Node *p) {
    if(p == NULL)
        return 0;

    if(p->left == NULL && p->right == NULL)
        return 1;

    return leafcount(p->left) + leafcount(p->right);
}


// 2. Count Internal Nodes
int internalnode_count(Node *p) {
    if(p == NULL)
        return 0;

    if(p->left != NULL || p->right != NULL)
        return 1 + internalnode_count(p->left)
                 + internalnode_count(p->right);

    return 0;
}


// 3. Count Nodes Having Exactly One Child
int onechild(Node *p) {
    if(p == NULL)
        return 0;

    int count = 0;

    if((p->left != NULL && p->right == NULL) ||
       (p->left == NULL && p->right != NULL))
        count = 1;

    return count + onechild(p->left) + onechild(p->right);
}


// 4. Count Nodes Having Two Children
int twochild(Node *p) {
    if(p == NULL)
        return 0;

    int count = 0;

    if(p->left != NULL && p->right != NULL)
        count = 1;

    return count + twochild(p->left) + twochild(p->right);
}
int main() {
    cout << "Enter the root : ";
    Node* root = create();

    cout << "Output are : \n";

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nTotal Nodes: " << totalnode(root);

    cout << "\nLeaf Nodes: " << leafnode(root);

    cout << "\nInternal Nodes: " << internalnode(root);

    cout << "Leaf Nodes: " << leafcount(root) << endl;

    cout << "Internal Nodes: " << internalnode_count(root) << endl;

    cout << "One Child Nodes: " << onechild(root) << endl;

    cout << "Two Child Nodes: " << twochild(root) << endl;

    return 0;
}