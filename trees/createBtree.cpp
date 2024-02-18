#include <iostream>
using namespace std;

class node {
   public:
    int data;
    node *left, *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* createBTree() {
    int value;
    cin >> value;
    if (value == -1) {
        return NULL;
    }
    node* root = new node(value);
    root->left = createBTree();
    root->right = createBTree();
    return root;
}

// ROOT LEFT RIGHT
void preOder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOder(root->left);
    preOder(root->right);
}

// LEFT ROOT RIGHT
void inOrder(node* root) {
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// LEFT RIGHT ROOT
void postOrder(node* root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int countNodes(node* root) {
    if (!root) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    node* root = createBTree();
    cout << "PREORDER :: \n";
    preOder(root);
    cout << endl;
    cout << "INORDER :: \n";
    inOrder(root);
    cout << endl;
    cout << "POSTORDER :: \n";
    postOrder(root);
    cout << endl;

    cout << "NUMBER OF NODES " << countNodes(root) << endl;

    return 0;
}