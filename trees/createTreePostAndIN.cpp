#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};
int s = 0;
node *createTree(int *post, int *ino, int start, int end) {
  if (start > end) {
    return NULL;
  }
  int d = post[s];
  node *p = new node(d);
  s -= 1;
  int k;
  for (int j = start; j <= end; j++) {
    if (d == ino[j]) {
      k = j;
      break;
    }
  }

  p->right = createTree(post, ino, k + 1, end);
  p->left = createTree(post, ino, start, k - 1 );
  return p;
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
  int post[n], ino[n];

  for (int i = 0; i < n; i++) {
    cin >> post[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> ino[i];
  }

  s = n - 1;

  node *root = createTree(post, ino, 0, n-1);
  preOrder(root);
  return 0;
}
