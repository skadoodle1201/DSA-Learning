
#include <iostream>
#include <queue>
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
node *insertNode(node *root, int data) {
    if (!root) {
        root = new node(data);
        return root;
    }

    if (root->data >= data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

node *createBTree() {
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    }
    node *root = NULL;

    while (value != -1) {
        root = insertNode(root, value);
        cin >> value;
    }
    return root;
}

// ROOT LEFT RIGHT
void preOder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOder(root->left);
    preOder(root->right);
}

// LEFT ROOT RIGHT
void inOrder(node *root) {
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// LEFT RIGHT ROOT
void postOrder(node *root) {
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        if (n == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << n->data << " ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
}

void printBSTInRange(node *root, int k1, int k2) {
    if (!root)
        return;
    if (root->data >= k1 and root->data <= k2) {
        cout << root->data << " ";
    }
    if (root->data < k1) {
        printBSTInRange(root->right, k1, k2);
    } else if (root->data > k2) {
        printBSTInRange(root->left, k1, k2);
    } else {
        printBSTInRange(root->left, k1, k2);
        printBSTInRange(root->right, k1, k2);
    }
}
int main() {
    node *root = createBTree();
    cout << "PREORDER :: \n";
    preOder(root);
    cout << endl;
    cout << "INORDER :: \n";
    inOrder(root);
    cout << endl;
    cout << "POSTORDER :: \n";
    postOrder(root);
    cout << endl;
    levelOrderTraversal(root);
    cout << endl;
    printBSTInRange(root, 3, 10);

    return 0;
}
