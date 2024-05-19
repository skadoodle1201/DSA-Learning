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

node *insertNode(node *root, int value) {
  if (!root) {
    root = new node(value);
    return root;
  }

  if (root->data >= value) {
    root->left = insertNode(root->left, value);
  } else {
    root->right = insertNode(root->right, value);
  }
  return root;
}
node *createBST() {
  int nodes;
  cin >> nodes;

  node *root = NULL;
  while (nodes) {
    int value;
    cin >> value;

    root = insertNode(root, value);
    nodes--;
  }

  return root;
}

void preOrder(node *root) {
  if (!root) {
    return;
  }
  if (root->left) {
    cout << root->left->data << " => ";
  } else {
    cout << "END => ";
  }
  cout << root->data << " <= ";
  if (root->right) {
    cout << root->right->data << endl;
  } else {
    cout << "END" << endl;
  }
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  node *root = createBST();
  preOrder(root);
  return 0;
}
