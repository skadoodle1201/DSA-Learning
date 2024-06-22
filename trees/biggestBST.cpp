#include <climits>
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

int i = 0;
node *buildTree(int *pre, int *ino, int s, int e) {
  if (s > e) {
    return NULL;
  }
  int d = pre[i];
  i += 1;
  node *root = new node(d);
  int k;
  for (int j = s; j <= e; j++) {
    if (ino[j] == d) {
      k = j;
      break;
    }
  }

  root->left = buildTree(pre, ino, s, k - 1);
  root->right = buildTree(pre, ino, k + 1, e);

  return root;
}

class info {
public:
  int min;
  int max;
  bool isBST;
  int size;
  int ans;
};


info largestBST(node * root){
    if(!root){
        return {INT_MAX, INT_MIN, true, 0 ,0};
    }

    if(root->left == NULL and root->right == NULL){
        return {root->data,root->data,true,1,1};
    }

    info left = largestBST(root->left);
    info right = largestBST(root->right);
    if((left.isBST and right.isBST) and (left.max <= root->data) and (right.min > root->data)){
        info cur;
        cur.size = left.size + right.size + 1;
        cur.ans = (left.ans+ right.ans + 1);
        cur.min = min(left.min,root->data);
        cur.max = max(right.max,root->data);
        cur.isBST = true;
        return cur;
    }

    info cur;
    cur.size = left.size + right.size +1;
    cur.ans = max(left.ans, right.ans);
    cur.isBST = false;
    return cur;
}

int main() {
  int n;
  cin >> n;
  int pre[n], ino[n];
  for (int i = 0; i < n; i++) {
    cin >> pre[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ino[i];
  }
  node *root = buildTree(pre, ino, 0, n - 1);
  info ans = largestBST(root);
  cout << ans.ans;

  return 0;
}
