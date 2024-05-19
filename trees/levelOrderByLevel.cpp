#include <iostream>
#include <queue>
#include <vector>
// #include <>
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

node *build(string s) {
  if (s == "true") {
    int d;
    cin >> d;
    node *root = new node(d);
    string l;
    cin >> l;
    if (l == "true") {
      root->left = build(l);
    }
    string r;
    cin >> r;
    if (r == "true") {
      root->right = build(r);
    }
    return root;
  }
  return NULL;
}

void levelOrder(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  int level = 1;
  while (!q.empty()) {
    node *t = q.front();
    q.pop();
    if (t == NULL) {
      cout << endl;
      level ++ ;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << t->data << " ";
      if (level % 2 == 0) {
          if (t->right) {
            q.push(t->right);
          }
          if (t->left) {
            q.push(t->left);
          }
      } else {
          if (t->left) {
            q.push(t->left);
          }
          if (t->right) {
            q.push(t->right);
          }
      }
    }
  }
}
int main() {
  node *root = build("true");
  levelOrder(root);
  return 0;
}
