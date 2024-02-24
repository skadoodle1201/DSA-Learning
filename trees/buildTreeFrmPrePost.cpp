
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

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
int i = 0;

node *buildTree(int s, int e) {
  if (s > e) {
    return NULL;
  }
  int d = pre[i];
  i += 1;
  node *root = new node(d);
  int k;
  for (int j = s; j <= e; j++) {
    if (in[j] == d) {
      k = j;
      break;
    }
  }

  root->left = buildTree(s, k - 1);
  root->right = buildTree(k + 1, e);

  return root;
}
int main() {
  node *root = buildTree(0, 8);
  cout << "PREORDER :: \n";
  preOder(root);
  cout << endl;
  cout << "INORDER :: \n";
  inOrder(root);
  cout << endl;
  cout << "POSTORDER :: \n";
  postOrder(root);
  cout << endl;

  return 0;
}
