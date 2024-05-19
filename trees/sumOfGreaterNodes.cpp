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

node *construct(int *sa, int lo, int hi) {
  if (lo > hi) {
    return NULL;
  }
  int mid = (hi + lo) / 2;
  node *rv = new node(sa[mid]);
  rv->left = construct(sa, lo, mid - 1);
  rv->right = construct(sa, mid + 1, hi);
  return rv;
}

void sumNodes(node *root, int &sum) {
  if (root == NULL) {
    return;
  }
  sumNodes(root->right, sum);
  sum = sum + root->data;
  root->data = sum;
  sumNodes(root->left, sum);
}

void modifyBST(node *root) {
  int sum = 0;
  sumNodes(root, sum);
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
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  node *root = construct(arr, 0, n - 1);
  modifyBST(root);
  preOrder(root);
  return 0;
}
