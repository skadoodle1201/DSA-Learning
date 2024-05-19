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

node *createTree() {
  int val;
  cin >> val;

  if (val == -1) {
    return NULL;
  }
  node *root = new node(val);
  queue<node *> q;
  q.push(root);

  while (!q.empty()) {
    node *t = q.front();
    q.pop();

    int l, r;
    cin >> l >> r;
    if (l != -1) {
      t->left = new node(l);
      q.push(t->left);
    } else {
      t->left = NULL;
    }
    if (r != -1) {
      t->right = new node(r);
      q.push(t->right);
    } else {
      t->right = NULL;
    }
  }
  return root;
}
void printRight(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  bool flag = false;

  while (!q.empty()) {
    node *n = q.front();
    q.pop();
    if(!q.empty() and q.front() == NULL){
        flag = true;
    }
    if (n == NULL) {
      flag = false;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      if (flag) {
        cout << n->data;
        flag = false;
      }
      if (n->left) {
        q.push(n->left);
      }
      if (n->right) {
        q.push(n->right);
      }
    }
  }
}
void printLeft(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  bool flag = true;

  while (!q.empty()) {
    node *n = q.front();
    q.pop();

    if (n == NULL) {
      cout << " ";
      flag = true;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      if (flag) {
        cout << n->data;
        flag = false;
      }
      if (n->left) {
        q.push(n->left);
      }
      if (n->right) {
        q.push(n->right);
      }
    }
  }
}
int main() {
  node *root = createTree();
  printRight(root);
  return 0;
}
