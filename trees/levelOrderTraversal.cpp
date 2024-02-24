
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

node *createBTree() {
  int value;
  cin >> value;
  if (value == -1) {
    return NULL;
  }
  node *root = new node(value);
  root->left = createBTree();
  root->right = createBTree();
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

node *levelOrderTraversalInp() {
  queue<node *> q;
  node *root = NULL;
  int data;
  cout << "Enter Data For Root : ";
  cin >> data;
  if (data == -1) {
    return NULL;
  }
  root = new node(data);
  q.push(root);
  while (!q.empty()) {
    node *n = q.front();
    q.pop();

    int l, r;
    cout << "Enter Childer Of " << n->data << " : ";
    cin >> l >> r;

    if (l != -1) {
      n->left = new node(l);
      q.push(n->left);
    }

    if (r != -1) {
      n->right = new node(r);
      q.push(n->right);
    }
  }

  return root;
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

int main() {
  node *root = levelOrderTraversalInp();
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
  return 0;
}
