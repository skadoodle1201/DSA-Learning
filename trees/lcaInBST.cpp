#include <cmath>
#include <iostream>
#include <vector>
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
  node *root = NULL;
  int level = 0;
  while (level > 0) {
    int value;
    cin >> value;
    root = insertNode(root, value);
    level--;
  }
  return root;
}

node *lca(node *root, int n1, int n2) {
  if (!root) {
    return NULL;
  }

  if (root->data > n1 and root->data > n2) {
    return lca(root->left, n1, n2);
  }

  if (root->data < n1 and root->data < n2) {
    return lca(root->right, n1, n2);
  }
  return root;
}

void preOder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOder(root->left);
    preOder(root->right);
}


class Pair {
public:
  bool found;
  node *k;
};
Pair findInBST(node *root, int k, vector<int> &path) {
  if (root == NULL) {
    return {false, NULL};
  }

  Pair p;

  if (root->data == k) {
    p.found = true;
    p.k = root;
    return p;
  }

  path.push_back(root->data);
  if (root->data < k) {
    p = findInBST(root->left, k, path);
  } else {
    p = findInBST(root->right, k, path);
  }
  if (!p.found)
    path.pop_back();
  return p;
}
int main() {
  node *root = createBTree();
  int k, steps;
  cin >> k >> steps;
  vector<int>path;
  cout << findInBST(root,k, path).found;
  return 0;
}
