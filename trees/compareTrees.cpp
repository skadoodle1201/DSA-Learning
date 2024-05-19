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
  node *root = new node(value);
  string l, r;

  cin >> l;
  if (l == "true")
    root->left = createBTree();
  else
    root->left = NULL;

  cin >> r;
  if (r == "true")
    root->right = createBTree();
  else
    root->right = NULL;

  return root;
}

bool check(node *t1, node *t2) {
  if (t1 == NULL and t2 == NULL) {
    return true;
  }

  if (t1 and t2) {
    bool left = check(t1->left, t2->left);
    bool right = check(t1->right, t2->right);
    return (left and right);
  }
  return false;
}

void preOder(node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preOder(root->left);
  preOder(root->right);
}

int main() {
  node *r1 = createBTree();
  node *r2 = createBTree();
  preOder(r1);
  cout << endl;
  preOder(r2);

  bool checkVal = check(r1, r2);
  cout << (checkVal ? "true" : "false");
  return 0;
}
