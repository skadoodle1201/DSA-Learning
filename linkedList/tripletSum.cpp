#include <cmath>
#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *next;
  node(int d) {
    data = d;
    next = NULL;
  }
};

void addAtEnd(int d, node *&head, node *&tail) {
  node *nh = new node(d);
  if (!head) {
    head = tail = nh;
  } else {
    tail->next = nh;
    tail = nh;
  }
}

int main() {
  int n;
  cin >> n;
  node *h1, *t1, *h2, *h3, *t2, *t3;
  h1 = h2 = h3 = t1 = t2 = t3 = NULL;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    addAtEnd(d, h1, t1);
  }

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    addAtEnd(d, h2, t2);
  }

  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    addAtEnd(d, h3, t3);
  }
  int target;
  cin >> target;

  node *tempH2 = h2, *tempH3 = h3;

  while (h1) {
    while (h2) {
      while (h3) {
        if (h1->data + h2->data + h3->data == target) {
          cout << h1->data << " " << h2->data << " " << h3->data;
          return 0;
        }
        h3 = h3->next;
      }
      h2 = h2->next;
      h3 = tempH3;
    }
    h2 = tempH2;
    h1 = h1->next;
  }

  return 0;
}
