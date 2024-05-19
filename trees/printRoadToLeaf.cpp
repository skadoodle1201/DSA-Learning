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

void printPath(node *root, vector<int> &path, int target, int sum) {
  if (target == sum) {
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << " ";
    }
  }

  if (!root) {
    return;
  }

  path.push_back(root->data);

  if (root->left and root->left->data) {
    if ((root->left->data + sum) <= target) {
      printPath(root->left, path, target, sum + (root->data));
    }
  }

  if (root->right and root->right->data) {
    if ((root->right->data + sum) <= target) {
      printPath(root->right, path, target, sum + (root->data));
    }
  }
  path.pop_back();
}

int main() {
  node *root = build("true");
  int target;
  cin >> target;
  vector<int> p;
  printPath(root, p, target, 0);
  return 0;
}
