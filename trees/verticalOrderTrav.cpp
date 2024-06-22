#include <iostream>
#include <map>
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
  int value;
  cin >> value;

  if (value == -1) {
    return NULL;
  }
  node *root = NULL;

  while (value != -1) {
    root = insertNode(root, value);
    cin >> value;
  }
  return root;
}

void preOder(node *root, map<int, vector<int>> &m, int hd) {
  if (root == NULL) {
    return;
  }
  // cout << root->data << " ";
  m[hd].push_back(root->data);
  preOder(root->left, m, hd - 1);
  preOder(root->right, m, hd + 1);
}

void printVertical(node *root) {
  map<int, vector<int>> m;
  int hd = 0;
  preOder(root, m, hd);

  map<int, vector<int>>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    for (int i = 0; i < it->second.size(); ++i)
      cout << it->second[i] << " ";
    cout << endl;
  }
}
int main() {
  int levels;
  cin >> levels;
  node *root = createBTree();
  printVertical(root);
  return 0;
}

node *levelOrderTraversalInp() {
    queue<node *> q;
    node *root = NULL;
    int data;
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
