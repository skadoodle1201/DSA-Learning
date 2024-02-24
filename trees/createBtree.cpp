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

int countNodes(node *root) {
  if (!root) {
    return 0;
  }

  return 1 + countNodes(root->left) + countNodes(root->right);
}

int heightOfTree(node *root) {
  if (!root) {
    return 0;
  }

  return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

int diameterOfTree(node *root) {
  if (!root) {
    return 0;
  }

  int option1 = heightOfTree(root->left) + heightOfTree(root->right);

  int option2 = diameterOfTree(root->left);
  int option3 = diameterOfTree(root->right);

  return max(option1, max(option2, option3));
}

class Pair {
public:
  int height;
  int diameter;
  Pair() { height = diameter = 0; }
};

Pair fastDiameter(node *root) {
  if (!root) {
    Pair p;
    return p;
  }

  Pair leftP = fastDiameter(root->left);
  Pair rightP = fastDiameter(root->right);

  Pair p;
  p.height = max(leftP.height, rightP.height) + 1;
  int option1 = leftP.height + rightP.height;
  int option2 = leftP.diameter;
  int option3 = rightP.diameter;

  p.diameter = max(option1, max(option2, option3));

  return p;
}

node *searchInTree(node *root, int Value) {
  if (!root)
    return NULL;

  if (root->data == Value)
    return root;
  node *ans = searchInTree(root->left, Value);
  if (ans)
    return ans;
  return searchInTree(root->right, Value);
}

void mirrorTree(node *root) {
  if (!root) {
    return;
  }
  swap(root->left, root->right);
  mirrorTree(root->left);
  mirrorTree(root->right);
}

int main() {
  node *root = createBTree();
  cout << "PREORDER :: \n";
  preOder(root);
  cout << endl;
  cout << "INORDER :: \n";
  inOrder(root);
  cout << endl;
  cout << "POSTORDER :: \n";
  postOrder(root);
  cout << endl;

  cout << "NUMBER OF NODES " << countNodes(root) << endl;
  cout << "HEIGHT OF TREE " << heightOfTree(root) << endl;
  cout << "DIAMETER OF TREE " << diameterOfTree(root) << endl;

  Pair P = fastDiameter(root);
  cout << "Fast Height :: " << P.height << endl;
  cout << "Fast Diameter :: " << P.diameter << endl;

  int valueToSearch;
  cin >> valueToSearch;
  node *ans = searchInTree(root, valueToSearch);
  if (ans)
    cout << "Found";
  else
    cout << "Not Found";
  cout << endl;

  mirrorTree(root);

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
