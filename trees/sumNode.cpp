#include <iostream>
#include <queue>
#include <vector>
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

void removeLeaves(node * &root){
    if(root->left == NULL && root->right == NULL){
        root = NULL;
    }
    if(root->left) removeLeaves(root->left);
    if(root->right) removeLeaves(root->right);
}

void preOrder(node *root) {
  if (!root) {
    return;
  }
  if(root->left){
      cout<< root->left->data << " => ";
  }else{
      cout<<"END => ";
  }
  cout<<root->data << " <= ";
  if(root->right){
      cout<< root->right->data << endl;
  }else{
      cout<<"END" << endl;
  }
  preOrder(root->left);
  preOrder(root->right);
}

int sumNode(node *root) {
  if (root == NULL) {
    return 0;
  }

  return (root->data + sumNode(root->left) + sumNode(root->right));
}

int main() {
  node *root = build("true");
  node *temp = root;
  removeLeaves(temp);
  preOrder(root);

  return 0;
}
