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

node * levelOrderInp(){
    int d;
    cin >>d;
    if(d == -1){
        return NULL;
    }

    node * root = new node(d);
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *c = q.front();
        q.pop();

        int l ,r;
        cin >> l >> r;
        if(l != -1){
            node * left = new node(l);
            c -> left = left;
            q.push(left);
        }else{
            c->left = NULL;
        }
        if(r != -1){
            node * right = new node(r);
            c -> right = right;
            q.push(right);
        }else{
            c->right = NULL;
        }
    }

    return root;
}

void printLeaf(node *root) {
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
        return;
    }

    if(root->left) printLeaf(root->left);
    if(root->right) printLeaf(root->right);
}


int main() {
  node *root = levelOrderInp();
  printLeaf(root);
  return 0;
}
